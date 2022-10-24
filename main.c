/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodeville <theodeville@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/24 17:52:49 by theodeville      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_map	map;

    (void)argc;
	// init_parsing_map(&data, &map, argv[1]);
	// free_2d_array(map.map);
    if (parse_map_params(&data, argv[1]) == true)
    {
        free(data.map_line);
        free_param_struct(&data);
    }
    return (0);
}
