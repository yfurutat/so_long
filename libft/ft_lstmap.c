/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:50:56 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 06:51:52 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief process a linked list through mapping
 * 		=apply a funtion to each node of the passed list and create a new list
 * 	1. make a new node by ft_lstnew() 
 *  	as long as allocation succeeds & list doesn't reach NULL terminator, 
 *  2. add new node after previous one by lstadd_back()
 *  3. move on to next node to iterate this process.
 * 
 * @param node pointer to the current node of the passed linked list
 * @param f_proc function to apply to each node of the passed linked list
 * @param f_del function to delete the content of the node 
 * 			in case mapping process has failed
 * @return t_list* pointer to the header node of newly created linked list 
 * 			if the mapping is successfully complete
 *          else if mapping/allocation has failed
 * 			->clear all newly created nodes by ft_lstclear() & return null
 */
t_list	*ft_lstmap(t_list *node, void *(*f_proc)(void *), void (*f_del)(void *))
{
	t_list	*new_node;
	t_list	*head_newlst;

	if (f_proc == NULL || f_del == NULL)
		return (NULL);
	head_newlst = NULL;
	while (node != NULL)
	{
		new_node = ft_lstnew(f_proc(node->content));
		if (new_node == NULL)
		{
			ft_lstclear(&head_newlst, f_del);
			return (head_newlst);
		}
		ft_lstadd_back(&head_newlst, new_node);
		node = node->next;
	}
	return (head_newlst);
}
