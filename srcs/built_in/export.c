/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:55:05 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/16 17:46:36 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_parse_export(char *tab, char **key, char **value)
{
	int		dollar;
	int		i;

	i = 0;
	dollar = 0;
	if (tab[i] == '$')
		dollar = 1;
	while (tab[i] != '=')
		i++;
	if (dollar == 1)
		i -= 1;
	*key = ft_strndup(tab, i);
	*value = ft_strchr(tab, '=');
	return (0);
}

int	ft_is_in_env(char *key, char **envp)
{
	int i;
	int size;
	
	i = -1;
	size = ft_strlen(key);
	while (envp[++i])
	{
		if (ft_strncmp(key, envp[i], size) == 0)
			return (1);
	}
	return (0);
}

void	ft_print_tab(char **tab)
{
	int i = -1;
	int j = -1;

	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			ft_putchar(tab[i][j]);
	}
}

char	**set_in_env(char *line, char **env)
{
	
	int i;
	int size;
	char **tmp;
	
	size = 0;
	i = -1;
	while (env[++i])
		size++;
	printf("size = %d\n", size);
	//env[size] = ft_strlcat(env[size], line, )
	tmp = malloc(sizeof(char *) * (size + 2));
	i = -1;
	while (++i < size)
	{
		tmp[i] = env[i];
		tmp[i] = ft_strjoin(tmp[i], "\n");
		//free(env[i]);
	}
	tmp[i] = ft_strdup(line);
	tmp[i] = ft_strjoin(tmp[i], "\n");
	printf("valeur de i = [%i]\n", i);
	printf("line in tmp = [%s]\n", tmp[i]);
	tmp[++i] = NULL;
	ft_print_tab(tmp);
	return (tmp);
}

int ft_export(int fd, char **tabs, char **env)
{
	char	*key;
	char	*value;
	char	**tmp;
	int		is_in_env;
	
	key = NULL;
	value = NULL;
	is_in_env = 0;
	if (tabs[2])
		return (0);
	ft_parse_export(tabs[1], &key, &value);
	//printf("%s\n", key);
	//printf("%s\n", value);
	is_in_env = ft_is_in_env(key, env);
	//printf("is_in_key value : %d\n", is_in_env);
	//printf("line value : %s\n", tabs[1]);
	if (!ft_is_in_env(key, env))
	{
		tmp = set_in_env(tabs[1], &env);
	}
	else
		return (0);
	
	
	(void) fd;
	/*int i;
	int j;
	int size;

	i = 1;
	j = -1;
	size = ft_strlen(tabs[i]);
	if (tabs[i][++j] == '$')
		return(0);
	while (tabs[i][j] != '=')
		j++;
	if ()*/
	return (0);
}