/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:38:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/22 09:48:35 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gc.h"

void	*gc_calloc(size_t count, size_t size, t_track **track)
{
	size_t	tot;
	void	*dst;

	tot = size * count;
	dst = malloc(tot);
	if (!(dst))
		return (NULL);
	ft_bzero(dst, tot);
	gc_add_mal(track, (void **)&dst);
	return (dst);
}
