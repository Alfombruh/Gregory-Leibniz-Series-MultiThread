#include "../includes/pi.h"
#include <pthread.h>
#include <stdio.h>

static void *GLSerie(void *arg)
{
	long long i;
	t_th *th;

	th = (t_th *)arg;
	i = th->core_n;
	while(i < 1000000000)
	{
		if (i % 2 == 0)
			th->total += 1.00000000 / (2.00000000* i + 1.00000000000);
		else
			th->total -= 1.00000000 / (2.00000000 * i + 1.0000000000);
		i += NUM_THREADS;
	}
	return NULL;
}

int main()
{
	t_pi	pi;
	int		i;

	i = -1;
	if (fill_struct(&pi))
		return (ft_error("struct filling error"));
	while (++i < NUM_THREADS)
		if (pthread_create(&pi.core[i].th, NULL, GLSerie, &pi.core[i]))
			return (ft_error("error creating threads"));
	i = -1;
	while (++i < NUM_THREADS)
		if (pthread_join(pi.core[i].th, NULL))
			return (ft_error("error joining theads"));
	i = -1;
	while (++i < NUM_THREADS)
		pi.total += pi.core[i].total;
	pi.total *= 4.0;
	printf("%0.10LF\n", pi.total);
	return (0);
}
