/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:30:46 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/22 09:42:04 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"
#include "../libft.h"

void	gc_lstadd_front(t_track **track, t_track *new)
{
	if (!track || !new)
		return ;
	new->next = *track;
	(*track)->prev = new;
	*track = new;
}
