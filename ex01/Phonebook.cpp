/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 00:37:58 by miniklar          #+#    #+#             */
/*   Updated: 2025/09/26 18:47:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Contact::Contact( void ) {
	return ;
}

Contact::~Contact( void ) {
	return ;
}

Phonebook::Phonebook( void ) : count(0) {
	ClearTerminal();
	return ;
}

Phonebook::~Phonebook( void ) {
	ClearTerminal();
	std::cout << "Phonebook closed!" << std::endl;
	return ;
}

//Setters

void Contact::SetFirstName(const std::string& name) {
	this->firstName = name;
	return ;
}

void Contact::SetLastName(const std::string& name) {
	this->lastName = name;
	return ;
}

void Contact::SetNickname(const std::string& nickname) {
	this->Nickname = nickname;
	return ;
}

void Contact::SetPhoneNumber(const std::string& phone) {
	this->phoneNumber = phone;
	return ;
}

void Contact::SetDarkestSecret(const std::string& secret) {
	this->darkestSecret = secret;
	return ;
}

// Getters

std::string Contact::GetFirstName() const {
	return (this->firstName);
}

std::string Contact::GetLastName() const {
	return (this->lastName);
}

std::string Contact::GetNickname() const {
	return (this->Nickname);
}

std::string Contact::GetPhoneNumber() const {
	return (this->phoneNumber);
}

std::string Contact::GetDarkestSecret() const {
	return (this->darkestSecret);
}

int Phonebook::GetCount() const {
	return (this->count);
}

const Contact *Phonebook::GetContacts() const {
	return (this->array);
}

//Functions

void Phonebook::FillContact( void ) {
	std::string tmp;

	ClearTerminal();
	for (int i = 0; i < 5; i++) {
		PrintLogo();
		PrintInputMessage(i);
		std::getline(std::cin, tmp);
		CheckIfValidInput(tmp, i);
		ClearTerminal();
		FillContactField(i, this->count, tmp);
		tmp.clear();
	}
	this->count++;
	return ;
}

void Phonebook::FillContactField(int i, int contact_index, const std::string& str) {
	contact_index = contact_index % 8;
	switch (i) {
		case 0:
			this->array[contact_index].SetFirstName(str);
			break;
		case 1:
			this->array[contact_index].SetLastName(str);
			break;
		case 2:
			this->array[contact_index].SetNickname(str);
			break;
		case 3:
			this->array[contact_index].SetPhoneNumber(str);
			break;
		case 4:
			this->array[contact_index].SetDarkestSecret(str);
			break;
	}
}

void Phonebook::CheckIfValidInput(std::string& str, int i) {
	while (true) {
		if (str.empty())
			PrintErrorMessage("Empty input, please re-enter your input", i);
		else if ((i == 0 || i == 1) && !this->CheckName(str)) {
			PrintErrorMessage("Wrong input, please choose a name between 2 and 50 characters without numbers & special characters!", i);
		}
		else if (i == 3 && !(this->CheckPhoneNumber(str))) {
			PrintErrorMessage("Wrong input, please choose a phone number at least 3 numbers long and 15 numbers maximum without indicator!", i);
		}
		else if (i == 2 && !this->CheckNickname(str)) {
			PrintErrorMessage("Wrong input, please choose a nickname between 2 and 50 characters withotu special characters!", i);
		}
		else if (i == 4 && !this->CheckSecret(str)) {
			PrintErrorMessage("Wrong input, your darkest secret should not be >100 characters long!", i);
		}
		else
			break;
		if (!std::getline(std::cin, str)) {
			ClearTerminal();
			return ;
		}
	}
	return ;
}

bool Phonebook::CheckPhoneNumber(const std::string& str) {
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

bool Phonebook::CheckName(const std::string& str) {
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

bool Phonebook::CheckNickname(const std::string& str) {
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

bool Phonebook::CheckSecret(const std::string& str) {
	int len = str.length();
	if (len > 100)
		return (false);
	return (true);
}

int Phonebook::GetContactsIndex(const Contact *contact) {
	int i = 0;
	while (i < 8) {
		if (contact[i].GetFirstName().empty())
			break;
		i++;
	}
	return (i);
}

void Phonebook::PrintContacts(const Contact *contact, int maxWidth, int index) {
	ClearTerminal();
	PrintLogo();
	std::cout << std::right;
	std::cout << std::setw(10) << "Index";
	std::cout << '|' << std::setw(10) << "First Name";
	std::cout << '|' << std::setw(10) << "Last Name";
	std::cout << '|' << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < index; i++) {
		std::string first_name = contact[i].GetFirstName();
		std::string last_name = contact[i].GetLastName();
		std::string nickname = contact[i].GetNickname();

		if (first_name.length() > 10) {
			first_name = first_name.substr(0, maxWidth - 1);
			first_name = first_name + '.';
		}
		if (last_name.length() > 10) {
			last_name = last_name.substr(0, maxWidth - 1);
			last_name = last_name + '.';
		}
		if (nickname.length() > 10) {
			nickname = nickname.substr(0, maxWidth - 1);
			nickname = nickname + '.';
		}
			std::cout << std::setw(10) << i + 1 << '|';
			std::cout << std::setw(10) << first_name << '|';
			std::cout << std::setw(10) << last_name << '|';
			std::cout << std::setw(10) << nickname << std::endl;
	}
}

void Phonebook::DisplayContact(const Contact *contact) {
	int max_width = 10;
	int index = this->GetContactsIndex(contact);
	bool wrong_input = false;
	int index_choosen = 0;
	std::string str = "";

	while (1)
	{
		PrintContacts(contact, max_width, index);
		if (wrong_input)
		{
			std::cout << std::endl << "Wrong input!" << std::endl;
			wrong_input = false;
		}
		std::cout << std::endl << "Please choose an existing index to display the contact information: ";
		if (!std::getline(std::cin, str)){
			ClearTerminal();
			return;
		}
		else if (str.empty()) {
			wrong_input = true;
			continue;
		}
		for (int i = 0; str[i]; i++) {
			if (isdigit(str[i]) == 0)
			{
				wrong_input = true;
				break;
			}
		}
		if (wrong_input)
			continue;
		index_choosen = std::stoi(str);
		if (index_choosen <= index && index_choosen != 0) {
			ClearTerminal();
			break;
		}
		else
			wrong_input = true;
	}
	PrintLogo();
	std::cout << "First Name: " << this->array[index_choosen - 1].GetFirstName()<< std::endl;
	std::cout << "Last Name: " << this->array[index_choosen - 1].GetLastName() << std::endl;
	std::cout << "Nickname: " << this->array[index_choosen - 1].GetNickname() << std::endl;
	std::cout << "Phone Number: " << this->array[index_choosen - 1].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->array[index_choosen - 1].GetDarkestSecret() << std::endl << std::endl;
	WaitForKeyPress();
	ClearTerminal();
	return ;
}
