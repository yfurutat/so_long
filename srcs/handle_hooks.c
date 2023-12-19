/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:28:02 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/20 06:27:25 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	move_player(t_data *data, size_t new_x, size_t new_y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, \
		32 * data->p_x, 32 * data->p_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, \
		32 * new_x, 32 * new_y);
}

int	close_window(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	hoge(t_data *data, size_t new_x, size_t new_y)
{
	if (data->map[new_y][new_x] == '1')
		return ;
	else if (data->map[new_y][new_x] == '0' || data->map[new_y][new_x] == 'P')
		move_player(data, new_x, new_y);
	else if (data->map[new_y][new_x] == 'C')
	{
		move_player(data, new_x, new_y);
		data->map[new_y][new_x] = '0';
		data->collectibles--;
	}
	else if (data->map[new_y][new_x] == 'E')
	{
		if (data->collectibles != 0)
			return ;
		move_player(data, new_x, new_y);
		ft_putstr_fd("Grats!\n", STDOUT_FILENO);
		close_window(data);
	}
	data->p_x = new_x;
	data->p_y = new_y;
	data->cmd_cnt++;
	ft_putnbr_fd(data->cmd_cnt, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == UP)
		hoge(data, data->p_x, data->p_y - 1);
	else if (keycode == DOWN)
		hoge(data, data->p_x, data->p_y + 1);
	else if (keycode == LEFT)
		hoge(data, data->p_x - 1, data->p_y);
	else if (keycode == RIGHT)
		hoge(data, data->p_x + 1, data->p_y);
	return (0);
}

void	handle_hooks(t_data *data)
{
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, ON_DESTROY, 0, close_window, data);
}
