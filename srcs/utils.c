#include "../includes/pi.h"
#include <stdio.h>
#include <stdlib.h>

int ft_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

int	fill_struct(t_pi *pi)
{
	int i;

	i = -1;
	pi->total = 0;
	pi->core = (t_th *)malloc(sizeof(t_th) * NUM_THREADS);
	if (!pi->core)
		return (1);
	while (++i < NUM_THREADS)
	{
		pi->core[i].pi = pi;
		pi->core[i].core_n = i;
		pi->core[i].total = 0;
	}
	return (0);
}
