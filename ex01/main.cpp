/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:05:29 by lomont            #+#    #+#             */
/*   Updated: 2025/09/23 20:36:29 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(void){
	Phonebook book;
	std::string command;

	std::cout << "Please enter a command: " << std::endl << "- ADD" << std::endl << "- SEARCH" << std::endl << "- EXIT" << std::endl;
	while (1) {
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0) {
			book.FillContact();
		}
		else if (command.compare("SEARCH") == 0)
			book.display_contact(book.array);
		else if (command.compare("EXIT") == 0)
			return 0;
		else {
			std::cout << "Command invalid. Please used 'ADD', 'SEARCH, or 'EXIT' to navigate the Phonebook" << std::endl;
		}
	}
	// std::cout << book.array[0].firstName << std::endl;
	// std::cout << book.array[0].lastName << std::endl;
	// std::cout << book.array[0].Nickname << std::endl;
	// std::cout << book.array[0].phoneNumber << std::endl;
	// std::cout << book.array[0].darkestSecret << std::endl;
	return (0);
}
