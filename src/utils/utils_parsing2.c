/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:22:58 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/23 09:25:47 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned long long	int_length(unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

char	*rev_tab(char *tab)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = -1;
	j = ft_strlen(tab) - 1;
	if (tab[0] == '-')
		i = 0;
	while (++i < (ft_strlen(tab) / 2))
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		j--;
	}
	return (tab);
}

char	*dec_to_hex_converter(t_data *data, unsigned long n, int caps)
{
	char					*base;
	char					*tab;
	int						i;
	unsigned long long		num;

	base = "0123456789ABCDEF";
	if (caps == 0 || caps == 2)
		base = "0123456789abcdef";
	i = 0;
	num = n;
	if (n < 0)
		num = -n;
	tab = gc_calloc(int_length(num) + 1, sizeof(char), &data->track);
	if (!tab)
		return (0);
	while (num >= 16)
	{
		tab[i++] = base[num % 16];
		num /= 16;
	}
	tab[i] = base[num % 16];
	return (rev_tab(tab));
}

int	int_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int	is_map(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}
