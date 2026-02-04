/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:49:03 by sergio            #+#    #+#             */
/*   Updated: 2026/02/04 22:41:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// --- Static Member Initialization ---
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// --- Constructor & Destructor ---
/// @brief Constructor. Creates a new account with an initial deposit.
/// @param initial_deposit The starting amount for this account.
Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals (0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

/// @brief Destructor. Closes the account.
Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
}

// --- Static Getters ---
/// @brief Gets the total number of accounts.
/// @return The static counter _nbAccounts.
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

/// @brief Gets the total money in the bank.
/// @return The static counter _totalAmount.
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

/// @brief Gets the total number of deposits made.
/// @return The static counter _totalNbDeposits.
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

/// @brief Gets the total number of withdrawals made.
/// @return The static counter _totalNbWithdrawals.
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

// --- Global Display Function ---
/// @brief Displays the general information of the bank (totals).
/// Format: accounts:X;total:Y;deposits:Z;withdrawals:W
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

// --- Member Functions ---
/// @brief Processes a deposit into the account.
/// @param deposit The amount to be deposited.
void	Account::makeDeposit( int deposit )
{
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

/// @brief Attempts to withdraw money from the account.
/// @param withdrawal The amount to withdraw.
/// @return true if withdrawal was successful, false if refused.
bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout	<< "index:" << _accountIndex
					<< ";p_amount:" << p_amount
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

/// @brief Checks the current amount in the account.
/// @return The current balance (_amount).
int	Account::checkAmount( void ) const
{
	return(_amount);
}

/// @brief Displays the status of the current instance (account).
/// Format: index:X;amount:Y;deposits:Z;withdrawals:W
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

// --- Private Helper ---
/// @brief Prints the current timestamp to cout.
/// Format: [YYYYMMDD_HHMMSS] followed by a space.
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
