/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 23:14:42 by yuske             #+#    #+#             */
/*   Updated: 2023/03/30 23:49:30 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FOUND 0

//13
/**
 * @brief 
 * 
 * @param str_l 
 * @param str_s 
 * @param n_look 
 * @return char* 
 */
char	*ft_strnstr(const char *str_l, const char *str_s, size_t n_look)
{
	size_t	len_s;

	if ((str_l == NULL && n_look == 0) || *str_s == '\0')
		return ((char *)str_l);
	len_s = ft_strlen(str_s);
	while (*str_l != '\0' && n_look > len_s - 1)
	{
		if ((ft_strncmp(str_l, str_s, len_s)) == FOUND)
			return ((char *)str_l);
		str_l += 1;
		n_look -= 1;
	}
	return (NULL);
}

//9L
// char	*ft_strnstr(const char *str_l, const char *str_s, size_t n)
// {
// 	if (*str_s == '\0' || (str_l == NULL && n == 0))
// 		return ((char *)str_l);
// 	while (*str_l != '\0' && n-- > ft_strlen(str_s) - 1)
// 	{
// 		if (!(ft_strncmp(str_l, str_s, ft_strlen(str_s))))
// 			return ((char *)str_l);
// 		str_l++;
// 	}
// 	return (NULL);
// }
