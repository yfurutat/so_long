/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:36:16 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 02:13:43 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//19L
/**
 * @brief 
 * 
 * @param mem1 
 * @param mem2 
 * @param n_cmp 
 * @return int 
 */
int	ft_memcmp(const void *mem1, const void *mem2, size_t n_cmp)
{
	const unsigned char	*mem_box1;
	const unsigned char	*mem_box2;
	int					diff;
	size_t				i;

	mem_box1 = (const unsigned char *)mem1;
	mem_box2 = (const unsigned char *)mem2;
	diff = 0;
	i = 0;
	while (i < n_cmp)
	{
		if (mem_box1[i] != mem_box2[i])
		{
			diff = mem_box1[i] - mem_box2[i];
			break ;
		}
		i += 1;
	}
	return (diff);
}

//15L
// /**
//  * @brief 
//  * 
//  * @param mem1 
//  * @param mem2 
//  * @param n_cmp 
//  * @return int 
//  */
// int	ft_memcmp(const void *mem1, const void *mem2, size_t n_cmp)
// {
// 	const unsigned char	*mem_box1;
// 	const unsigned char	*mem_box2;
// 	int					diff;
// 	size_t				i;

// 	mem_box1 = (const unsigned char *)mem1;
// 	mem_box2 = (const unsigned char *)mem2;
// 	i = 0;
// 	while (i < n_cmp && mem_box1[i] == mem_box2[i])
// 		i += 1;
// 	if (i == n_cmp || !mem1 || !mem2)
// 		diff = 0;
// 	else
// 		diff = mem_box1[i] - mem_box2[i];
// 	return (diff);
// }

//12L
// /**
//  * @brief 
//  * 
//  * @param mem1 
//  * @param mem2 
//  * @param n_cmp 
//  * @return int 
//  */
// int	ft_memcmp(const void *mem1, const void *mem2, size_t n_cmp)
// {
// 	const unsigned char	*mem_box1;
// 	const unsigned char	*mem_box2;
// 	size_t				i;

// 	if (n_cmp == 0)
// 		return (0);
// 	mem_box1 = (const unsigned char *)mem1;
// 	mem_box2 = (const unsigned char *)mem2;
// 	i = 0;
// 	while (i < n_cmp - 1 && mem_box1[i] == mem_box2[i])
// 		i += 1;
// 	return (mem_box1[i] - mem_box2[i]);
// }
