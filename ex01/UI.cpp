/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 01:40:32 by lomont            #+#    #+#             */
/*   Updated: 2025/09/24 20:50:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void printLogo( void ) {
	std::cout << LOGO << std::endl;
}

void clearTerminal( void ) {
	std::cout << "\033[2J\033[1;1H";
}

void print_input_message(const int i){
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

void printErrorMessage(const char *errorMessage, int i) {
	clearTerminal();
	printLogo();
	std::cout << errorMessage << std::endl << std::endl;
	print_input_message(i);
}

void waitForKeyPress( void ) {
	std::string waitingKeyEnter;

	std::cout << "Please press Enter to go back home..." << std::flush;
	std::getline(std::cin, waitingKeyEnter);
	//std::cin.get();
	// std::cin.clear();
	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
