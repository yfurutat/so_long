/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfurutat <yfurutat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:14:27 by efmacm23          #+#    #+#             */
/*   Updated: 2023/12/20 04:00:13 by yfurutat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

// typedef struct s_vars {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// }	t_vars;

// int	key_hook(int keycode, void *data)
// {
// 	if (keycode == ESC) 
// 	{
// 		destroy_data(data);
// 		exit(EXIT_SUCCESS);
// 	}
// 	printf("%d!\n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	data;

// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world!");
// 	mlx_key_hook(data.win_ptr, key_hook, &data);
// 	mlx_loop(data.mlx_ptr);
// }

// (for window 1)
// if (key_is_released)
// 	key_hook(keycode, data);

// (for window 2)
// if (key_is_released)
// 	key_hook2(keycode, data);

void	print_map(char **map)
{
	size_t	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

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

bool	check_extension(char *file_name)
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
	init_game(&data);
	print_map(data.map);
	free_map(data.map);
	return (0);
}
	// exit_error("fin\n", &data);
	// int fd = open(argv[1], O_RDONLY);
	// if (fd == -1)
	// {
	// 	perror(argv[1]);
	// 	printf("%d\n", errno);
	// 	// printf("ERROR\n");
	// 	// return (errno);
	// }

// int	main(int argc)
// {
// 	// void	*mlx_ptr;
// 	// void	*win_ptr;

// 	// // Initialize the MiniLibX
// 	// mlx_ptr = mlx_init();
// 	// if (!mlx_ptr)
// 	// 	return EXIT_FAILURE;

// 	// // Create a new window
// 	// win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Hello MiniLibX");
// 	// if (!win_ptr) {
// 	// 	// Free resources if window creation fails
// 	// 	mlx_destroy_display(mlx_ptr);
// 	// 	free(mlx_ptr);
// 	// 	return EXIT_FAILURE;
// 	// }

// 	// // Start the event loop
// 	// mlx_loop(mlx_ptr);

// 	// // Clean up (though this part of the code is typically never reached,
// 	// // as mlx_loop is usually only exited when the program is terminating)
// 	// mlx_destroy_window(mlx_ptr, win_ptr);
// 	// mlx_destroy_display(mlx_ptr);
// 	// // Avoid freeing mlx_ptr directly as MiniLibX manages its memory
// 	return EXIT_SUCCESS;
// }

// __attribute__((destructor))void	destructor()
// {
// 	system("leaks -q so_long");
// }
