/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:35:07 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 14:12:29 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// strieri, stmapi: unsigned int では無限ループする可能性がある 

//10L
/**
 * @brief 
 * 
 * @param str 
 * @param fnc 
 */
void	ft_striteri(char *str, void (*fnc)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (str == NULL || fnc == NULL)
		return ;
	while (str[i] != '\0')
	{
		fnc(i, &str[i]);
		i += 1;
	}
}

// void	ft_toupper_p(unsigned int n, char *str)
// {
// 	if (*str >= 'a' && *str <= 'z')
// 		*str += ('A' - 'a');
// }

// int	main(void)
// {
// 	char	str[] = "abcdefghijklmno";

// 	ft_striteri(str, ft_toupper_p);
// 	printf("%s\n", str);
// 	return (0);
// }
