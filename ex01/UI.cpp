/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 01:40:32 by lomont            #+#    #+#             */
/*   Updated: 2025/09/26 18:47:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void PrintLogo( void ) {
	std::cout << LOGO << std::endl;
}

void ClearTerminal( void ) {
	std::cout << "\033[2J\033[1;1H";
}

void PrintInputMessage(const int i){
	switch (i) {
		case (0) :
			std::cout << "Please enter your First Name: ";
			break;
		case (1) :
			std::cout << "Please enter your Last Name: ";
			break;
		case (2) :
			std::cout << "Please enter your Nickname: " ;
			break;
		case (3) :
			std::cout << "Please enter your Phone Number: ";
			break;
		case (4) :
			std::cout << "Please enter your Darkest Secret: ";
			break;
	}
}

void PrintErrorMessage(const char *ErrorMessage, int i) {
	ClearTerminal();
	PrintLogo();
	std::cout << ErrorMessage << std::endl << std::endl;
	PrintInputMessage(i);
}

void WaitForKeyPress( void ) {
	std::string waitingKeyEnter;

	std::cout << "Please press Enter to go back home..." << std::flush;
	std::getline(std::cin, waitingKeyEnter);
}
