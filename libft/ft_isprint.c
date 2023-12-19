/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:42:25 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 23:17:11 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param chr 
 * @return int 
 */
int	ft_isprint(int chr)
{
	return (chr >= ' ' && chr <= '~');
}

// #include <locale.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		chr;
// 	char	c;

// 	chr = 0;
// 	c = 0;
// 	// setlocale(LC_ALL, "");
// 	while (chr < 127 || c < 127)
// 	{
// 		if (ft_isprint(chr))
// 		{
// 			printf("%c ", c);
// 			printf("%c ", chr);
// 		}
// 		c++;
// 		chr++;
// 	}
// 	return (0);
// }
