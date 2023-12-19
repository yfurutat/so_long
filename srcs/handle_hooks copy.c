/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 02:28:02 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/20 06:23:51 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	move_player(t_data *data, size_t new_x, size_t new_y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
}

int	close_window(t_data *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

// void	exit_hook(t_data *data)
// {
// 	destroy_data(data);
// 	exit(EXIT_SUCCESS);
// }

// int	close_window(int button, int x, int y, t_data *data)
	// (void)button;
	// (void)x;
	// (void)y;

void	move_to_0(t_data *data, size_t new_x, size_t new_y)
{
	// turn player tile to black
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
	// turn new tile to player
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
}

void	move_to_c(t_data *data, size_t new_x, size_t new_y)
{
	// turn player to black
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
	// turn collectible to player
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
	move_player(data, new_x, new_y);
	data->collectibles--;
}

		// turn player to black
		// turn collectible to player
void	move_to_e(t_data *data, size_t new_x, size_t new_y)
{
	if (data->collectibles == 0)
	{
		move_player(data, new_x, new_y);
		ft_putstr_fd("Grats!\n", STDOUT_FILENO);
		close_window(data);
	}
	else
	{
		//cannot move / 
		return ;
	}
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

// void	moves()

// void	hoge(t_data *data, size_t new_x, size_t new_y)
// {
// 	//wall || (collectible != 0 && [new_y][new_x])
// 	if (data->map[new_y][new_x] == '1')
// 		return ;
// 	else if (data->map[new_y][new_x] == '0' || data->map[new_y][new_x] == 'P')
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
		
// 	}
// 	else if (data->map[new_y][new_x] == 'C')
// 	{
// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_b.img_ptr, 32 * data->p_x, 32 * data->p_y);
// 		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_p.img_ptr, 32 * new_x, 32 * new_y);
// 		data->collectibles--;
// 	}
// 	else if (data->map[new_y][new_x] == 'E')
// 	{
// 		if (data->collectibles == 0)
// 		{
// 			move_player(data, new_x, new_y);
// 			ft_putstr_fd("Grats!\n", STDOUT_FILENO);
// 			close_window(data);
// 		}
// 		else
// 		{
// 			//cannot move / 
// 			return ;
// 		}
// 	}
// 	data->p_x = new_x;
// 	data->p_y = new_y;
// 	data->cmd_cnt++;
// 	// if ()
// 	// 	data->collectibles--;
// 	//
// }

// void	hoge(t_data *data, size_t new_x, size_t new_y)
// {
// 	//wall || (collectible != 0 && [new_y][new_x])
// 	if (data->map[new_y][new_x] == '1')
// 		return ;
// 	else if (data->map[new_y][new_x] == '0')
// 		move_player(data, new_x, new_y);
// 	else if (data->map[new_y][new_x] == 'C')
// 	{
// 		move_to_c(data, new_x, new_y);
// 	}
// 	else if (data->map[new_y][new_x] == 'E')
// 	{
// 		move_to_e(data, new_x, new_y);
// 	}
// 	data->cmd_cnt++;
// 	// if ()
// 	// 	data->collectibles--;
// 	//
// }


	// printf("%d!\n", keycode);

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
