/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:08:43 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 15:42:27 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && str[i] != '\0')
	{
		dup[i] = str[i];
		i += 1;
	}
	dup[i] = '\0';
	return (dup);
}
	// if (str == NULL)
	// 	return (NULL);//the original is not equipped with null guards.

// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "hello";

// 	printf("%s\n", strndup(str, 0));
// 	printf("%s\n", ft_strndup(str, 0));
// 	printf("%s\n", strndup(str, SIZE_MAX));
// 	printf("%s\n", ft_strndup(str, SIZE_MAX));
// 	printf("%s\n", strndup(NULL, 0));
// 	printf("%s\n", ft_strndup(NULL, 0));
// 	// printf("%s\n", strndup(NULL, 1));//segv
// 	// printf("%s\n", ft_strndup(NULL, 1));//segv
// 	return (0);
// }
