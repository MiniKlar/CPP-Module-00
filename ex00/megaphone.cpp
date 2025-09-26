/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 01:53:29 by miniklar          #+#    #+#             */
/*   Updated: 2025/09/26 18:49:38 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ToUpper(char *s)
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
			ToUpper(argv[i]);
			std::cout << argv[i];
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
