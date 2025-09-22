/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:37:58 by miniklar          #+#    #+#             */
/*   Updated: 2025/09/22 21:16:04 by lomont           ###   ########.fr       */
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

	for (int i = 0; i < 5; i++) {
		print_input_message(i);
		std::getline(std::cin, tmp);
		check_if_valid_input(&tmp, i);
		fill_contact_field(i, contact_index, tmp);
		tmp.clear();
	}
	return ;
}

void Phonebook::print_input_message(int i){
	switch (i) {
		case (0) :
			std::cout << "Please enter your First Name: " << std::endl;
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
	while (str->length() <= 0) {
		std::cout << "Please enter a valid input" << std::endl;
		print_input_message(i);
		std::getline(std::cin, *str);
	}
	return ;
}
