/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:36:18 by abelahce          #+#    #+#             */
/*   Updated: 2022/07/04 22:26:49 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wakt(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleeping(t_philo	*philo)
{
	long long	ok;

	ok = wakt();
	while (wakt() - ok < philo->teat)
	{
	}
}

void	routine(t_philo	*philo)
{
	while (1)
	{
		if (philo->index % 2)
			printf(" time is %d {%d} is thinking \n", wakt() - philo->start, philo->index);
		if (!philo->index % 2)
			printf(" time is %d {%d} is eating \n", wakt() - philo->start, philo->index);
		sleeping(philo);
		if (!philo->index % 2)
			printf(" time is %d {%d} is thinking \n", wakt() - philo->start, philo->index);
		if (philo->index % 2)
			printf(" time is %d {%d} is eating \n", wakt() - philo->start, philo->index);
	}
}

void	*philothing(void	*ptr)
{
	t_philo	*philo;

	philo = ptr;
	while (philo->maxeated > philo->nbeat || philo->death)
		routine(philo);
	return (NULL);
}

int	start_philo(t_data *midgard)
{
	pthread_t	*th;
	int			i;
	int			nb;

	i = 0;
	th = malloc (sizeof(pthread_t) * midgard->nb_philo);
	if (!th)
		exit (0);
	pthread_mutex_init(&midgard->bolisi, NULL);
	nb = midgard->nb_philo;
	while (i < nb)
	{
		if (pthread_create(&th[i], NULL, &philothing, &midgard->philo[i]))
			return (0);
		i++;
	}
	while (1)
	{
		if (midgard->close == 1)
			break ;
	}
	// pthread_detach(*th);
	return (1);
}
