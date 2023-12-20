/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 07:01:44 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/20 10:49:53 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pave_path(char **map, size_t x, size_t y, size_t *cnt)
{
	if (map[y][x] == 'C')
		(*cnt)++;
	if (map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'E' \
		|| map[y][x] == 'X')
	{
		if (map[y][x] == 'E')
			map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'F';
	pave_path(map, x - 1, y, cnt);
	pave_path(map, x + 1, y, cnt);
	pave_path(map, x, y - 1, cnt);
	pave_path(map, x, y + 1, cnt);
}

static char	**mapdup(char **map, size_t height)
{
	char	**dup;
	size_t	i;

	dup = (char **)malloc((height + 1) * sizeof(char *));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		dup[i] = ft_strdup(map[i]);
		if (dup[i] == NULL)
		{
			free_map(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

void	check_path(t_data *data)
{
	size_t	cnt;
	char	**map_copy;
	char	exit_chr;

	map_copy = mapdup(data->map, data->height);
	if (map_copy == NULL)
		exit_error("malloc() failed.\n", data);
	cnt = 0;
	pave_path(map_copy, data->p_x, data->p_y, &cnt);
	exit_chr = map_copy[data->e_y][data->e_x];
	free_map(map_copy);
	if (exit_chr != 'X' || cnt < data->collectibles)
		exit_error("No way out.\n", data);
}
