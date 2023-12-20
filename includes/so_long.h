/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:05:34 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 09:07:37 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open()
# include <unistd.h> // close(), read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <stdbool.h>
# include <errno.h>
# include "../libft/libft.h"

# define UP (65362)
# define DOWN (65364)
# define LEFT (65361)
# define RIGHT (65363)
# define ESC (65307)
# define ON_DESTROY (17)

typedef struct s_xpm_data
{
	void	*img_ptr;
	int		width;
	int		height;
}	t_xd;

typedef struct s_data
{
	char	**map;
	size_t	p_x;
	size_t	p_y;
	size_t	e_x;
	size_t	e_y;
	size_t	width;
	size_t	height;
	size_t	collectibles;
	size_t	exit;
	size_t	player;
	int		cmd_cnt;
	void	*mlx_ptr;
	void	*win_ptr;
	t_xd	img_b;
	t_xd	img_p;
	t_xd	img_c;
	t_xd	img_w;
	t_xd	img_e;
}	t_data;

void	exit_error(char *err_msg, t_data *data);
void	init_game(t_data *data);
void	parse_map(char *file_name, t_data *data);
void	scan_map(t_data *data);
void	free_map(char **map);
void	destroy_data(t_data *data);
void	handle_hooks(t_data *data);
bool	check_extension(char *file_name);
void	check_path(t_data *data);

#endif