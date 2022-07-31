/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:40:30 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/30 03:44:26 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	atoing(t_data *midgard, char **arv, int i)
{
	midgard->nb_philo = ft_atoi(arv[1]);
	midgard->tdie = ft_atoi(arv[2]);
	midgard->teat = ft_atoi(arv[3]);
	midgard->tsleep = ft_atoi(arv[4]);
	midgard->nbeat = 0;
	midgard->maxeat = 0;
	midgard->death = 1;
	if (i == 6)
		midgard->maxeat = ft_atoi(arv[5]);
}

void	indexing(t_data	*midgard)
{
	int	i;

	i = 0;
	while (i < midgard->nb_philo)
	{
		midgard->philo[i].index = i;
		midgard->philo[i].teat = midgard->teat;
		midgard->philo[i].nbeat = midgard->nbeat;
		midgard->philo[i].death = midgard->death;
		midgard->philo[i].maxeated = midgard->maxeat;
		midgard->philo[i].eated = wakt();
		midgard->philo[i].start = wakt();
		midgard->philo[i].total = 0;
		midgard->philo[i].call = &(midgard->ccall);
		i++;
	}
}

int	parsing(int arc, char	**arv, t_data *midgard)
{
	int i;

	i = arc;
	arc--;
	while (arc > 0)
	{
		if (ft_strlen(arv[arc]) < 1)
		{
			ft_putstr("you have an empty argument \n");
			return (0);
		}
		if (ft_isdigit(arv[arc]) == 0)
		{
			ft_putstr("you have some latters in your inpute my friend\n");
			return (0);
		}
		arc--;
	}
	if (ft_atoi(arv[1]) < 0 || ft_atoi(arv[1]) < 0 || ft_atoi(arv[1]) < 0
		|| ft_atoi(arv[1]) < 0)
		return (0);
	midgard->forks = malloc (sizeof(pthread_mutex_t) * ft_atoi(arv[1]));
	if (!midgard->forks)
		return (0);
	midgard->philo = malloc (sizeof (t_philo) * atoi(arv[1]));
	if (!midgard->philo)
		return (0);
	atoing(midgard, arv, i);
	indexing(midgard);
	return (1);
}
