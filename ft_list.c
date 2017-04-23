/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 18:06:58 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/23 15:05:18 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

t_			*ft_list2(t_ *lst, char **str)
{
	int		i;
	int		j;
	int		n;

	n = -1;
	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '#' && ++n <= 4)
			{
				lst->x[n] = j - lst->x[0];
				lst->y[n] = i - lst->y[0];
			}
		}
	}
	return (lst);
}

void		ft_list(char ***str)
{
	t_		*lst;
	t_		*lst2;
	int		i;

	lst = (t_*)malloc(sizeof(t_));
	lst2 = lst;
	i = -1;
	while (str[++i])
	{
		lst = ft_list2(lst, str[i]);
		lst->x[0] = 0;
		lst->y[0] = 0;
		if (str[i + 1])
		{
			lst->n = (t_*)malloc(sizeof(t_));
			lst = lst->n;
		}
	}
	lst->n = 0;
	free(str);
	ft_next(lst2);
}
