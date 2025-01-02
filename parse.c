/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:27:17 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/03 00:01:15 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	type_arg(t_token *token, int separator)
{
	if (ft_strcmp(token->str, "") == 0)
		token->type = EMPTY;
	else if (ft_strcmp(token->str, ">") == 0 && separator == 0)
		token->type = TRUNC;
	else if (ft_strcmp(token->str, ">>") == 0 && separator == 0)
		token->type = APPEND;
	else if (ft_strcmp(token->str, "<") == 0 && separator == 0)
		token->type = INPUT;
	else if (ft_strcmp(token->str, "|") == 0 && separator == 0)
		token->type = PIPE;
	else if (ft_strcmp(token->str, ";") == 0 && separator == 0)
		token->type = END;
	else if (token->prev == NULL || token->prev->type >= TRUNC)
		token->type = CMD;
	else
		token->type = ARG;
}

t_token	*get_tokens(char *line)
{
	t_token	*prev;
	t_token	*next;
	int		i;
	int		sep;

	prev = NULL;
	next = NULL;
	i = 0;
	ft_skip_space(line, &i);//スペースを飛ばす
	while (line[i])
	{
		sep = ignore_sep(line, i);//無効なセパレーターをチェック(\かつセパレーター)
		next = next_token(line, &i);//トークンをnextに入れる(シングル・ダブルクオテーションの対応・\の対応)
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		type_arg(next, sep);//トークンにコマンドのタイプの割り振り
		ft_skip_space(line, &i);//スペースを飛ばす
	}
	if (next)
		next->next = NULL;//最後のトークンにNULL設定
	while (next && next->prev)
		next = next->prev;//next をリストの先頭に戻す
	return (next);
}
//parse fixed 
void	parse(t_mini *mini, char *line)
{
	// char	*line;
	t_token	*token;
	signal(SIGINT, &sig_int);//Ctrl+C　（プロンプトの新しい行の作成）
	signal(SIGQUIT, &sig_quit);//Ctrl＋/ （何もしない）の登録
	// printf("%s\n", line);
	// ft_putstr_fd("\033[0;36m\033[1mminishell ▸ \033[0m", STDERR);
	if (mini->exit == 1)
		ft_putendl_fd("exit", STDERR);
	if (g_sig.sigint == 1)
		mini->ret = g_sig.exit_status;
	if (quote_check(mini, &line))//クオーテーションのチェック(" or ' で囲われているか)
		return ;
	line = space_line(line);//セパレーターに空白を追加
	if (line && line[0] == '$')
		line[0] = (char)(-line[0]);//$の際に符号変換、変数の値を取得するためのフラグ
	mini->start = get_tokens(line);//lineの文字をトークンにする・トークンにタイプを付与
	// ft_memdel(line);
	squish_args(mini);//トークンの位置調整
	token = mini->start;
	while (token)
	{
		if (is_type(token, ARG))
			type_arg(token, 0);//トークンにコマンドのタイプの割り振り
		token = token->next;
	}
}
