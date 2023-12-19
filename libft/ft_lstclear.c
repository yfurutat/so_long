/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:46:37 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 13:55:52 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// lstclear: del==NULL で freel) していないのでleak [ko] 

/**
 * @brief 
 * 
 * @param node 
 * @param f_del 
 */
// void	ft_lstclear(t_list **node, void (*f_del)(void *))
// {
// 	t_list	*tmp;

// 	if (node == NULL || f_del == NULL)
// 		return ;
// 	while (*node != NULL)
// 	{
// 		tmp = (*node)->next;
// 		ft_lstdelone(*node, f_del);
// 		(*node) = tmp;
// 	}
// }

void	ft_lstclear(t_list **node, void (*f_del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (node == NULL || *node == NULL || f_del == NULL)
		return ;
	current = *node;
	while (current != NULL)
	{
		next = current->next;
		f_del(current->content);
		free(current);
		current = next;
	}
	*node = NULL;
}
