/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwitrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 21:36:51 by gwitrand          #+#    #+#             */
/*   Updated: 2016/09/15 21:36:53 by gwitrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_readwrite(int ret, int fd, int n_option, char *buf)
{
	int		i;

	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
		buf[ret] = '\0';
	i = ft_strlen(buf);
	if (i > n_option)
	{
		n_option = i - n_option;
		while (buf[n_option])
		{
			write(1, &buf[n_option], 1);
			n_option++;
		}
	}
	else
	{
		i = 0;
		while (buf[i])
		{
			write(1, &buf[i], 1);
			i++;
		}
	}
	close(fd);
}

int		main(int argc, char **argv)
{
	int		i;
	int		n_option;

	i = 2;
	n_option = 0;
	if (argc < 3)
		return (-1);
	n_option = ft_nb(argv[1]);
	if (argc == 3)
	{
		while (i < argc)
		{
			ft_tail(argv[i], n_option);
			i++;
		}
		return (0);
	}
	else
	{
		while (i < argc)
		{
			ft_tail_2(argv[i], n_option);
			i++;
		}
	}
}
