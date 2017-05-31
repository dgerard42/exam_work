
void			sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				swap;
	int				done;

	i = 0;
	j = 0;
	swap = 0;
	done = 0;
	while (done == 0 && size > 1)
	{
		while ((i + 1) < (size))
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		i = 0;
		while (tab[j] <= tab[j + 1] && done == 0)
		{
			if (j + 2 == size)
				done = 1;
			j++;
		}
		j = 0;
	}
}
