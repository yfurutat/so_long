/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:28:59 by yuske             #+#    #+#             */
/*   Updated: 2023/03/31 04:43:27 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//7L
/**
 * @brief 
 * 
 * @param str 
 * @param fd 
 */
void	ft_putstr_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str != '\0')
	{
		ft_putchar_fd(*str, fd);
		str += 1;
	}
}

//6L
// void	ft_putstr_fd(char *str, int fd)
// {
// 	size_t	len;

// 	if (str == NULL)
// 		return ;
// 	len = ft_strlen(str);
// 	write(fd, str, len);
// }

//4L
// void	ft_putstr_fd(char *str, int fd)
// {
// 	if (str == NULL)
// 		return ;
// 	while (*str != '\0')
// 		ft_putchar_fd(*str++, fd);
// }
