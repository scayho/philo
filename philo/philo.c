/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:36:18 by abelahce          #+#    #+#             */
/*   Updated: 2022/06/23 15:34:52 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wakt(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
}

void	*philothing(void	*arg)
{
	int			i;
	static int	j;

	i = 0;
	(void)arg;
	printf("j = {%d}", ++j);
	while (i < 200)
	{
		printf("[%d]	", i);
		i++;
	}
	printf("\n");
	i++;
	return (NULL);
}

void	start_philo(t_data *midgard)
{
	pthread_t	th;
	int			i;

	i = 0;
	while (i < midgard->nb_philo)
	{
		pthread_create(&th, NULL, philothing, NULL);
		sleep(1);
		i++;
	}
}
