/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:39:49 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/21 14:11:24 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_data	midgard;

	if (arc > 6 || arc < 5)
	{
		ft_putstr(" my briend lemme thinking am i a philosopher \n");
		exit(0);
	}
	parsing(arc, arv);
	midgard.nb_philo = ft_atoi(arv[1]);
	midgard.tdie = ft_atoi(arv[2]);
	midgard.teat = ft_atoi(arv[3]);
	midgard.tsleep = ft_atoi(arv[4]);
	midgard.nbeat = 0;
	if (arc == 6)
		midgard.nbeat = ft_atoi(arv[5]);
	printf("{%d} \n", gettimeofday());
	return (0);
}
