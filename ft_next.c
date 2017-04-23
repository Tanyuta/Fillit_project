/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:06:34 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/23 15:05:23 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

char		**ft_map(char **str, int l)
{
	int		i;
	int		j;

	i = -1;
	if (str)
		free(str);
	str = (char**)malloc(sizeof(char*) * l);
	while (++i < l - 1)
	{
		str[i] = (char*)malloc(l);
		j = -1;
		while (++j < l - 1)
			str[i][j] = '.';
		str[i][j] = '\0';
	}
	str[i] = 0;
	return (str);
}

void		ft_replace(char **str, t_ *lst, int i, int j)
{
	if (str[i + lst->y[0]][j + lst->x[0]] == lst->c &&
		str[i + lst->y[1]][j + lst->x[1]] == lst->c &&
		str[i + lst->y[2]][j + lst->x[2]] == lst->c &&
		str[i + lst->y[3]][j + lst->x[3]] == lst->c)
	{
		str[i + lst->y[0]][j + lst->x[0]] = '.';
		str[i + lst->y[1]][j + lst->x[1]] = '.';
		str[i + lst->y[2]][j + lst->x[2]] = '.';
		str[i + lst->y[3]][j + lst->x[3]] = '.';
	}
	else
	{
		str[i + lst->y[0]][j + lst->x[0]] = lst->c;
		str[i + lst->y[1]][j + lst->x[1]] = lst->c;
		str[i + lst->y[2]][j + lst->x[2]] = lst->c;
		str[i + lst->y[3]][j + lst->x[3]] = lst->c;
	}
}

int			ft_repeat(char **str, t_ *lst, int l)
{
	int		i;
	int		j;

	i = -1;
	if (!(lst))
		return (1);
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (LL1 && LL2 && LL3 && LL4 && LL5 && LL6 && LL7 && LL8)
			{
				if (XY1 && XY2 && XY3 && XY4 && XY5 && XY6 && XY7 && XY8)
				{
					ft_replace(str, lst, i, j);
					if (ft_repeat(str, lst->n, l))
						return (1);
					else
						ft_replace(str, lst, i, j);
				}
			}
		}
	}
	return (0);
}

void		ft_fillit(t_ *lst)
{
	char	**str;
	int		i;
	int		l;
	int		j;

	i = -1;
	l = 3;
	str = 0;
	str = ft_map(str, l);
	while (!(ft_repeat(str, lst, l)))
	{
		l++;
		str = ft_map(str, l);
	}
	free(lst);
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			write(1, &str[i][j], 1);
		write(1, "\n", 1);
	}
}

void		ft_next(t_ *lst2)
{
	char	c;
	t_		*lst;

	c = 65;
	lst = lst2;
	while (lst2)
	{
		lst2->c = c;
		c++;
		lst2 = lst2->n;
	}
	ft_fillit(lst);
}
