#ifndef PI_H
#define PI_H

#ifndef NUM_THREADS
#define NUM_THREADS 6
#endif 

#include <pthread.h>

typedef struct s_th
{
	struct s_pi *pi;
	int			core_n;
	long double total;
	pthread_t	th;
}				t_th;

typedef struct s_pi
{
	long double	total;
	t_th		*core;
}				t_pi;

int	ft_error(char *msg);
int	fill_struct(t_pi *pi);

#endif
