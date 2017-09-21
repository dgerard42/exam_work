
#include "brackets.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *string)
{
	int letter = 0;

	while(string[letter] != '\0')
		ft_putchar(string[letter++]);
}

void				fill_struct(t_env *env)
{
	env->curv_brac = 0;
	env->squa_brac = 0;
	env->squig_brac = 0;
}

int					brac_count(char *string)
{
	t_env	env;
	int		letter;
	int		type[420];
	int		layer;

	letter = 0;
	layer = 0;
	fill_struct(&env);
	while (string[letter] != '\0')
	{
		if (string[letter] == '(')
		{
			env.curv_brac++;
			layer++;
			type[layer] = 1;
		}
		if (string[letter] == '[')
		{
			env.squa_brac++;
			layer++;
			type[layer] = 2;
		}
		if (string[letter] == '{')
		{
			env.squig_brac++;
			layer++;
			type[layer] = 3;
		}
		if(string[letter] == ')')
		{
			env.curv_brac--;
			if (type[layer] != 1)
				return (0);
			else if(type[layer] == 1)
				layer--;
		}	
		if(string[letter] == ']')
		{
			env.squa_brac--;
			if (type[layer] != 2)
				return (0);
			else if(type[layer] == 2)
				layer--;
		}	
		if(string[letter] == '}')
		{
			env.squig_brac--;
			if (type[layer] != 3)
				return (0);
			else if(type[layer] == 3)
				layer--;
		}
	   letter++;	
	}
	if (env.curv_brac == 0 && env.squa_brac == 0 && env.squig_brac == 0)
		return (1);
	else
		return (0);
}

int					main(int argc, char **argv)
{
	int	correct;
	int	param;

	correct = 0;
	param = 1;
	while (param < argc)
	{
		correct = brac_count(argv[param]);
		if (correct == 1)
			ft_putstr("OK\n");
		if (correct == 0)
			ft_putstr("Error\n");
		param++;
	}
	if (argc <= 1)
		ft_putchar('\n');
}
