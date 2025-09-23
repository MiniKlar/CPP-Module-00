/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:45:49 by lomont            #+#    #+#             */
/*   Updated: 2025/09/23 02:36:00 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>

class Contact {
	public:
		std::string firstName;
		std::string lastName;
		std::string Nickname;
		std::string phoneNumber;
		std::string darkestSecret;

		Contact( void );
		~Contact( void );
};

class Phonebook {
	public:
		Contact array[8];
		Phonebook( void );
		~Phonebook( void );
		void FillContact( int contact_index );
		void print_input_message (int i);
		void fill_contact_field(int i, int contact_index, std::string tmp);
		void check_if_valid_input(std::string *str, int i);
		bool check_phone_number(std::string str);
};

#endif
