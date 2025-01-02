/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:57:48 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/02 23:59:44 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//here is changing 

t_token	*next_token(char *line, int *i)
{
	t_token	*token;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	token = ft_calloc(1, sizeof(t_token));
	token->str = ft_calloc(1, sizeof(char) * next_alloc(line, i));
	if (!token || !token->str)
		return (NULL);
	while (line[*i] && (line[*i] != ' ' || c != ' '))//line が終わるまで　かつ、スペース以外ではなく、c != ' '(c が ' または " の場合)
	{
		if (c == ' ' && (line[*i] == '\'' || line[*i] == '\"'))//シングル・ダブルクオテーションであれば、Cに文字を入れる
			c = line[(*i)++];
		else if (c != ' ' && line[*i] == c)//シングル・ダブルクオテーションであれば、Cをリセット＋次の文字へ移動
		{
			c = ' ';
			(*i)++;
		}
		else if (line[*i] == '\\' && (*i)++)//現在の文字がエスケープ文字 \ の場合、次の文字を無条件にトークンに追加
			token->str[j++] = line[(*i)++];
		else
			token->str[j++] = line[(*i)++];//通常の文字をトークンに追加
	}
	token->str[j] = '\0';
	return (token);
}

static int	is_last_valid_arg(t_token *token)
{
	t_token	*prev;

	if (!token || is_type(token, CMD) || is_type(token, ARG))//CMD ARGの対応が付与されていた際にTRUE
	{
		prev = prev_sep(token, NOSKIP);//NOSKIP　最初のtokenをスキップしない・セパレーター手前までtokenを移動したものをprevに格納
		if (!prev || is_type(prev, END) || is_type(prev, PIPE))
			return (1);//END 最後のコマンド　or PIPE パイプであれば、1
		return (0);
	}
	else
		return (0);
}

void	squish_args2(t_mini *mini, t_token *token, t_token *prev)
{
	while (prev && is_last_valid_arg(prev) == 0)//END 最後のコマンド　or PIPE パイプであれば、一つ後ろへ移動
		prev = prev->prev;
	if (token->prev != NULL)//トークンの位置調整　次のトークン→前の次のトークン
		token->prev->next = token->next;
	if (token->next != NULL)//トークンの位置調整　前のトークン→次の前のトークン
		token->next->prev = token->prev;
	token->prev = prev;
	if (prev != NULL)//prevがあれば、tokenをprevの直後に挿入
	{
		token->next = prev->next;
		if (prev->next != NULL)
			prev->next->prev = token;
		prev->next = token;
	}
	else//prev がない場合には、リストの最初に挿入
	{
		token->next = mini->start;
		if (mini->start != NULL)
			mini->start->prev = token;
		mini->start = token;
	}
}

void	squish_args(t_mini *mini)
{
	t_token	*token;
	t_token	*prev;

	token = mini->start;
	while (token)
	{
		prev = prev_sep(token, NOSKIP);//NOSKIP　最初のtokenをスキップしない・セパレーター手前までtokenを移動したものをprevに格納
		if (is_type(token, ARG) && is_types(prev, "TAI"))//tokenがargであり、T: TRUNC , A: APPEND, I: INSERT
														//の場合は、次の処理を実行
			squish_args2(mini, token, prev);//トークンの位置を調整
		token = token->next;
	}
}
