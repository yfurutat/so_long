/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:31:01 by yuske             #+#    #+#             */
/*   Updated: 2023/04/04 14:06:04 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strieri, stmapi: unsigned int では無限ループする可能性がある 

//18L
/**
 * @brief 
 * 
 * @param str 
 * @param fnc 
 * @return char* 
 */
char	*ft_strmapi(char const *str, char (*fnc)(unsigned int, char))
{
	size_t	i;
	size_t	end;
	char	*new_str;

	if (str == NULL || fnc == NULL)
		return (NULL);
	end = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * (end + 1));
	if (new_str != NULL)
	{
		i = 0;
		while (i < end)
		{
			new_str[i] = fnc(i, str[i]);
			i += 1;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
	// while (str[i] != '\0')
	// unsigned int	i;//infinite loop
	// unsigned int	end;//infinite loop

// char	ft_toupper_p(unsigned int n, char chr);

// int	main(void)
// {
// 	printf("%s\n", ft_strmapi("hello", ft_toupper_p));
// }

// char	ft_toupper_p(unsigned int n, char chr)
// {
// 	if (chr >= 'a' && chr <= 'z')
// 		chr += ('A' - 'a');
// 	return (chr);
// }
