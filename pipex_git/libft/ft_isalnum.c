/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:08:29 by kdominic          #+#    #+#             */
/*   Updated: 2021/10/05 13:08:31 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int ch)
{
	if (ch >= 97 && ch <= 122)
		return (1);
	else if (ch >= 65 && ch <= 90)
		return (1);
	else if (ch >= 48 && ch <= 57)
		return (1);
	else
		return (0);
}
