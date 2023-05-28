/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqueiroz <aqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:29:17 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/04/15 15:11:19 by aqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunbr(unsigned int nbr)
{
	char	*nb;
	int		len;

	len = 0;
	nb = ft_uitoa(nbr);
	len += ft_printstr(nb);
	free(nb);
	return (len);
}
