#include "../includes/pi.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static void *GLSerie(void *arg)
{
	int i;
	t_th *th;

	th = (t_th *)arg;

	(void) i;
	printf("Hi, Im thread %d\n", th->core_n);
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
	while (++i < NUM_THREADS)
		if (pthread_join(pi.core[i].th, NULL))
			return (ft_error("error joining theads"));

	return (0);
}
/*
int main()
{
	long i = -1;
	long double pi;
	long double inf;
	long caqui = 1;


	while (++i < 1000000000000)
	{
		if (i % 2 == 0)
			inf += 1.0/caqui;
		else
			inf -= 1.0/caqui;
		caqui += 2;
	}
 	pi = inf * 4;
	printf("%Lf\n", pi);
	return (0);
}*/
