/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:26:52 by tdeville          #+#    #+#             */
/*   Updated: 2022/10/20 15:17:26 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int main(int argc, char **argv)
{
    t_data  data;
    t_map	map;

    (void)argc;
    parse_map_params(&data, argv[1]);
	(void)argc;
	(void)argv;
	init_parsing_map(&data, &map, argv[1]);
    // get_cub_file(&data, argv[1]);
    get_cub_file(&data, argv[1]);
    return (0);
}
