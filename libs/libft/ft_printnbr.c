/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:13:17 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/15 15:11:13 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	char	*nb;
	int		len;

	len = 0;
	nb = ft_itoa(nbr);
	len += ft_printstr(nb);
	free(nb);
	return (len);
}
