/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:36:31 by tprysiaz          #+#    #+#             */
/*   Updated: 2016/12/15 17:20:24 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fil.h"

int			ft_dot_hash(char *str, int i)
{
	int		b;
	int		c;
	int		e;

	b = 0;
	c = 0;
	e = 0;
	if ((str[i + 4] == '\n' && str[i + 9] == '\n' && str[i + 14] == '\n' &&
		str[i + 19] == '\n') && (str[i + 20] == '\n' || str[i + 20] == '\0'))
	{
		while (c < 5)
		{
			str[i] == '.' ? b++ : 0;
			str[i] == '#' ? e++ : 0;
			str[i] == '\n' ? c++ : 0;
			if (str[i] == '\0')
				break ;
			i++;
		}
	}
	if (b == 12 && e == 4)
		return (0);
	return (1);
}

void		ft_valid_file(char *str, int len)
{
	int	i;

	i = 0;
	while (i != len - 1)
	{
		if (ft_dot_hash(str, i) == 0)
		{
			if ((i + 21) < len)
				i = i + 21;
			else if ((i + 21) > len)
				i = i + 19;
		}
		else
		{
			write(1, "error\n", 6);
			free(str);
			break ;
		}
	}
	if (i == len - 1)
		ft_array(str, len);
}
