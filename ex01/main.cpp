/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:05:29 by lomont            #+#    #+#             */
/*   Updated: 2025/09/26 18:47:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void){
	Phonebook book;
	std::string command;
	std::string ErrorMessage = "";

	while (1) {
		PrintLogo();
		if (!ErrorMessage.empty())
		{
			std::cout << "!! " << ErrorMessage << " !!" << std::endl << std::endl;
			ErrorMessage.clear();
		}
		std::cout << "Please enter a command (ADD, SEARCH or EXIT) " << ": ";
		if (!std::getline(std::cin, command)) {
			ClearTerminal();
			break;
		}
		else if (command.empty()) {
			ClearTerminal();
			continue;
		}
		else if (command.compare("ADD") == 0) {
			book.FillContact();
		}
		else if (command.compare("SEARCH") == 0) {
			if (book.GetCount() > 0)
				book.DisplayContact(book.GetContacts());
			else {
				ClearTerminal();
				ErrorMessage = "You can't search into a Phonebook empty, please ADD a contact!";
			}
		}
		else if (command.compare("EXIT") == 0)
			return 0;
		else {
			ClearTerminal();
			ErrorMessage = "Command invalid. Please used 'ADD', 'SEARCH, or 'EXIT' to navigate the Phonebook";
		}
	}
	return (0);
}
