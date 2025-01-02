/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoumakobayashi <shoumakobayashi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:02:48 by shoumakobay       #+#    #+#             */
/*   Updated: 2025/01/02 16:22:36 by shoumakobay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_env_name(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i] && src[i] != '=' && ft_strlen(src) < BUFF_SIZE)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_env_value(char *arg, t_env *env)
{
	char	env_name[BUFF_SIZE];
	char	*env_val;

	env_val = ft_strdup("");
	while (env && env->value)
	{
		get_env_name(env_name, env->value);
		if (ft_strcmp(arg, env_name) == 0)
		{
			ft_memdel(env_val);
			env_val = env_value(env->value);
			return (env_val);
		}
		env = env->next;
	}
	return (env_val);
}

void	shell_level(t_env *env)
{
	int		shell_level;
	char	env_name[BUFF_SIZE];
	char	*shlvl;
	char	*shell_level_value;


	shell_level_value = get_env_value("SHLVL", env);//env構造体からSHLVLの値を取得
	if (strcmp(shell_level_value, "") == 0)//取得できないならMAINに戻る（ない場合のエラーはない）
		return ;
	shell_level = get_lvl(shell_level_value) + 1;//今のSHELL LEVELを＋１する
	ft_memdel(shell_level_value);//shell_level_valueのメモリーをフリー
	while (env && env->next)
	{
		get_env_name(env_name, env->value);//env->value から構造体の名前をenv_nameに格納
		if (strcmp("SHLVL", env_name) == 0)//env_nameがSHLVLと一致する場合にSHLVLの更新
		{
			ft_memdel(env->value);
			shlvl = ft_itoa(shell_level);
			env->value = ft_strjoin("SHLVL=", shlvl);
			ft_memdel(shlvl);
			return ;
		}
		env = env->next;
	}
}
