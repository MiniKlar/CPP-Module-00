/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:45:49 by lomont            #+#    #+#             */
/*   Updated: 2025/09/24 20:25:25 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include "UI.hpp"

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string Nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact( void );
		~Contact( void );

		// Getters

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		// Setters

		void setFirstName(const std::string& name);
		void setLastName(const std::string& name);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phone);
		void setDarkestSecret(const std::string& secret);
};

class Phonebook {
	private:
		int count;
		Contact array[8];

		void fill_contact_field(const int i, int contact_index, const std::string& tmp);
		void check_if_valid_input(std::string& str, int i);
		bool check_phone_number(const std::string& str);
		bool check_name(const std::string& str);
		bool check_nickname(const std::string& str);
		bool check_secret(const std::string& str);
		int getContactsIndex(const Contact *contact);
		void printContacts(const Contact *contact, int maxWidth, int index);

	public:
		Phonebook( void );
		~Phonebook( void );
		int getCount() const;
		const Contact *getContacts() const;
		void FillContact( void );
		void display_contact(const Contact *contact);
};

#endif
