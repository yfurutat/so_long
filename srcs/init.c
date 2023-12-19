/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:37:53 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 06:29:27 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	create_images(t_data *data)
{
	(data->img_b).img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		"textures/b32.xpm", &((data->img_b).width), &((data->img_b).height));
	if ((data->img_b).img_ptr == NULL)
		exit_error("mlx_xpm_file_to_image() failed.\n", data);
	(data->img_p).img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		"textures/p32.xpm", &((data->img_p).width), &((data->img_p).height));
	if ((data->img_p).img_ptr == NULL)
		exit_error("mlx_xpm_file_to_image() failed.\n", data);
	(data->img_c).img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		"textures/c32.xpm", &((data->img_c).width), &((data->img_c).height));
	if ((data->img_c).img_ptr == NULL)
		exit_error("mlx_xpm_file_to_image() failed.\n", data);
	(data->img_w).img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		"textures/w32.xpm", &((data->img_w).width), &((data->img_w).height));
	if ((data->img_w).img_ptr == NULL)
		exit_error("mlx_xpm_file_to_image() failed.\n", data);
	(data->img_e).img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, \
		"textures/e32.xpm", &((data->img_e).width), &((data->img_e).height));
	if ((data->img_e).img_ptr == NULL)
		exit_error("mlx_xpm_file_to_image() failed.\n", data);
}

void	put_pix(t_data *data, size_t i, size_t j)
{
	const char	c = (data->map)[i][j];
	void		*img;

	img = NULL;
	if (c == 'P')
		img = (data->img_p).img_ptr;
	else if (c == 'E')
		img = (data->img_e).img_ptr;
	else if (c == 'C')
		img = (data->img_c).img_ptr;
	else if (c == '1')
		img = (data->img_w).img_ptr;
	else
		return ;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 32 * j, 32 * i);
}

void	deploy_images(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((data->map)[i])
	{
		j = 0;
		while ((data->map)[i][j])
		{
			put_pix(data, i, j);
			j++;
		}
		i++;
	}
}

// /opt/X11/include/X11/X.h
void	init_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		exit_error("mlx_init() failed.\n", data);
	create_images(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
		32 * data->width, 32 * data->height, "so_long");
	if (data->win_ptr == NULL)
		exit_error("mlx_new_window() failed.\n", data);
	deploy_images(data);
	handle_hooks(data);
	mlx_loop(data->mlx_ptr);
}

// #include <stdio.h>

// int	main()
// {
// 	t_data data;

// 	ft_memset(&data, 0, sizeof(t_data));
// 	data.width = 10;
// 	data.height = 12;
// 	init_game(&data);
// 	// data.mlx_ptr = mlx_init();
// 	// if (data.mlx_ptr == NULL)
// 	// 	return 1;
// 	// // printf("%p\n", data.mlx_ptr);
// 	// data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "new");
// 	// if (data.win_ptr == NULL) {
// 	// 	free(data.mlx_ptr);
// 	// 	return 1;
// 	// }
// 	(data.img_p).img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, \
// 		"textures/p32.xpm", &((data.img_p).width), &((data.img_p).height));
// 	// if ((data.img_p).img_ptr == NULL) {
// 	// 	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
// 	// 	free(data.mlx_ptr);
// 	// 	return 1;
// 	// }
// 	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, (data.img_p).img_ptr, 50, 50);
// 	// mlx_loop(data.mlx_ptr);
// 	// mlx_destroy_window(data.mlx_ptr, data.win_ptr);
// 	// free(data.mlx_ptr);
// 	return 0;
// }
// 	printf("W: %d H: %d\n", ((data.img_p).width), ((data.img_p).height));
// 	free(data.win_ptr);
