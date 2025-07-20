/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:53:29 by miniklar          #+#    #+#             */
/*   Updated: 2025/07/20 23:59:31 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ft_toUpper(char *s)
{
	int i = 0;

	while (s[i])
	{
		s[i] = toupper(s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;

		while (i < argc)
		{
			ft_toUpper(argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
