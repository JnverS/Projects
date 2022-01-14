/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdominic <kdominic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:42:31 by kdominic          #+#    #+#             */
/*   Updated: 2022/01/10 16:28:31 by kdominic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_dubl(char **argv)
{
	int	i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(i > j)
		{
			if (!ft_strcmp(argv[j], argv[i]) && i != j)
			{
				write(2, "SAME ELEMENT!\n", 14);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	validation(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+') && argv[i][j + 1] != 0)
			j++;
		while(argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "Not valid args\n", 15);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	check_dubl(argv);
}