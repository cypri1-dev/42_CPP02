/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/28 09:08:16 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << BOLD_ON GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int integer)
{
	std::cout << BOLD_ON YELLOW << "Integer constructor called" << RESET << std::endl;
	if (integer > (INT_MAX >> this->_nbBits) || integer < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON RED << "Overflow detected" << RESET << std::endl;
	this->_value = integer << this->_nbBits;
}
Fixed::Fixed(const float floater)
{
	std::cout << BOLD_ON BLUE << "Float constructor called" << RESET << std::endl;
	int intPart = (int)roundf(floater);
	if (intPart > (INT_MAX >> this->_nbBits) || intPart < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON << RED << "Overflow detected" << RESET << std::endl;
	this->_value = (int)roundf(floater * (1 << this->_nbBits));
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
	std::cout << BOLD_ON << "Copy constructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << BOLD_ON << "Copy assigment operator called" << RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	
	std::cout << BOLD_ON RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void )const {
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void )const {
	return((float)this->_value / (1 << this->_nbBits));
}

int	Fixed::toInt( void )const {
	return (this->_value >> this->_nbBits);
}

bool Fixed::operator>(Fixed const &other)const {
	return (this->_value > other._value);
}

bool Fixed::operator<(Fixed const &other)const {
	return (this->_value < other._value);
}

bool Fixed::operator>=(Fixed const &other)const {
	return (this->_value >= other._value);
}

bool Fixed::operator<=(Fixed const &other)const {
	return (this->_value <= other._value);
}

bool Fixed::operator==(Fixed const &other)const {
	return (this->_value == other._value);
}

bool Fixed::operator!=(Fixed const &other)const {
	return (this->_value != other._value);
}

Fixed Fixed::operator+(Fixed const &other)const {
	//add protection overflow
	return Fixed(this->_value + other._value);
}

Fixed Fixed::operator-(Fixed const &other)const {
	//add protection overflow
	return Fixed(this->_value - other._value);
}

Fixed Fixed::operator*(Fixed const &other)const {
	//add protection overflow
	return Fixed(this->_value * other._value);
}

Fixed Fixed::operator/(Fixed const &other)const {
	//add protection overflow & division by 0
	return Fixed(this->_value / other._value);
}