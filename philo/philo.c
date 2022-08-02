/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:36:18 by abelahce          #+#    #+#             */
/*   Updated: 2022/08/02 17:21:24 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dormir(long long nb)
{
	long long	start;

	start = wakt ();
	// usleep((nb * 1000) * 0.95);
	while (wakt() - start < nb)
		usleep(50);
}

long long	wakt(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	printing(char	*str, t_philo *philo)
{
	pthread_mutex_lock(philo->call);
	printf("{%lld} [%d] is %s\n", wakt() - philo->start, philo->index + 1, str);
	pthread_mutex_unlock(philo->call);
}

void	eating(t_philo	*philo)
{
	pthread_mutex_lock(philo->shopsticks);
	printing("taking left shopstick", philo);
	pthread_mutex_lock(philo->rshopsticks);
	printing("taking right shopstick", philo);
	printing("eating", philo);
	dormir(philo->teat);
	pthread_mutex_unlock(philo->shopsticks);
	pthread_mutex_unlock(philo->rshopsticks);
}

void	sleeping(t_philo *philo)
{
	printing("sleeping", philo);
	dormir(philo->teat);
}

void	thinking(t_philo *philo)
{
	printing("thinking about existens", philo);
}

void	philocasting(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		philo->total++;
		if (philo->total >= philo->maxeated)
		{
			philo->asgard->samy++;
			break ;
		}
		sleeping(philo);
		thinking(philo);
	}
}

void	philosophercult(t_philo	*philo)
{
	// if (philo->index % 2)
	// 	dormir(philo->teat);
	philocasting(philo);
}

void	*philothing(void	*ptr)
{
	t_philo	*philo;

	philo = ptr;
	philosophercult(philo);
	return (NULL);
}

int	launch(t_data	*midgard, int i, int nb)
{
	while (i < nb)
	{
		if (pthread_mutex_init(&midgard->forks[i], NULL))
			return (0);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		midgard->philo[i].shopsticks = &midgard->forks[i];
		if (i == nb - 1)
			midgard->philo[i].rshopsticks = &midgard->forks[0];
		else
			midgard->philo[i].rshopsticks = &midgard->forks[i + 1];
		if (pthread_create(&midgard->th[i], NULL, &philothing, &midgard->philo[i]))
			return (0);
		usleep (500);
		i++;
	}
	return (1);
}

int	start_philo(t_data *midgard)
{
	int			i;
	int			nb;

	i = 0;
	pthread_mutex_init(&midgard->ccall, NULL);
	nb = midgard->nb_philo;
	midgard->th = malloc (sizeof(pthread_t) * midgard->nb_philo);
	if (!midgard->th)
		exit (0);
	i = 0;
	if (!launch(midgard, i, nb))
		return (free(midgard->th), 0);
	while (i < nb)
		pthread_detach(midgard->th[i++]);
	while (midgard->samy != midgard->maxeat)
	{
	}
	printf("$%d$\n", midgard->samy);
	pthread_mutex_lock(&midgard->ccall);
	printf("everyone eated #{%d}#\n", midgard->samy);
	return (1);
}
	