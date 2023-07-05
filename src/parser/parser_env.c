/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:14:18 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/07/05 19:43:28 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_env_var(char *env)
{
	int		i;
	char	*var;

	i = 0;
	while (env[i] != '=')
		i++;
	var = malloc(sizeof(char) * (i + 1));
	if (var == NULL)
	{
		ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
		return (NULL);
	}
	i = -1;
	while (env[++i] != '=')
		var[i] = env[i];
	var[i] = '\0';
	return (var);
}

char	*ft_get_env(char *input, t_data *data)
{
	int		c;
	char	*env;
	char	**value;
	char	*tmp;

	c = 0;
    //ft_printf("%s\n", input);
	while (data->envp[c])
	{
		env = ft_get_env_var(data->envp[c]);
		if (ft_strcmp(env, input) == 0)
		{
			free(env);
			value = ft_split(data->envp[c], '=');
			tmp = ft_strdup(value[1]);
			ft_free_str_array(value);
			return (tmp);
		}
		free(env);
		c++;
	}
	return (NULL);
}

void	ft_replace_env(t_token *token, int s, int e, char *value)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (value == NULL)
		value = "";
	new = malloc(sizeof(char) * (ft_strlen(token->string)
				- (e - s) + ft_strlen(value) + 1));
	if (!new)
		return ;
	while (i < s)
		new[j++] = token->string[i++];
	i = 0;
	while (value[i])
		new[j++] = value[i++];
	i = e;
	while (token->string[i])
		new[j++] = token->string[i++];
	new[j] = '\0';
	free(token->string);
	token->string = new;
}

int	ft_replace_var(t_token *token, t_data *data)
{
	int		s;
	int		e;
	char	*env;
	char	*value;

	s = 0;
	e = 0;
    while (token->string[e] && token->string[e] != '$')
        e++;
    if (token->string[e] == '$' && token->string[e + 1])
    {
        e++;
        s = e;
        while (token->string[e] && (ft_isalnum(token->string[e])
            || token->string[e] == '_'))
                e++;
        if (ft_is_inter(token->string))
            env = ft_substr(token->string, s, 1);
        else
            env = ft_substr(token->string, s, e - s);
        if (ft_strcmp(env, "?") == 0)
            value = ft_itoa(data->id_last_proc);
        else
            value = ft_get_env(env, data);
        ft_replace_env(token, s - 1, s + ft_strlen(env), value);
        free(env);
        free(value);
		return (1);
    }
	return (0);
}