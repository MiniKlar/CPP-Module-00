/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 01:40:32 by lomont            #+#    #+#             */
/*   Updated: 2025/09/24 02:17:51 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void printLogo( void ) {
	std::cout << LOGO << std::endl;
}

void clearTerminal( void ) {
	std::cout << "\033[2J\033[1;1H";
}
