/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:49:58 by tdeville          #+#    #+#             */
/*   Updated: 2022/11/18 14:17:53 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_rect_color(t_render *render, t_vector2_d top_left, t_vector2_d bottom_right, int color)
{
	int		tmp;

	tmp = top_left.x;
	while (top_left.y < bottom_right.y)
	{
		top_left.x = tmp;
		while (top_left.x < bottom_right.x)
		{
			my_mlx_pixel_put(render, top_left.x, top_left.y, color);
			top_left.x++;
		}
		top_left.y++;
	}
}

void	print_around_player(t_data *dt, t_render *data)
{
	int	x;
	int	y;
    int i;
    int j;
	t_vector2_f position;

	position = dt->render->origin;
    i = (int)(position.y / 40) - 5;
    if (i < 0)
        i = 0;
    while (i < (int)(position.y / 40) + 5)
    {
        if (i > dt->maps->height - 1)
            i = dt->maps->height;
        j = (int)(position.x / 40) - 5;
        if (j < 0)
            j = 0;
        
        printf("j = %d\n", j);
        printf("i = %d\n", i);
        while (j < (int)(position.x / 40) + 5)
        {
			if (j > dt->maps->longest_line)
                j = dt->maps->longest_line;
            t_vector2_d top_left;
	 		t_vector2_d bottom_right;
	 		top_left.x = j * (dt->render->cell_size / 5);
	 		top_left.y = i * (dt->render->cell_size / 5);
	 		bottom_right.x = top_left.x + (dt->render->cell_size / 5);
	 		bottom_right.y = top_left.y + (dt->render->cell_size / 5);
            if (dt->maps->map[i][j] == '1') // If the cell is a wall
	 			draw_rect_color(data, top_left, bottom_right, 16711680);
			else if (ft_strchr("NSWE0", dt->maps->map[i][j]))
				draw_rect_color(data, top_left, bottom_right, 0);
            j++;
        }
        printf("ici1\n");
        i++;
    }
	printf("%d %d\n", (int)(position.x / 40), (int)(position.y / 40));
}

void	print_grid(t_data *dt, t_render *data)
{
	int		x;
	int		y;

	y = 0;
	while (dt->maps->map[y])
	{
		x = 0;
		while (dt->maps->map[y][x])
		{
			t_vector2_d top_left;
	 		t_vector2_d bottom_right;
	 		top_left.x = x * (dt->render->cell_size / 5);
	 		top_left.y = y * (dt->render->cell_size / 5);
	 		bottom_right.x = top_left.x + (dt->render->cell_size / 5);
	 		bottom_right.y = top_left.y + (dt->render->cell_size / 5);
			if (dt->maps->map[y][x] == '1') // If the cell is a wall
	 			draw_rect_color(data, top_left, bottom_right, 16711680);
			else if (ft_strchr("NSWE0", dt->maps->map[y][x]))
				draw_rect_color(data, top_left, bottom_right, 0);
			x++;
		}
		y++;
	}
}

int print_minimap(t_data *data)
{
    // // print_grid(data, data->render);
    // print_around_player(data, data->render);    
    return (0);
}