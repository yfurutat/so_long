/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:36:38 by yuske             #+#    #+#             */
/*   Updated: 2023/04/07 02:44:14 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//11L
/**
 * @brief 
 * 
 * @param mem 
 * @param chr 
 * @param n_toset 
 * @return void* 
 */
void	*ft_memset(void *mem, int chr, size_t n_toset)
{
	unsigned char	*mem_caster;
	size_t			i;

	i = 0;
	mem_caster = (unsigned char *)mem;
	while (i < n_toset)
	{
		mem_caster[i] = (unsigned char)chr;
		i += 1;
	}
	return (mem_caster);
}
