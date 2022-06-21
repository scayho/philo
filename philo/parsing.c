/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:40:30 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/21 14:03:14 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(int arc, char	**arv)
{
	arc--;
	while (arc > 0)
	{
		if (ft_strlen(arv[arc]) < 1)
		{
			ft_putstr("you have an empty argument \n");
			exit (0);
		}
		if (ft_isdigit(arv[arc]) == 0)
		{
			ft_putstr("you have some lattersin your inpute my friend\n");
			exit (0);
		}
		arc--;
	}
}
