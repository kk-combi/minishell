/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:28:30 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/03 00:01:54 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// signal
// exec cd / echo current /
//
// code explan
// tokyo plannning

t_sig	g_sig;

void	minishell(t_mini *mini)
{
	t_token *token;
	int status;

	token = next_run(mini->start, NOSKIP);
	if (is_types(mini->start, "TAI"))
		token = mini->start->next;
	while (mini->exit == 0 && token)
	{
		mini->charge = 1;
		mini->parent = 1;
		mini->last = 1;
		redir_and_exec(mini, token);
		reset_std(mini);
		close_fds(mini);
		reset_fds(mini);
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (mini->last == 0)
			mini->ret = status;
		if (mini->parent == 0)
		{
			free_token(mini->start);
			exit(mini->ret);
		}
		mini->no_exec = 0;
		token = next_run(token, SKIP);
	}
}

int	main(int argc, char **argv, char **ev)
{
	t_mini	mini;
	char	*line;

	(void)argc;
	(void)argv;
	//minishell の初期値を設定
	mini.exit = 0;//exit 1 EXIT実行　0 minishell継続
	mini.ret = 0;//関数の戻り値を格納
	mini.no_exec = 0;//関数を実行できたかどうか 0 未実行 1 実行済み
	mini.fdin = -1;//ファイルディスプリクタ入力
	mini.fdout = -1;//ファイルディスプリクタ出力
	mini.pipin = -1;//パイプの入力
	mini.pipout = -1;//パイプの出力
	mini.pid = -1;//プロセスID
	//環境変数の取得
	env_init(&mini, ev);
	//SHELL LEVEL (シェルの深さを表す環境変数の再設定)
	shell_level(mini.env);
	while (1)
	{
		//コマンドプロンプトの表示
		line = readline("> ");
		//line がない・EXITがある場合にコマンド終了
		if (line == NULL || ft_strcmp(line, "exit") == 1)
			return (free(line), 0);
		//signal関数のための初期値設定
		g_sig.sigint = 0;
		g_sig.sigquit = 0;
		g_sig.pid = 0;
		g_sig.exit_status = 0;
		//line をトークンの構造体に入れ替え
		parse(&mini, line);
		if (mini.start != NULL && check_line(&mini, mini.start))
			minishell(&mini);
		add_history(line);
		free_token(mini.start);
	}
	free_env(mini.env);
	free_env(mini.secret_env);
	return (mini.ret);
}

// 1. unset variable
// 2. norminette
// 3. pippe checking
// 4. ctrl + C
// 5. history
