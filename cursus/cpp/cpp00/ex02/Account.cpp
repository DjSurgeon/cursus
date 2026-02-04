/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:49:03 by sergio            #+#    #+#             */
/*   Updated: 2026/02/04 17:44:34 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	
}

Account::~Account( void )
{
	
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	
}

void	Account::makeDeposit( int depostit )
{

}

bool	Account::makeWithdrawal( int withdrawal )
{
	
}

int	Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{

}

void	Account::_displayTimestamp( void )
{
	std::time_t	timeNow = std::time(NULL);
	std::tm		*timestamp = std::localtime(&timeNow);
	
	std::cout	<< "["
				<< (1900 + timestamp->tm_year)
				<< std::setw(2) << std::setfill('0') << (1 + timestamp->tm_mon)
				<< std::setw(2) << std::setfill('0') << timestamp->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << timestamp->tm_hour
				<< std::setw(2) << std::setfill('0') << timestamp->tm_min
				<< std::setw(2) << std::setfill('0') << timestamp->tm_sec
				<< "] ";
}
