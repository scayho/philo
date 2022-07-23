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

void	dormir(long long	nb)
{
	long long start;
	long long end;

	start = wakt ();
	end = wakt();
	while (end - start < nb)
	{
		end = wakt();
	}
}

long long	wakt(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	printing(char	*str, t_philo *philo)
{
	pthread_mutex_lock(&philo->call);	
	printf("{%lld} [%d] is %s\n", wakt() - philo->start, philo->index, str);
	pthread_mutex_unlock(&philo->call);
}

void	eating(t_philo	*philo)
{
	pthread_mutex_lock(&(philo->shopsticks));
	printing("ticking right shopstick", philo);
	pthread_mutex_lock(&(philo->rshopsticks));
	printing("ticking left shopstick", philo);
	printing("eating", philo);
	dormir(philo->teat);
	pthread_mutex_unlock(&(philo->shopsticks));
	pthread_mutex_unlock(&(philo->rshopsticks));
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
		sleeping(philo);
		thinking(philo);
	}
}

void	philosophercult(t_philo	*philo)
{
	if (!philo->index % 2)
		sleeping(philo);
	philocasting(philo);
}

void	*philothing(void	*ptr)
{
	t_philo	*philo;

	philo = ptr;
	philosophercult(philo);
	return (NULL);
}

int	start_philo(t_data *midgard)
{
	int			i;
	int			nb;

	i = 0;
	pthread_mutex_init(&midgard->call, NULL);
	nb = midgard->nb_philo;
	midgard->th = malloc (sizeof(pthread_t) * midgard->nb_philo);
	if (!midgard->th)
		exit (0);
	while (i < nb)
	{
		pthread_mutex_init(&midgard->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		midgard->philo[i].shopsticks = midgard->forks[i];
		midgard->philo[i].rshopsticks = midgard->forks[i + 1];
		if (i == nb - 1)
			midgard->philo[i].rshopsticks = midgard->forks[0];
		if (pthread_create(&midgard->th[i], NULL, &philothing, &midgard->philo[i]))
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
