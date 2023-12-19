/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:40:19 by yuske             #+#    #+#             */
/*   Updated: 2023/03/30 05:10:48 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//5L
/**
 * @brief 
 * 
 * @param str 
 * @param chr 
 * @return char* 
 */
char	*ft_strchr(const char *str, int chr)
{
	while (*str != (unsigned char)chr && *str != '\0')
		str += 1;
	if (*str == (unsigned char)chr)
		return ((char *)str);
	return (NULL);
}
