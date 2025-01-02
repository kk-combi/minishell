/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:40:29 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/02 23:10:56 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ignore_sep(char *line, int i)//バックスラッシュかつセパレーター(;, |, >, >>)であれば、戻り値1 (次で処理させない) 0(処理OK)
{
	if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == ';')
		return (1);
	else if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == '|')
		return (1);
	else if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == '>')
		return (1);
	else if (line[i] && line[i] == '\\' && line[i + 1] && line[i + 1] == '>'
		&& line[i + 2] && line[i + 2] == '>')
		return (1);
	return (0);
}

int	quotes(char *line, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (line[i] && i != index)
	{
		if (i > 0 && line[i - 1] == '\\')
			;
		else if (open == 0 && line[i] == '\"')//最初にダブルクオテーションで囲われていたら
			open = 1;
		else if (open == 0 && line[i] == '\'')//最初にシングルクオテーションで囲われていたら
			open = 2;
		else if (open == 1 && line[i] == '\"')//最後にダブルクオテーションで囲われていたら
			open = 0;
		else if (open == 2 && line[i] == '\'')//最後にシングルクオテーションで囲われていたら
			open = 0;
		i++;
	}
	return (open);//0 クオテーションで最初から最後まで囲われている　1 2 最初か最後どちらかに囲われている
}

int	quote_check(t_mini *mini, char **line)
{
	if (quotes(*line, INT_MAX))
	{
		ft_memdel(*line);
		mini->ret = 2;
		mini->start = NULL;
		return (1);
	}
	return (0);
}

char	*space_line(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = space_alloc(line);
	while (new && line[i])
	{//ダブルクオテーションで囲われており、$の前には\がないと判断した場合
		if (quotes(line, i) != 2 && line[i] == '$' && i && line[i - 1] != '\\')
			new[j++] = (char)(-line[i++]);//$の値をマイナス反転
		else if (quotes(line, i) == 0 && is_sep(line, i))//クオテーションで囲われており、セパレーター(<>|;)がある場合
		{//new変数を格納する前にセパレーター(<>|;)の前に空白を入れる
			new[j++] = ' ';
			new[j++] = line[i++];
			if (quotes(line, i) == 0 && line[i] == '>')//クオテーションで囲われており、>の場合は空白を入れる前にスペースを追加
				new[j++] = line[i++];
			new[j++] = ' ';
		}
		else
			new[j++] = line[i++];
	}
	new[j] = '\0';
	ft_memdel(line);
	return (new);
}
