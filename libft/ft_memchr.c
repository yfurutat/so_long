/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:21:19 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 05:49:39 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//10L
/**
 * @brief 
 * 
 * @param mem 
 * @param chr 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void *mem, int chr, size_t n)
{
	const unsigned char	*mem_caster;

	mem_caster = (const unsigned char *)mem;
	while (n > 0)
	{
		if (*mem_caster == (unsigned char)chr)
			return ((char *)mem_caster);
		mem_caster += 1;
		n -= 1;
	}
	return (NULL);
}
