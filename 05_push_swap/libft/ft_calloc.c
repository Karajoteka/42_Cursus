/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aorcha-m <aorcha-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:02:54 by agu               #+#    #+#             */
/*   Updated: 2023/11/27 16:08:11 by aorcha-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates memory for an array of nmemb elements of size bytes each and 
 *returns a pointer to the allocated memory. The memory is set to zero. If nmemb
 *or size is 0, then calloc() returns either NULL,or a unique pointer value that 
 *can later be successfully passed to free(). */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total_size;
	void	*memory_block;

	total_size = nelem * elsize;
	memory_block = malloc(total_size);
	if (!memory_block)
		return (NULL);
	ft_bzero(memory_block, total_size);
	return (memory_block);
}
