/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:45:49 by lomont            #+#    #+#             */
/*   Updated: 2025/09/26 18:50:43 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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

		std::string GetFirstName() const;
		std::string GetLastName() const;
		std::string GetNickname() const;
		std::string GetPhoneNumber() const;
		std::string GetDarkestSecret() const;
		// Setters

		void SetFirstName(const std::string& name);
		void SetLastName(const std::string& name);
		void SetNickname(const std::string& nickname);
		void SetPhoneNumber(const std::string& phone);
		void SetDarkestSecret(const std::string& secret);
};

class Phonebook {
	private:
		int count;
		Contact array[8];

		void FillContactField(const int i, int contact_index, const std::string& tmp);
		void CheckIfValidInput(std::string& str, int i);
		bool CheckPhoneNumber(const std::string& str);
		bool CheckName(const std::string& str);
		bool CheckNickname(const std::string& str);
		bool CheckSecret(const std::string& str);
		int GetContactsIndex(const Contact *contact);
		void PrintContacts(const Contact *contact, int maxWidth, int index);

	public:
		Phonebook( void );
		~Phonebook( void );
		int GetCount() const;
		const Contact *GetContacts() const;
		void FillContact( void );
		void DisplayContact(const Contact *contact);
};

#endif
