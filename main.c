/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:18:33 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/16 14:47:01 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"
#define BUF_SIZE 1

char		*ft_read(char *ag)
{
	int		i;
	int		fd;
	int		res;
	char	*str;
	char	buf[BUF_SIZE + 1];

	i = 0;
	fd = open(ag, O_RDONLY);
	str = (char*)malloc(545);
	while ((res = read(fd, buf, BUF_SIZE)) > 0)
	{
		str[i] = buf[0];
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

int			main(int ac, char **ag)
{
	int		i;
	char	*str;

	i = 0;
	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	str = ft_read(ag[1]);
	while (str[i])
		i++;
	if (i != 20 && i != 41 && i != 62 && i != 83 && i != 104 && i != 125 &&
		i != 146 && i != 167 && i != 188 && i != 209 && i != 230 && i != 251 &&
		i != 272 && i != 293 && i != 314 && i != 335 && i != 356 && i != 377 &&
		i != 398 && i != 419 && i != 440 && i != 461 && i != 482 && i != 503 &&
		i != 524 && i != 545)
	{
		write(1, "error\n", 6);
		free(str);
	}
	else
		ft_valid_file(str, i);
	return (0);
}
