/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:59:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/18 16:13:11 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << BOLD_ON GREEN << "Default constructor called" << RESET <<std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other.getRawBits()) {
	std::cout << BOLD_ON YELLOW << "Copy constructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << BOLD_ON << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << BOLD_ON RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void )const {
	std::cout << BOLD_ON << "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	std::cout << BOLD_ON << "setRawBits member function called" << RESET << std::endl;

	this->_value = raw;
}