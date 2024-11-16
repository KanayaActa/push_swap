/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miwasa <miwasa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:28:02 by miwasa            #+#    #+#             */
/*   Updated: 2024/11/15 20:26:19 by miwasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static size_t	ft_split_count(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == ' ')
			s++;
		if (!*s)
			break ;
		count++;
		while (*s && *s != ' ')
			s++;
	}
	return (count);
}

static int	find_next_token(const char **s, char **start)
{
	while (**s && **s == ' ')
		(*s)++;
	if (!**s)
		return (0);
	*start = (char *)*s;
	while (**s && **s != ' ')
		(*s)++;
	return (1);
}

int	main(int argc, char **argv)
{
	char		*start;
	char		*program_name;
	const char	*s = argv[1];
	int			i;

	if (argc == 2)
	{
		program_name = argv[0];
		argc = ft_split_count(s) + 1;
		argv = __builtin_alloca((argc) * sizeof(char *));
		ft_memset(argv, 0, (argc) * sizeof(char *));
		argv[0] = program_name;
		i = 1;
		while (*s && i < argc)
		{
			if (!find_next_token(&s, &start))
				break ;
			argv[i] = __builtin_alloca(s - start + 1);
			ft_memcpy(argv[i], start, s - start);
			argv[i++][s - start] = '\0';
		}
		argv[i] = NULL;
	}
	return (push_swap(argc, argv));
}
