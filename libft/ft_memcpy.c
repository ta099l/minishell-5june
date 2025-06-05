/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:59 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/02/07 12:49:07 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*des;
	const unsigned char	*sr;

	if (!dest && !src)
		return (dest);
	des = (unsigned char *)dest;
	sr = (const unsigned char *)src;
	while (n--)
		*des++ = *sr++;
	return (dest);
}
/*int main(void) {
	char src[] = "";
	char dest[50]; // Declare dest as a character array

	ft_memcpy(dest, src, sizeof(src)); // Copy src into dest

	printf("dest is: %s\n", dest); // Print the content of dest

	return (0);
}*/
