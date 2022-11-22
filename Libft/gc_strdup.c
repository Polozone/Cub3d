/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:58:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/22 09:38:56 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gc.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*gc_strdup(t_track **track, const char *src)
{
	char	*dest;

	dest = gc_calloc(sizeof(char), ft_strlen(src) + 1, track);
	if (!dest)
		return (0);
	ft_strcpy(dest, src);
	return (dest);
}
