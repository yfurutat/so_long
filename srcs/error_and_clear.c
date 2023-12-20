/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:08:54 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/20 09:44:26 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	free_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	destroy_data(t_data *data)
{
	free_map(data->map);
	if (data->mlx_ptr)
	{
		if ((data->img_p).img_ptr)
			mlx_destroy_image(data->mlx_ptr, (data->img_p).img_ptr);
		if ((data->img_e).img_ptr)
			mlx_destroy_image(data->mlx_ptr, (data->img_e).img_ptr);
		if ((data->img_c).img_ptr)
			mlx_destroy_image(data->mlx_ptr, (data->img_c).img_ptr);
		if ((data->img_w).img_ptr)
			mlx_destroy_image(data->mlx_ptr, (data->img_w).img_ptr);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	free(data->mlx_ptr);
}

void	exit_error(char *err_msg, t_data *data)
{
	if (data)
		destroy_data(data);
	ft_putstr_fd("Error:\n", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
