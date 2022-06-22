/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:40:30 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/22 15:08:01 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int arc, char	**arv, t_data *midgard)
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
			ft_putstr("you have some latters in your inpute my friend\n");
			exit (0);
		}
		arc--;
	}
	if (ft_atoi(arv[1]) < 0 || ft_atoi(arv[1]) < 0 || ft_atoi(arv[1]) < 0
	|| ft_atoi(arv[1]) < 0)
	return (0);
	midgard->nb_philo = ft_atoi(arv[1]);
	midgard->tdie = ft_atoi(arv[2]);
	midgard->teat = ft_atoi(arv[3]);
	midgard->tsleep = ft_atoi(arv[4]);
	midgard->nbeat = 0;
	if (arc == 6)
		midgard->nbeat = ft_atoi(arv[5]);
}
