/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:54:43 by fbruggem          #+#    #+#             */
/*   Updated: 2022/10/24 14:51:12 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*from;
	char		*to;

	i = 0;
	from = src;
	to = dst;
	if (dst == NULL && src == NULL)
		return (0);
	if (n == 0)
		return (dst);
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}
