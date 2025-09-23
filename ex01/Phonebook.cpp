/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:37:58 by miniklar          #+#    #+#             */
/*   Updated: 2025/09/23 20:47:49 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact( void ) {
	std::cout << "Constructor contact called" << std::endl;
	this->firstName.clear();
	this->lastName.clear();
	this->Nickname.clear();
	this->darkestSecret.clear();
	this->phoneNumber.clear();
	return ;
}

Contact::~Contact( void ) {
	std::cout << "Destructor contact called" << std::endl;
	return ;
}

Phonebook::Phonebook( void ) {
	std::cout << "Constructor Phonebook called" << std::endl;
	this->count = 0;
	return ;
}

Phonebook::~Phonebook( void ) {
	std::cout << "Destructor Phonebook called" << std::endl;
	return ;
}

void Phonebook::FillContact( void ) {
	std::string tmp;

	std::cout << "\033[2J\033[1;1H"; // Efface l'écran
	for (int i = 0; i < 5; i++) {
		print_input_message(i);
		std::getline(std::cin, tmp);
		check_if_valid_input(&tmp, i);
		std::cout << "\033[2J\033[1;1H"; // Efface l'écran
		fill_contact_field(i, this->count, tmp);
		tmp.clear();
	}
	this->count++;
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
	contact_index = contact_index % 8;
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
		if (str->empty() || (i == 3 && !(this->check_phone_number(*str))) || ((i == 0 || i == 1) && !this->check_name(*str)) || (i == 2 && !this->check_nickname(*str)) || (i == 4 && !this->check_secret(*str))) {
			std::cout << "\033[2J\033[1;1H";
			std::cout << "That was not a valid input" << std::endl;
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
	int len = str.length();
	if (str[0] == '+'){
		if ((len < 4 || len > 16))
			return (false);
	}
	else if (len < 3 || len > 15)
		return (false);
	for (int i = 1; str[i]; i++) {
		if (!isdigit(static_cast<unsigned char>(str[i]))) {
			return (false);
		}
	}
	return (true);
}

bool Phonebook::check_name(std::string str) {
	int len = str.length();
	if (len < 2 || len > 50)
		return (false);
	for (int i = 0; str[i] ; i++) {
		char c = str[i];
		if (!isalpha(c))
			return (false);
	}
	return (true);
}

bool Phonebook::check_nickname(std::string str) {
	int len = str.length();
	if (len < 2 || len > 50)
		return (false);
	for (int i = 0; str[i]; i++) {
		char c = str[i];
		if (!isalnum(c))
			return (false);
	}
	return (true);
}

bool Phonebook::check_secret(std::string str) {
	int len = str.length();
	if (len > 100)
		return (false);
	return (true);
}

int Phonebook::check_contacts(Contact *contact) {
	int i = 0;
	while (i < 8) {
		if (contact[i].firstName.empty())
			break;
		i++;
	}
	return (i);
}

void Phonebook::display_contact(Contact *contact) {
	int max_width = 10;
	int index = this->check_contacts(contact);

	std::cout << std::right;
	std::cout << std::setw(10) << "Index";
	std::cout << '|' << std::setw(10) << "First Name";
	std::cout << '|' << std::setw(10) << "Last Name";
	std::cout << '|' << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < index; i++) {
		std::string first_name = contact[i].firstName;
		std::string last_name = contact[i].lastName;
		std::string nickname = contact[i].Nickname;

		if (first_name.length() > 10) {
			first_name = first_name.substr(0, max_width - 1);
			first_name = first_name + '.';
		}
		if (last_name.length() > 10) {
			last_name = last_name.substr(0, max_width - 1);
			last_name = last_name + '.';
		}
		if (nickname.length() > 10) {
			nickname = nickname.substr(0, max_width - 1);
			nickname = nickname + '.';
		}
			std::cout << std::setw(10) << i << '|';
			std::cout << std::setw(10) << first_name << '|';
			std::cout << std::setw(10) << last_name << '|';
			std::cout << std::setw(10) << nickname << std::endl;
	}
	return ;
}
