/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:08:44 by rmattheo          #+#    #+#             */
/*   Updated: 2022/11/22 09:42:04 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"
#include "../libft.h"

t_track	*gc_lstnew(void **address)
{
	t_track	*lstnew;

	lstnew = malloc(sizeof(t_track));
	if (!lstnew)
		return (0);
	lstnew->address = *address;
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}
