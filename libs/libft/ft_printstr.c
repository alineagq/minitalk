/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:05:20 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/15 15:11:16 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		len += write(1, "(null)", 6);
	else
	{
		while (*str)
		{
			len += write(1, &(*str), 1);
			str++;
		}
	}
	return (len);
}
