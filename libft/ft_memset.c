/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabu-zee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:59 by kabu-zee          #+#    #+#             */
/*   Updated: 2025/02/07 12:49:07 by kabu-zee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = s;
	while (n--)
		*p++ = c;
	return (s);
}
/*void print_buffer(const char *buffer, size_t len) {
	for (size_t i = 0; i < len; i++) {
		printf("%02x ", (unsigned char)buffer[i]);
	}
	printf("\n");
}
int	main(void) {
	char buffer[10];

	// Fill the buffer with a specific value
	ft_memset(buffer, 0xAB, sizeof(buffer));

	// Print buffer after custom memset
	printf("After my_memset: ");
	print_buffer(buffer, sizeof(buffer));

	// Comparison with standard memset
	char standard_buffer[10];
	memset(standard_buffer, 0xAB, sizeof(standard_buffer));

	// Print buffer after standard memset
	printf("After standard memset: ");
	print_buffer(standard_buffer, sizeof(standard_buffer));

	return (0);
}*/
