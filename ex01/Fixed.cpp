/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:31:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/21 13:15:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _value(0) {
	
	std::cout << BOLD_ON GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int integer) {
	
	std::cout << BOLD_ON YELLOW<< "Integer constructor called" << RESET << std::endl;
	if (integer > (INT_MAX >> this->_nbBits) || integer < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON RED << "Overflow detected" << RESET << std::endl;
	this->_value = integer << this->_nbBits;
}

Fixed::Fixed(const float floater) {
	
	std::cout << BOLD_ON BLUE << "Float constructor called" << RESET << std::endl;
	int intPart = (int)roundf(floater);
	if (intPart > (INT_MAX >> this->_nbBits) || intPart < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON << RED << "Overflow detected" << RESET << std::endl;
	this->_value = (int)roundf(floater * (1 << this->_nbBits));
}

Fixed &Fixed::operator=(const Fixed &other) {
	
	std::cout << BOLD_ON << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
	
	std::cout << BOLD_ON << "Copy constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	
	std::cout << BOLD_ON RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void )const {
	// std::cout << BOLD_ON << "getRawBits member function called" << RESET << std::endl;
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	// std::cout << BOLD_ON << "setRawBits member function called" << RESET << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat( void )const {
	
	if(this->_value > FLT_MAX || this->_value < FLT_MIN)
	{
		std::cout << BOLD_ON << RED << "Overflow detected in toFloat" << RESET << std::endl;
		return (0.0f);	
	}
	return((float)this->_value / (1 << this->_nbBits)); // <==> ((float)this->value / (float)2^_nbBits)
}

int	Fixed::toInt( void )const{
	
	int shiftedValue = this->_value >> this->_nbBits;
	if (shiftedValue > INT_MAX || shiftedValue < INT_MIN) 
	{
		std::cout << BOLD_ON << RED << "Overflow detected in toInt" << RESET << std::endl;
		return (0);
	}
	return (shiftedValue); // <==> (this->value * 2^8)
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}

/*

11111111 111111111 11111111 111111111
11111111 111111111 11111111 000000000
00000000 111111111 11111111 111111111

INT_MAX >> 8

*/