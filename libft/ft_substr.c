/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:59:02 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 18:37:24 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// substr: malloc()する量が多すぎることがある 

/**
 * @brief 
 * 
 * @param str: the material string to create a substring from
 * @param start (unsigned int): the point from which to start copying
 * @param len: length of substring this func creates 
 * @return char* sub: substring. empty (""), if (start >= end || len = 0)
 * 			NULL: if malloc() fails or the passed string is NULL.
 */
// char	*ft_substr(char const *str, unsigned int start, size_t len)
// {
// 	char	*sub;
// 	size_t	end;
// 	size_t	i;

// 	if (str == NULL)
// 		return (NULL);
// 	end = ft_strlen(str);
// 	if (start >= end)
// 		len = 0;
// 	else if (len > end - start)
// 		len = end - start;
// 	sub = (char *)malloc(sizeof(char) * (len + 1));
// 	if (sub == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < len && start < end)
// 		sub[i++] = str[start++];
// 	sub[i] = '\0';
// 	return (sub);
// }
		// sub[i++] = (char)str[start++];
	// else if (len > end)
	// 	len = end;

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	end;

	if (str == NULL)
		return (NULL);
	end = ft_strlen(str);
	if (len == 0 || start >= end)
		return (ft_strdup(""));
	if (len > end - start)
		len = end - start;
	return (ft_strndup(&str[start], len));
}
		// return (ft_strndup("", 0));
