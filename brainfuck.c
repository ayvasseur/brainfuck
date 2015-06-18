/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayvasseur <#######@#############>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 17:30:07 by ayvasseur         #+#    #+#             */
/*   Updated: 2015/06/18 20:26:14 by ayvasseur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static char	*ft_simple_case(char *s, char *p)
{
	if (*s == '>')
		return (++p);
	else if (*s == '<')
		return (--p);
	else if (*s == '+')
	{
		++*p;
		return (p);
	}
	else if (*s == '-')
	{
		--*p;
		return (p);
	}
	else if (*s == '.')
		ft_putchar(*p);
	return (p);
}

static int	ft_analyse(char *s, char *p)
{
	int		c;

	c = 0;
	while (*s)
	{
		p = ft_simple_case(s, p);
		switch (*s)
		{
			case '[':
				if (!*p)
					while (*s)
					{
						if (*s == '[')
							c++;
						if (*s == ']')
							if (!--c)
								break ;
						s++;
					}
				break ;
			case ']':
				if (*p)
					while (*s)
					{
						if (*s == ']')
							c++;
						if (*s == '[')
							if (!--c)
								break ;
						s--;
					}
			default:
				break ;
		}
		s++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	static char		final_string[1048 + 1];

	if (argc == 2 && strlen(argv[1]) < 1048)
		ft_analyse(argv[1], final_string);
	else
		ft_putchar('\n');
	return (0);
}
