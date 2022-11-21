/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:47:45 by pmulin            #+#    #+#             */
/*   Updated: 2022/11/21 11:36:42 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	clear_img(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->render->nbr_px)
	{
		char *dst = data->render->addr + (i * data->render->precompute_bits_p_px);
		*(unsigned int*)dst = 0x000000;
		i++;
	}
	return ;
}

void	init_win(t_data *data)
{
	void	*mlx;
	void	*mlx_window;

	data->render->cell_size = 40;
	data->render->mlx = mlx_init();
	if (data->render->mlx == NULL)
	{
		write(2, "Error during initialization instance of mlx\n", 44);
		exit (-1);
	}
	data->render->mlx_win = mlx_new_window(data->render->mlx, WIDTH, HEIGHT, "My window");
	data->render->img = mlx_new_image(data->render->mlx, WIDTH, HEIGHT);
	data->render->addr = mlx_get_data_addr(data->render->img, &data->render->bits_per_pixel, &data->render->line_length, &data->render->endian);
}

int	exit_program_from_escape(t_data *data)
{
	mlx_destroy_window(data->render->mlx, data->render->mlx_win);
	exit(0);
}

int	deal_key(int key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 1;
	return (0);
}

int	key_release(int	key, t_data *data)
{
	if (key > 200)
		return (0);
	data->keytab[key] = 0;
	return (0);
}

void	player_input(t_data *data)
{
	if (data->keytab[KEY_ESC])
		exit_program_from_escape(data);
	if (data->keytab[KEY_W])
		move_up(data);
	if (data->keytab[KEY_Q] || data->keytab[KEY_LEFT])
		rotate_left(data);
	if (data->keytab[KEY_S])
		move_down(data);
	if (data->keytab[KEY_E] || data->keytab[KEY_RIGHT])
		rotate_right(data);
	if (data->keytab[KEY_D])
		move_right(data);
	if (data->keytab[KEY_A])
		move_left(data);
}

int	update(t_data *data)
{
	player_input(data);
	clear_img(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	print_minimap(data);
	dda(data);
	hitbox(data);
	mlx_put_image_to_window(data->render->mlx, data->render->mlx_win, data->render->img, 0, 0);
	return (0);
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

void		init_img(t_data *data, t_img *img, char *orientation)
{
	char	*path_name_tmp;
	char	*path_name;

	path_name_tmp = get_path_imgs(data, orientation);
	if (path_name_tmp == NULL)
		write(2, "bite\n", 5);
	path_name = ft_strjoin(path_name_tmp, ".xpm");
	img->img = mlx_xpm_file_to_image(data->render->mlx, path_name, &img->width, &img->height);
	if (img->img == NULL)
	{
		write(2, "Error\nwhen opening the texture ", 31);
		write(2, orientation, ft_strlen(orientation));
		free(path_name);
		exit (0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);
	img->precompute_bits_p_px = img->bits_per_pixel / 8;
	free(path_name);
}

int		init_imgs(t_data *data)
{
	init_img(data, &data->east, "EA");
	init_img(data, &data->west, "WE");
	init_img(data, &data->north, "SO");
	init_img(data, &data->south, "NO");
	return (0);
}

void	init_mlx(t_data *data)
{
	init_win(data);
	init_data(data);
	init_imgs(data);
	data->render->precompute_bits_p_px = data->render->bits_per_pixel >> 3;
	data->render->nbr_px = WIDTH * HEIGHT;
}
