/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 05:43:40 by madorna-          #+#    #+#             */
/*   Updated: 2022/01/27 22:39:56 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

/*
** Constructor
*/

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
** Destructor
*/

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*
** Account class functions
*/

void
	Account::_displayTimestamp(void)
{
	time_t		timer;
	struct tm*	timeinfo;
	char		buffer[19];

	time(&timer);
	timeinfo = localtime(&timer);
	strftime(buffer, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}

void
	Account::makeDeposit(int deposit)
{
	int oldAmount;

	oldAmount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << oldAmount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool
	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if ((_amount - withdrawal) < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

void
	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void
	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
	<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/*
** GETTERS
*/

int
	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int
	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int
	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int
	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/*
** INITIALIZATION OF static int
*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

