/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:28:46 by yuske             #+#    #+#             */
/*   Updated: 2023/04/15 19:23:46 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param str 
 * @return size_t 
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len += 1;
	return (len);
}

// #include <stdio.h>
// #include <string.h>
// #include <limits.h>

// int	main(void)
// {
// 	char	*str1 = malloc(10);
// 	// behavior is undefined since the string is not null-terminated
// 	char	str2[10] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
// 	// behavior is undefined 
// 	// since the pointer does not point to a valid memory location
// 	char	*str3 = (char *)0xdeadbeef;

// 	printf("1. %zd\n", strlen(""));
// 	printf("1. %zd\n", ft_strlen(""));
// 	printf("2. %zd\n", strlen(" "));
// 	printf("2. %zd\n", ft_strlen(" "));
// 	printf("3. %zd\n", strlen("\0"));
// 	printf("3. %zd\n", ft_strlen("\0"));
// 	printf("4. %zd\n", strlen("\n"));
// 	printf("4. %zd\n", ft_strlen("\n"));
// 	printf("5. %zd\n", strlen("\a"));
// 	printf("5. %zd\n", ft_strlen("\a"));
// 	printf("6. %zd\n", strlen("\b"));
// 	printf("6. %zd\n", ft_strlen("\b"));
// 	printf("7. %zd\n", strlen("hello\0world"));
// 	printf("7. %zd\n", ft_strlen("hello\0world"));

// 	memcpy(str1, "helloworld", 10);
// 	printf("3. %zd\n", strlen(str1));
// 	printf("3. %zd\n", ft_strlen(str1));
// 	free(str1);
// 	printf("4. %zd\n", strlen(str1));
// 	printf("4. %zd\n", ft_strlen(str1));
// 	printf("5. %zd\n", strlen(str2));
// 	printf("5. %zd\n", ft_strlen(str2));
// 	// printf("6. %zd\n", strlen(str3));//segv
// 	// printf("6. %zd\n", ft_strlen(str3));//segv
// 	// printf("7. %zd\n", strlen(NULL));//segv
// 	// printf("7. %zd\n", ft_strlen(NULL));//segv
// 	// printf("8. %zd\n", strlen(0));//segv
// 	// printf("8. %zd\n", ft_strlen(0));//segv
// 	// printf("9. %zd\n", strlen(123));//incompatible
// 	return (0);
// }

// int	main(void)
// {
// 	char	str[SIZE_MAX + 1UL];
// 	// create a string of length ULONG_MAX

// 	// fill the string with 'A's
// 	ft_memset(str, 'A', SIZE_MAX - 1);
// 	// add a null terminator at the end of the string
// 	str[SIZE_MAX + 1] = '\0';
// 	printf("String length: %zu\n", strlen(str));
// 	printf("String length: %zu\n", ft_strlen(str));
// 	return (0);
// }
