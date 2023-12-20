/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:29:38 by yfurutat          #+#    #+#             */
/*   Updated: 2023/12/20 09:23:02 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include "mlx.h"

static size_t	count_lines(char *file_name)
{
	char	*line;
	size_t	cnt;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("\'open()\' failed.", NULL);
	cnt = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cnt++;
		free(line);
	}
	if (close(fd) == -1)
		exit_error("'close()' failed.", NULL);
	return (cnt);
}

void	parse_map(char *file_name, t_data *data)
{
	size_t	cnt;
	size_t	i;
	int		fd;

	cnt = count_lines(file_name);
	if (cnt == 0)
		exit_error("empty file", NULL);
	data->map = (char **)ft_calloc((cnt + 1), sizeof(char *));
	if (data->map == NULL)
		exit_error("'malloc()' failed.\n", NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_error("\'open()\' failed.\n", data);
	i = 0;
	while (i < cnt + 1)
	{
		data->map[i] = get_next_line(fd);
		i++;
		if (i == cnt)
			data->map[i] = NULL;
		if (i == cnt)
			break ;
	}
	if (close(fd) == -1)
		exit_error("'close()' failed.\n", data);
}
