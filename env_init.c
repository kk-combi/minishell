/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:38:05 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/02 16:11:21 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	env_init(t_mini *mini, char **env_s)
{
	t_env	*env;
	t_env	*new;
	int		i;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (1);
	//環境変数の０番目を取得
	env->value = ft_strdup(env_s[0]);
	//envの次の値をNULLで埋める
	env->next = NULL;
	//0番目の値をmini構造体に入れる
	mini->env = env;
	//0番目の値をsecret_env構造体(変更前の値を保存する環境変数)に入れる
	mini->secret_env = env;
	i = 1;
	while (env_s && env_s[0] && env_s[i])//環境変数をenvに格納
	{
		new = ft_calloc(1, sizeof(t_env));
		if (!new)
			return (1);
		new->value = ft_strdup(env_s[i]);
		new->next = NULL;
		env->next = new;
		i++;
	}
	return (0);
}
