/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 21:05:29 by lomont            #+#    #+#             */
/*   Updated: 2025/09/16 12:21:34 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(void){
	Phonebook test;

	test.FillContact(0);
	std::cout << test.array[0].firstName << std::endl;
	std::cout << test.array[0].lastName << std::endl;
	std::cout << test.array[0].Nickname << std::endl;
	std::cout << test.array[0].phoneNumber << std::endl;
	std::cout << test.array[0].darkestSecret << std::endl;
	return (0);
}
