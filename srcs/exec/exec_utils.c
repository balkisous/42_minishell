/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:17:26 by ddecourt          #+#    #+#             */
/*   Updated: 2021/12/01 13:50:35 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**get_cmd_path(char **envp)
{
	int		i;
	int		j;
	char	*path;

	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH", 4) != 0)
			path = ft_strnstr(envp[i], "PATH", 4);
	}
	return (ft_split(path + 5, ':'));
}

char *get_right_path(t_parsing *params, char **envp)
{
	char *path;
	char **path_array;
	int i;

	i = 0;
	path_array = get_cmd_path(envp);
	while (path_array[++i])
	{
		path = ft_strjoin(path_array[i], "/");
		path = ft_strjoin(path, params->tabs[0]);
		if (access(path, F_OK) == 0)
			return (path);
	}
	ft_putstr_fd(params->tabs[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

int open_file(t_parsing *params, char *file)
{
	int fd;
	if (params->type == 1 || params->type == 4)
		return(fd = open(file, O_RDONLY));
	if (params->type == 2)
		return(fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0664));
	if (params->type == 3)
		return(fd = open(file, O_RDWR | O_APPEND | O_CREAT, 0664));	
	else
		return(0);
}

void	ft_free_params(t_parsing *params)
{
	while (params->next)
	{
		ft_free_file(params->file);				//here free file liste
		free_tabs(params->tabs);				//here free params->tabs
		free(params);
		params = params->next;
	}
}

void	ft_free_file(t_file *file)
{
	while (file->next)
	{
		free(file->name);
		free(file);
		file = file->next;
	}
}