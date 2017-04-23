/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprysiaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:42:45 by tprysiaz          #+#    #+#             */
/*   Updated: 2017/04/23 15:05:08 by tprysiaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIL_H
# define FIL_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define LL1 i + lst->y[0] < l - 1
# define LL2 i + lst->y[1] < l - 1
# define LL3 i + lst->y[2] < l - 1
# define LL4 i + lst->y[3] < l - 1
# define LL5 j + lst->x[0] < l - 1
# define LL6 j + lst->x[1] < l - 1
# define LL7 j + lst->x[2] < l - 1
# define LL8 j + lst->x[3] < l - 1

# define XY1 i + lst->y[0] >= 0 && i + lst->y[1] >= 0
# define XY2 i + lst->y[2] >= 0 && i + lst->y[3] >= 0
# define XY3 j + lst->x[0] >= 0 && j + lst->x[1] >= 0
# define XY4 j + lst->x[2] >= 0 && j + lst->x[3] >= 0
# define XY5 str[i + lst->y[0]][j + lst->x[0]] == '.'
# define XY6 str[i + lst->y[1]][j + lst->x[1]] == '.'
# define XY7 str[i + lst->y[2]][j + lst->x[2]] == '.'
# define XY8 str[i + lst->y[3]][j + lst->x[3]] == '.'

typedef struct	s_
{
	int			x[4];
	int			y[4];
	char		c;
	struct s_	*n;
}				t_;

void			ft_valid_file(char *str, int len);
void			ft_array(char *str, int len);
void			ft_list(char ***str);
void			ft_next(t_ *lst2);

#endif
