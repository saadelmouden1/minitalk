/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:29:44 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/18 09:31:39 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

long	ft_atoi(char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		i++;
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	info = NULL;
	context = NULL;
	if (sig == SIGUSR1)
		write(1, "well recieved\n", 14);
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					i;

	if (argc == 3)
	{
		i = 0;
		sa.sa_sigaction = handler;
		sigaction(SIGUSR1, &sa, NULL);
		while (argv[2][i])
			send_bit(ft_atoi(argv[1]), argv[2][i++]);
		send_bit(ft_atoi(argv[1]), '\0');
	}
	else
		write(1, "Error\n", 6);
	while (1)
		pause();
	return (0);
}
