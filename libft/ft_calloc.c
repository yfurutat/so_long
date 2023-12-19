/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:51:39 by yuske             #+#    #+#             */
/*   Updated: 2023/04/05 04:10:04 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 13L
/**
 * @brief 
 * 
 * @param num 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t num, size_t size)
{
	void	*mem;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	if (size > SIZE_MAX / num)
		return (NULL);
	mem = malloc(num * size);
	if (mem != NULL)
		ft_bzero(mem, num * size);
	return (mem);
}
		// ft_calloc(1, 1);
		// return (NULL);
