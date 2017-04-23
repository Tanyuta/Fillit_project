/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:06:44 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/23 15:05:13 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int			ft_valid_figure(char **tmp)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (tmp[i][j] == '#')
			{
				if (tmp[i][j + 1] == '#')
					count++;
				if (i < 3 && tmp[i + 1][j] == '#')
					count++;
			}
		}
	}
	if (count == 3 || count == 4)
		return (0);
	return (1);
}

void		ft_array_3(char ***tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (ft_valid_figure(tmp[i]))
		{
			write(1, "error\n", 6);
			free(tmp);
			break ;
		}
		i++;
	}
	if (tmp[i] == 0)
		ft_list(tmp);
}

char		**ft_array_2(char *str, int i)
{
	int		x;
	int		y;
	char	**s;

	x = 0;
	y = 0;
	s = (char**)malloc(sizeof(char*) * 5);
	while (x < 4)
	{
		s[x] = (char*)malloc(sizeof(char) * 5);
		while (str[i] != '\n')
		{
			s[x][y] = str[i];
			i++;
			y++;
		}
		s[x][y] = '\0';
		y = 0;
		i++;
		x++;
	}
	s[x] = 0;
	return (s);
}

void		ft_array(char *str, int len)
{
	int		i;
	int		j;
	char	***tmp;

	i = 0;
	j = 0;
	len = len < 440 ? len / 20 + 1 : len / 20;
	tmp = (char***)malloc(sizeof(char**) * len);
	while (i < len - 1)
	{
		tmp[i] = ft_array_2(str, j);
		i++;
		j = j + 21;
	}
	tmp[i] = 0;
	ft_array_3(tmp);
}
