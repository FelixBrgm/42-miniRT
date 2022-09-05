/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvznuzda <pashavznuzdajev@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:41 by fbruggem          #+#    #+#             */
/*   Updated: 2022/09/05 16:34:06 by pvznuzda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	del_ptr(void **ptr, int n);
// if (ft_protect(3, p1, p2, p3));
int	ft_protect(int n, ...)
{
	va_list	list;
	void	**ptr;
	int		i;

	ptr = ft_calloc(n, sizeof(void *));
	if (!ptr)
		return (-1);
	va_start(list, n);
	i = 0;
	while (i < n)
		ptr[i++] = va_arg(list, void *);
	va_end(list);
	i = 0;
	while (i < n)
		if (!ptr[i++])
			return (del_ptr(ptr, n));
	free(ptr);
	return (0);
}

int	del_ptr(void **ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(ptr[i++]);
	free(ptr);
	return (-1);
}
