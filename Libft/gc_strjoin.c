/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:05:34 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/22 09:53:04 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gc.h"

char	*gc_strjoin(t_track **track, char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = -1;
	str = gc_calloc(sizeof(char), ((ft_strlen(s1) + ft_strlen(s2)) + 2), track);
	if (!str)
		return (0);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[++j])
		{
			str[i] = s2[j];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
