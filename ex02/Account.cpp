/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 04:16:36 by lomont            #+#    #+#             */
/*   Updated: 2025/09/26 18:14:44 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ) {
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_amount += initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
	return ;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	return ;
}

int Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
	return ;
}

void Account::makeDeposit( int deposit ) {
	int	tmp_amount;

	tmp_amount = _amount;
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << tmp_amount << ";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << _nbDeposits << std::endl;
	return ;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int	tmp_amount;
	int new_amount;

	tmp_amount = checkAmount();
	new_amount = checkAmount() - withdrawal;
	if (new_amount < 0) {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << tmp_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << tmp_amount << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}

}

int Account::checkAmount( void ) const {
	return (_amount);
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

void Account::_displayTimestamp( void ) {
	std::time_t	timeNow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct std::tm* ptm = std::localtime(&timeNow);
	std::cout << '[' << std::put_time(ptm, "%G%m%d_%I%M%S") << ']';
	return ;
}

