/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:18:41 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 11:21:20 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	init_strjoin(t_join	*d)
{
	d->str = NULL;
	d->i = 0;
	d->j = -1;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_join	d;

	init_strjoin(&d);
	d.str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
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
