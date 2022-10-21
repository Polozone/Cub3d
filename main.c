/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmulin <pmulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/21 13:09:33 by pmulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_map	map;

    (void)argc;
    // (void)map;
    // parse_map_params(&data, argv[1]);
    parse_map_params(&data, argv[1]);
	init_parsing_map(&data, &map, argv[1]);
	free_2d_array(map.map);
    // get_cub_file(&data, argv[1]);
    return (0);
}
