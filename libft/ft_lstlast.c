/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:49:14 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 08:11:20 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//7 lines
/**
 * @brief determines and returns a pointer to the last node of a linked list.
 * 
 * @param node pointer to the node node of a linked list you are handling.
 * 
 * @return t_list* pointer to the last node of a list
 * 				implementation failed -> NULL
 * 
 * @details Traverses the linked list from the node passed as the argument
 * 		until it reaches the last node, the pointer to which is returned.
 * 		If the input node is NULL, this function returns NULL.
 * 
 * @note linked list: a collection of nodes, where each node contains a value
 * and a pointer to the next node in the list. The last node in the list has
 * a pointer to NULL. This function can be used to determine the last node in
 * a list, which is useful for various operations such as appending a new
 * node to the end of the list.
 */
t_list	*ft_lstlast(t_list *node)
{
	while (node != NULL)
	{
		if (node->next == NULL)
			break ;
		node = node->next;
	}
	return (node);
}

// int	main(int argc, char *argv[])
// {
// 	t_list	*head;
// 	t_list	*current;
// 	int		i;

// 	i = 1;
// 	head = ft_lstnew((char *)argv[i]);
// 	current = head;
// 	i += 1;
// 	while (i < argc)
// 	{
// 		current->next = ft_lstnew((char *)argv[i]);
// 		current = current->next;
// 		i += 1;
// 	}
// 	current->next = NULL;
// 	current = head;
// 	printf("%s\n", (char *)current->content);
// 	current = ft_lstlast(current);
// 	printf("%s\n", (char *)current->content);
// 	printf("%p\n", current->next);
// 	return (0);
// }
