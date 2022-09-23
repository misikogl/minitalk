/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:54:59 by misikogl          #+#    #+#             */
/*   Updated: 2022/06/25 21:43:18 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int	ft_atoi(char *str)
{
	int	number;

	number = 0;
	while (*str)
		number = (10 * number) + (*str++ - 48);
	return (number);
}

void	sender(int *message, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message[i] == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				printf ("SIGUSR1 FAILED");
		}
		else if (message[i] == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				printf ("SIGUSR2 FAILED");
		}
		i++;
		usleep(50);
	}
	free(message);
}

int	*encoder(char c)
{
	int	*coded_char;
	int	char_to_bit;
	int	i;

	coded_char = malloc(sizeof(*coded_char) * 8);
	char_to_bit = (int)c;
	i = 7;
	while (char_to_bit)
	{
		coded_char[i] = char_to_bit % 2;
		char_to_bit /= 2;
		i--;
	}
	return (coded_char);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;
	int	*message;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			message = encoder(argv[2][i]);
			sender(message, pid);
			i++;
		}
	}
	else
		write (1, "ERROR: ./a.out (Server PID) ('MESSAGE')", 39);
}
