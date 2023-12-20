/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:14:27 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 11:01:19 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

static bool	check_extension(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5 || file_name[len - 4] != '.' || file_name[len - 3] != 'b' \
		|| file_name[len - 2] != 'e' || file_name[len - 1] != 'r')
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		exit_error("Invalid argc", NULL);
	if (check_extension(argv[1]) == false)
		exit_error("Invalid extension", NULL);
	parse_map(argv[1], &data);
	scan_map(&data);
	if (data.height > Y_MAX || data.width > X_MAX)
		exit_error("Too big a map.\n", &data);
	init_game(&data);
	return (0);
}
	// printf("X %zd Y %zd\n", data.width, data.height);

// __attribute__((destructor))void	destructor()
// {
// 	system("leaks -q so_long");
// }
