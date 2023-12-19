/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:47:24 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 04:07:50 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param node 
 * @param f_del 
 */
// void	ft_lstdelone(t_list *node, void (*f_del)(void *))
// {
// 	if (node == NULL || f_del == NULL)
// 		return ;
// 	f_del(node->content);
// 	free(node);
// }
	// node = NULL;

void	ft_lstdelone(t_list *node, void (*f_del)(void *))
{
	if (node == NULL || f_del == NULL)
		return ;
	if (node->content)
		f_del(node->content);
	free(node);
}
