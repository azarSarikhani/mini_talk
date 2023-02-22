/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:23:27 by asarikha          #+#    #+#             */
/*   Updated: 2022/11/04 11:05:31 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest_str;
	char	*src_str;

	dest_str = (char *)(dst);
	src_str = (char *)(src);
	if (!dst && !src)
		return ((void *)0);
	if (dst >= src)
		while (len-- > 0)
			dest_str[len] = src_str[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
