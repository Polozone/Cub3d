/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:07:23 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/16 16:31:37 by pmulin           ###   ########.fr       */
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

char	*dec_to_hex_converter(unsigned long n, int caps)
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
	tab = ft_calloc(int_length(num) + 1, sizeof(char));
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

char	*fill_color(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		len;
	
	new = ft_calloc(4, sizeof(char));
	i = 0;
	j = 0;
	len = int_len(ft_atoi(str));
	while (i < (3 - len))
	{
		new[i] = '0';
		i++;
	}
	j = 0;
	while (i < 3)
	{
		new[i] = str[j];
		i++;
		j++;
	}
	return (new);
}


unsigned long createRGB(t_data *data)
{   
	int				i;
	unsigned long	rgb;
	char			*tmp;
	char			*tmp1;
	char			*tmp0;
	char			*tmpmem;

	i = 0;
	while (data->params[i].stop == 0)
	{
		if (data->params[i].color != NULL)
		{
			tmp1 = dec_to_hex_converter(ft_atoi(data->params[i].rgb[0]), 0);
			if (!ft_strncmp(tmp1, "0", ft_strlen(tmp1)))
			{
				tmp0 = tmp1;
				tmp1 = ft_strjoin(tmp1, "0");
				free(tmp0);
			}
			tmp = ft_strjoin(tmp, tmp1);
			free(tmp1);
			
			tmp1 = dec_to_hex_converter(ft_atoi(data->params[i].rgb[1]), 0);
			if (!ft_strncmp(tmp1, "0", ft_strlen(tmp1)))
			{
				tmp0 = tmp1;
				tmp1 = ft_strjoin(tmp1, "0");
				free(tmp0);
			}
			tmp = ft_strjoin(tmp, tmp1);
			free(tmp1);

			tmp1 = dec_to_hex_converter(ft_atoi(data->params[i].rgb[2]), 0);
			if (!ft_strncmp(tmp1, "0", ft_strlen(tmp1)))
			{
				tmp0 = tmp1;
				tmp1 = ft_strjoin(tmp1, "0");
				free(tmp0);
			}
			tmp = ft_strjoin(tmp, tmp1);
			tmp0 = ft_convert_base(tmp, "0123456789abcdef", "0123456789");
			if (!ft_strncmp("F", data->params[i].color, ft_strlen(data->params[i].color)))
			{
				data->floor_color = ft_atoi(tmp0);
			}
			else if (!ft_strncmp("C", data->params[i].color, ft_strlen(data->params[i].color)))
				data->ceil_color = ft_atoi(tmp0);
			free(tmp0); 
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
			newline = ft_substr(line, 0, sep);
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
