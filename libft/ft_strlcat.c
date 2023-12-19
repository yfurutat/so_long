/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuske <yuske@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:02:52 by yuske             #+#    #+#             */
/*   Updated: 2023/04/01 07:48:20 by yuske            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//14L len_cat = 

/**
 * @brief 
 * 
 * @param dst 
 * @param src: string to append to dst. always SEGV if this is NULL.
 * @param len_cat: total length of the concatenated strings
 * @return size_t len_dst + len_src, if len_cat > len_dst
 * 				  len_cat + len_src, if len_cat <= len_dst
 * 
 * @details len_cat = len_dst + len_src -> just
 * 			len_cat > len_dst -> cat happens
 * 			len_cat <= len_dst -> cat doesn't happen
 */
// size_t	ft_strlcat(char *dst, const char *src, size_t len_cat)
// {
// 	size_t	len_src;
// 	size_t	len_dst;

// 	len_src = ft_strlen(src);
// 	if (len_cat == 0)
// 		return (len_src);
// 	len_dst = ft_strlen(dst);
// 	if (len_cat <= len_dst)
// 		return (len_src + len_cat);
// 	dst += len_dst;
// 	while (*src != '\0' && len_dst + 1 < len_cat)
// 	{
// 		*dst = *src;
// 		dst += 1;
// 		src += 1;
// 		len_cat -= 1;
// 	}
// 	*dst = '\0';
// 	return (len_src + len_dst);
// }

size_t	ft_strlcat(char *dst, const char *src, size_t total_len)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	slen = ft_strlen(src);
	if (total_len == 0)
		return (slen);
	dlen = ft_strlen(dst);
	if (total_len <= dlen)
		return (slen + total_len);
	i = 0;
	while (total_len > dlen + i + 1 && src[i] != '\0')
	{
		dst[dlen + i] = src[i];
		i += 1;
	}
	dst[dlen + i] = '\0';
	return (slen + dlen);
}

// size_t	ft_strlcat(char *dst, const char *src, size_t total_len)
// {
// 	size_t	slen;
// 	size_t	dlen;
// 	size_t	i;

// 	slen = ft_strlen(src);
// 	if (total_len == 0)
// 		dlen = 0;
// 	else
// 		dlen = ft_strlen(dst);
// 	if (total_len <= dlen)
// 		return (slen + total_len);
// 	i = 0;
// 	while (total_len > dlen + i + 1 && src[i] != '\0')
// 	{
// 		dst[dlen + i] = src[i];
// 		i += 1;
// 	}
// 	dst[dlen + i] = '\0';
// 	return (slen + dlen);
// }
		// dst = strdup("");//never change the original dst!
		// underflow if len_cat is 0
		// while (*src != '\0' && len_dst < len_cat - 1)
	// while (*src && len_dst + 1 < len_cat--)
	// 	*dst++ = *src++;

//NG
// size_t	ft_strlcat(char *dst, const char *src, size_t total_len)
// {
// 	size_t	slen;
// 	size_t	dlen;
// 	size_t	i;

// 	slen = ft_strlen(src);
// 	dlen = 0;
// 	if (dst != NULL && total_len > 0)
// 		dlen = ft_strlen(dst);
// 	i = 0;
// 	while (total_len > dlen + i + 1 && src[i] != '\0')
// 	{
// 		dst[dlen + i] = src[i];
// 		i += 1;
// 	}
// 	if (dst != NULL)
// 		dst[dlen + i] = '\0';
// 	return (slen + dlen);
// }

// int	main(void)
// {
// 	size_t	len_rtn;
// 	size_t	len_cat;
// 	char	*dst;
// 	char	*src;

// 	dst = strdup("abcdefghijklmnopqrstuvwxyz");
// 	src = strdup("012345678");
// 	len_cat = 27;
// 	len_rtn = strlcat(dst, src, len_cat);
// 	printf("[org]l: %zd cat: %s\n", len_rtn, dst);
// 	return (0);
// }
	// printf("[org]l:%zd\n", strlcat(NULL, NULL, 0));
	// printf("[org]l:%zd\n", strlcat(NULL, "OK?", 0));
	// printf("[org]l:%zd\n", ft_strlcat(NULL, NULL, 0));//segv
	// printf("[org]l:%zd\n", ft_strlcat(NULL, "OK?", 0));

// SYNOPSIS
//      #include <string.h>

//      size_t
//      strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

//      size_t
//      strlcat(char * restrict dst, const char * restrict src, size_t dstsize);

// DESCRIPTION
//      The strlcpy() and strlcat() functions copy and concatenate strings with
//      the same input parameters and output result as snprintf(3).  They are
//      designed to be safer, more consistent, and less error prone replacements
//      for the easily misused functions strncpy(3) and strncat(3).

//      strlcpy() and strlcat() take the full size of the destination buffer and
//      guarantee NUL-termination if there is room.  Note that room for the NUL
//      should be included in dstsize.  Also note that strlcpy() and strlcat()
//      only operate on true ''C'' strings. This means that for strlcpy() src
//      must be NUL-terminated and for strlcat() both src and dst() must be NUL-
//      terminated.

//      strlcpy() copies up to dstsize - 1 characters 
//      from the string src to dst,
//      NUL-terminating the result if dstsize is not 0.

//      strlcat() appends string src to the end of dst.  It will append at most
//      dstsize - strlen(dst) - 1 characters.  
//      It will then NUL-terminate, unless dstsize is 0 
//      or the original dst string was longer than dstsize
//      (in practice this should not happen as it means 
//      that either dstsize is incorrect or that dst is not a proper string).

//      If the src and dst strings overlap, the behavior is undefined.

// RETURN VALUES
//      Besides quibbles over the return type (size_t versus int) and signal
//      handler safety (snprintf(3) is not entirely safe on some systems), the
//      following two are equivalent:

//            n = strlcpy(dst, src, len);
//            n = snprintf(dst, len, "%s", src);

//      Like snprintf(3), the strlcpy() and strlcat() functions return the total
//      length of the string they tried to create.  For strlcpy() that means the
//      length of src.  For strlcat() that means the initial length of dst plus
//      the length of src.

//      If the return value is >= dstsize, the output string has been truncated.
//      It is the caller's responsibility to handle this.
