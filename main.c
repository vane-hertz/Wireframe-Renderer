/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpadilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:50:44 by tpadilla          #+#    #+#             */
/*   Updated: 2016/11/30 17:39:57 by tpadilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Function for storing coordinates for printing
**
 map		*map_parser(char *line)
{
	map		*cds;
	int		i;

	i = 0;
	cds = (map*)malloc(sizeof(map));
	while (line[i])
	{
		if (line[i])
	}
	return (cds)
} */

void	window_handler(char	*file)
{
	map		*cds;
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	cds = (map*)malloc(sizeof(map));
	X = 0;
	Y = 0;
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, 400, 400, "FUCKING SHIT");
	get_next_line(fd, &line);
	while (line[i])
	{
		if (line[i] == ' ')
		{
			i++;
		}
		if (line[i] == '0')
		{
			i++;
			if (line[i - 1] != '1')
				X += 10;
		}
		if (line[i] == '1')
		{
			mlx_pixel_put(MLX, WIN, X, Y, 0x0055FF55);
			i++;
			X += 10;
		
		}
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			Y += 10;
			X = 0;
			get_next_line(fd, &line);
			i = 0;
		}
	}
	mlx_loop(MLX);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_map");
		return (0);
	}
	window_handler(argv[1]);
	return (0);
}
