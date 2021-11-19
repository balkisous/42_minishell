/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddecourt <ddecourt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:47:40 by ddecourt          #+#    #+#             */
/*   Updated: 2021/11/19 01:11:55 by ddecourt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_n(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '-' && arg[i])
	{
		i++;
		while (arg[i] == 'n')
			i++;
		if (arg[i] != 'n' && arg[i])
			return (0);
	}
	return (1);
}

int	ft_echo(int fd, char **arg)
{
	int size;
	int n;
	
	size = 0;
	while (arg[size])
		size++;
	if (size == 1)
		ft_putchar_fd('\n', fd);
	if (size > 1)
		n = check_n(arg[1]);
	if (n == 0)
	{
		ft_putstr_fd(arg[1], fd);
		ft_putchar_fd('\n', fd);
	}
	if (n == 1)
		ft_putstr_fd(arg[1], fd);
	return (0);
}