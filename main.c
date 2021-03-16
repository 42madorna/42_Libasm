/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:45:31 by madorna-          #+#    #+#             */
/*   Updated: 2021/03/10 23:59:50 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <libc.h>

int		main()
{
	char dst[100] = "";
	char dst2[100] = "";
	char hola[] = "Hola, que tal";
	printf("%ld\n", ft_strlen(hola));
	printf("%ld\n", strlen(hola));
	printf("%s\n", ft_strcpy(dst, hola));
	printf("%s\n", strcpy(dst2, hola));
}