/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:05:29 by lomont            #+#    #+#             */
/*   Updated: 2025/09/24 02:23:44 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void){
	Phonebook book;
	std::string command;
	std::string errorMessage = "";

	while (1) {
		printLogo();
		if (!errorMessage.empty())
		{
			std::cout << "!! " << errorMessage << " !!" << std::endl << std::endl;
			errorMessage.clear();
		}
		std::cout << "Please enter a command (ADD, SEARCH or EXIT) " << ": ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0) {
			book.FillContact();
		}
		else if (command.compare("SEARCH") == 0) {
			if (book.count > 0)
				book.display_contact(book.array);
			else {
				clearTerminal();
				errorMessage = "You can't search into a Phonebook empty, please ADD a contact!";
			}
		}
		else if (command.compare("EXIT") == 0)
			return 0;
		else {
			clearTerminal();
			errorMessage = "Command invalid. Please used 'ADD', 'SEARCH, or 'EXIT' to navigate the Phonebook";
		}
	}
	return (0);
}
