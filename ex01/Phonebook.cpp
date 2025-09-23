/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:37:58 by miniklar          #+#    #+#             */
/*   Updated: 2025/09/23 02:53:15 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact( void ) {
	std::cout << "Constructor contact called" << std::endl;
	this->firstName = '\0';
	this->lastName = '\0';
	this->Nickname = '\0';
	this->darkestSecret = '\0';
	this->phoneNumber = '\0';
	return ;
}

Contact::~Contact( void ) {
	std::cout << "Destructor contact called" << std::endl;
	return ;
}

Phonebook::Phonebook( void ) {
	std::cout << "Constructor Phonebook called" << std::endl;
	return ;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Destructor Phonebook called" << std::endl;
	return ;
}

void Phonebook::FillContact(int contact_index) {
	std::string tmp;

	std::cout << "\033[2J\033[1;1H"; // Efface l'écran
	for (int i = 0; i < 5; i++) {
		print_input_message(i);
		std::getline(std::cin, tmp);
		check_if_valid_input(&tmp, i);
		std::cout << "\033[2J\033[1;1H"; // Efface l'écran
		fill_contact_field(i, contact_index, tmp);
		tmp.clear();
	}
	return ;
}

void Phonebook::print_input_message(int i){
	switch (i) {
		case (0) :
			std::cout << "Please enter your First Name: " << std::endl << std::flush;
			break;
		case (1) :
			std::cout << "Please enter your Last Name: " << std::endl;
			break;
		case (2) :
			std::cout << "Please enter your Nickname: " << std::endl;
			break;
		case (3) :
			std::cout << "Please enter your Phone Number: " << std::endl;
			break;
		case (4) :
			std::cout << "Please enter your Darkest Secret" << std::endl;
			break;
	}
}

void Phonebook::fill_contact_field(int i, int contact_index, std::string str) {
	switch (i) {
		case 0:
			this->array[contact_index].firstName = str;
			break;
		case 1:
			this->array[contact_index].lastName = str;
			break;
		case 2:
			this->array[contact_index].Nickname = str;
			break;
		case 3:
			this->array[contact_index].phoneNumber = str;
			break;
		case 4:
			this->array[contact_index].darkestSecret = str;
			break;
	}
}

void Phonebook::check_if_valid_input(std::string *str, int i) {
	while (true) {
		if (str->empty() || (i == 3 && !(this->check_phone_number(*str)))) {
			std::cout << "Please enter a valid input" << std::endl;
			print_input_message(i);
			std::getline(std::cin, *str);
		}
		else
			break;
	}
	return ;
}

bool Phonebook::check_phone_number(std::string str) {
	if (str[0] != '+' && !isdigit(static_cast<unsigned char>(str[0])))
		return (false);
	if (!(str.length() > 1))
		return (false);
	for (int i = 1; str[i]; i++) {
		if (!isdigit(static_cast<unsigned char>(str[i]))) {
			return (false);
		}
	}
	return (true);
}
