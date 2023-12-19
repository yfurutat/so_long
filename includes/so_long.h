/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:05:34 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 00:39:19 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> // open()
# include <unistd.h> // close(), read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <stdio.h> // perror()
# include <string.h> // strerror()
// # include <math.h>
# include <stdbool.h>
# include <errno.h>
# include "../libft/libft.h"
// #include "minilibx-linux/mlx.h"

# define W ""
# define A ""
# define S ""
# define D ""

typedef struct s_xpm_data
{
	void	*img_ptr;
	int		width;
	int		height;
}	t_xd;

typedef struct s_data
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	collectibles;
	size_t	exit;
	size_t	player;
	void	*mlx_ptr;
	void	*win_ptr;
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
bool	check_extension(char *file_name);

#endif