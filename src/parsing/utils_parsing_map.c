/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:07:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/22 10:20:11 by tdeville         ###   ########lyon.fr   */
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

int	int_len(int	n)
{
	int i;
	
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

unsigned long createRGB(t_data *data)
{   
	int				i;
	int				j;
	unsigned long	rgb;
	char			*tmp;
	char			*tmp1;

	i = 0;
	tmp = NULL;
	while (data->params[i].stop == 0)
	{
		if (data->params[i].color != NULL)
		{
			j = -1;
			while (++j < 3)
			{
				tmp1 = dec_to_hex_converter(data, ft_atoi(data->params[i].rgb[j]), 0);
				if (!ft_strncmp(tmp1, "0", ft_strlen(tmp1)))
					tmp1 = gc_strjoin(&data->track, tmp1, "0");
				tmp = gc_strjoin(&data->track, tmp, tmp1);
			}
			tmp1 = ft_convert_base(data, tmp, "0123456789abcdef", "0123456789");
			if (!ft_strncmp("F", data->params[i].color, ft_strlen(data->params[i].color)))
				data->floor_color = ft_atoi(tmp1);
			else if (!ft_strncmp("C", data->params[i].color, ft_strlen(data->params[i].color)))
				data->ceil_color = ft_atoi(tmp1);
		}
		tmp = NULL;
		i++;
	}
	return (0);
}

int		get_longest_line(char *line)
{
	int		i;
	int		longest;
	int		tmp;
	int		max;

	i = 0;
	longest = 0;
	max = ft_strlen(line);
	if (!line)
		return (-1);
	while (line[i])
	{
		tmp = 0;
		while (line[i] && line[i] != '\n')
		{
			tmp++;
			i++;
		}
		if (tmp > longest)
			longest = tmp;
		if (i >= max)
		 	return (longest);
		i++;
	}
	return (longest);
}

int				is_map(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	else
		return (false);
}

char		*clear_endmap(char	*line)
{
	int		sep;
	int		len;
	char	*newline;

	sep = ft_strlen(line);
	len = sep;
	if (line == 0)
		return (NULL);
	while (sep > 0)
	{
		if (is_map(line[sep]))
		{
			newline = ft_substr(line, 0, sep + 1);
			free(line);
			return (newline);
		}
		sep--;
	}
	return (NULL);
}

int		count_nl(char *line)
{
	int		i;
	int		cmpt;

	i = 0;
	cmpt = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
			cmpt++;
		i++;
	}
	return (cmpt + 1);
}
