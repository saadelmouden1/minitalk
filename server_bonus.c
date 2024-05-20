/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:30:11 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/18 09:31:59 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_pid(unsigned int pid)
{
	unsigned int	a;

	if (pid > 9)
	{
		print_pid(pid / 10);
		print_pid(pid % 10);
	}
	else
	{
		a = pid + 48;
		write(1, &a, 1);
	}
}

char	*ft_strjoin(char *str, int c)
{
	int		len;
	char	*s;
	int		i;

	len = 0;
	if (str == NULL)
	{
		len = 0;
	}
	else
		while (str[len] != '\0')
			len++;
	s = (char *)malloc(len + 2);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[len] = c;
	len++;
	s[len] = '\0';
	return (free(str), s);
}

void	freeing(char **str, int *i, char *c, int is)
{
	if (is == 1)
	{
		if (*str)
			free(*str);
		*str = NULL;
	}
	*i = 0;
	*c = 0;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pid;
	static char	*str;

	context = NULL;
	if (pid != info->si_pid)
	{
		freeing(&str, &i, &c, 1);
		pid = info->si_pid;
	}
	if (sig == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		str = ft_strjoin(str, c);
		if (c == '\0')
		{
			ft_putstr(str);
			free(str);
			kill(pid, SIGUSR1);
		}
		freeing(&str, &i, &c, 0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc == 1 && argv)
	{
		print_pid(getpid());
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		write(1, "\n", 1);
		while (1)
			pause();
	}
	return (0);
}
