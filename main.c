/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 13:59:18 by tdeville         ###   ########lyon.fr   */
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
    parse_map_params(&data, argv[1]);
    free(data.map_line);
    free_param_struct(&data);
    return (0);
}
