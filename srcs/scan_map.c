/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:54:47 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 09:22:51 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "mlx.h"

static size_t	row_len(char *row)
{
	size_t	len;

	if (!row)
		return (0);
	len = 0;
	while (row[len] != '\0' && row[len] != '\n')
		len++;
	return (len);
}

static void	handle_cep(t_data *data, size_t i, size_t j)
{
	if (data->map[i][j] == 'C')
		data->collectibles++;
	if (data->map[i][j] == 'E')
	{
		data->e_x = j;
		data->e_y = i;
		data->exit++;
	}
	if (data->map[i][j] == 'P')
	{
		data->p_x = j;
		data->p_y = i;
		data->player++;
	}
}

static void	check_char(t_data *data, size_t i, size_t j)
{
	if (!ft_strchr("01CEP", data->map[i][j]))
		exit_error("Invalid character.\n", data);
	if (i == 0 || j == 0 || data->map[i + 1] == NULL \
		|| data->map[i][j + 1] == '\0' || data->map[i][j + 1] == '\n')
	{
		if (data->map[i][j] != '1')
			exit_error("broken wall.\n", data);
	}
	handle_cep(data, i, j);
	if (data->exit > 1)
		exit_error("Too many exits.\n", data);
	if (data->player > 1)
		exit_error("Too many players.\n", data);
}

void	scan_map(t_data *data)
{
	size_t	i;
	size_t	j;

	data->width = row_len(data->map[0]);
	i = 0;
	while (data->map[i])
	{
		if (data->width != row_len(data->map[i]))
			exit_error("Not rectagular.\n", data);
		j = 0;
		while (data->map[i][j] != '\n' && data->map[i][j] != '\0')
		{
			check_char(data, i, j);
			j++;
		}	
		i++;
	}
	if (data->collectibles == 0)
		exit_error("No collectibles.\n", data);
	if (data->exit == 0)
		exit_error("No exit.\n", data);
	if (data->player == 0)
		exit_error("No player.\n", data);
	data->height = i;
	check_path(data);
}
