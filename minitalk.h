/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 06:58:34 by sel-moud          #+#    #+#             */
/*   Updated: 2024/05/18 09:31:56 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

long	ft_atoi(char *str);
void	ft_putstr(char *str);
void	send_bit(int pid, char c);
void	handler(int sig, siginfo_t *info, void *context);
void	print_pid(unsigned int pid);
char	*ft_strjoin(char *str, int c);
void	handler(int sig, siginfo_t *info, void *context);

#endif