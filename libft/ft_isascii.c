/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:35:10 by yuske             #+#    #+#             */
/*   Updated: 2023/04/03 23:35:00 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isascii(int chr)
{
	return (chr >= 0 && chr <= 127);
}

// // #include <locale.h>
// #include <stdio.h>

// 	// setlocale(LC_ALL, "");
// int	main(void)
// {
// 	int		chr;
// 	char	c;

// 	chr = 32;
// 	c = 32;
// 	while (chr < 127 || c < 127)
// 	{
// 		if (ft_isascii(chr))
// 		{
// 			printf("%c ", c);
// 			printf("%c ", chr);
// 		}
// 		c++;
// 		chr++;
// 	}
// 	return (0);
// }

// // int main() {
// //     setlocale(LC_ALL, "");
// //     for (char c = '!'; c <= '/'; c++) {
// //         printf("%c ", c);
// //     }
// //     printf("\n");
// //     return 0;
// // }
