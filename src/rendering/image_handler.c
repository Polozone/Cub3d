/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:06:20 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 14:11:49 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_img(t_data *data)
{
	int		i;
	char	*dst;

	i = 0;
	while (i < data->render->nbr_px)
	{
		dst = data->render->addr + (i * data->render->precompute_bits_p_px);
		*(unsigned int *)dst = 0x000000;
		i++;
	}
	return ;
}

char	*get_path_imgs(t_data *data, char *orientation)
{
	int		i;

	i = 0;
	while (data->params[i].stop != 1)
	{
		if (ft_strcmp(data->params[i].coord, orientation) == 0)
		{
			return (data->params[i].path);
		}
		i++;
	}
	return (NULL);
}

void	init_img(t_data *data, t_img *img, char *orientation)
{
	char	*path_name_tmp;
	char	*path_name;

	path_name_tmp = get_path_imgs(data, orientation);
	if (path_name_tmp == NULL)
		write(2, "bite\n", 5);
	path_name = ft_strjoin(path_name_tmp, ".xpm");
	img->img = mlx_xpm_file_to_image(data->render->mlx,
			path_name,
			&img->width,
			&img->height);
	if (img->img == NULL)
	{
		write(2, "Error\nwhen opening the texture ", 31);
		write(2, orientation, ft_strlen(orientation));
		free(path_name);
		exit (0);
	}
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->size_line, &img->endian);
	img->precompute_bits_p_px = img->bits_per_pixel / 8;
	free(path_name);
}

int	init_imgs(t_data *data)
{
	init_img(data, &data->east, "EA");
	init_img(data, &data->west, "WE");
	init_img(data, &data->north, "SO");
	init_img(data, &data->south, "NO");
	return (0);
}
