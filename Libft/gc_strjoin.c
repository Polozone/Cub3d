/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:05:34 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/23 11:22:58 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gc.h"

static void	init_strjoin(t_join	*d)
{
	d->str = NULL;
	d->i = 0;
	d->j = -1;
}

char	*gc_strjoin(t_track **track, char const *s1, char const *s2)
{
	t_join	d;

	init_strjoin(&d);
	d.str = gc_calloc(sizeof(char),
			((ft_strlen(s1) + ft_strlen(s2)) + 2), track);
	if (!d.str)
		return (0);
	if (s1)
	{
		while (s1[d.i])
		{
			d.str[d.i] = s1[d.i];
			d.i++;
		}
	}
	if (s2)
	{
		while (s2[++d.j])
		{
			d.str[d.i] = s2[d.j];
			d.i++;
		}
	}
	d.str[d.i] = '\0';
	return (d.str);
}
