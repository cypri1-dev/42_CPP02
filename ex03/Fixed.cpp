/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:20:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/28 14:42:18 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <climits>

const int Fixed::_nbBits = 8;

Fixed::Fixed() : _value(0) {
	// std::cout << BOLD_ON GREEN << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int integer)
{
	// std::cout << BOLD_ON YELLOW << "Integer constructor called" << RESET << std::endl;
	if (integer > (INT_MAX >> this->_nbBits) || integer < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON RED << "Overflow detected" << RESET << std::endl;
	this->_value = integer << this->_nbBits;
}
Fixed::Fixed(const float floater)
{
	// std::cout << BOLD_ON BLUE << "Float constructor called" << RESET << std::endl;
	int intPart = (int)roundf(floater);
	if (intPart > (INT_MAX >> this->_nbBits) || intPart < (INT_MIN >> this->_nbBits))
		std::cout << BOLD_ON << RED << "Overflow detected" << RESET << std::endl;
	this->_value = (int)roundf(floater * (1 << this->_nbBits));
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
	// std::cout << BOLD_ON << "Copy constructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << BOLD_ON << "Copy assigment operator called" << RESET << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	
	// std::cout << BOLD_ON RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void )const {
	return (this->_value);
}

void Fixed::setRawBits( int const raw ) {
	this->_value = raw;
}

float	Fixed::toFloat( void )const {
	return((float)this->getRawBits() / (1 << this->_nbBits));
}

int	Fixed::toInt( void )const {
	return (this->getRawBits() >> this->_nbBits);
}

bool Fixed::operator>(Fixed const &other)const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(Fixed const &other)const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other)const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other)const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(Fixed const &other)const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other)const {
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)const {
	
	Fixed res(this->toFloat() + other.toFloat());
	return (res);
}

Fixed Fixed::operator-(Fixed const &other)const {
	
	Fixed res(this->toFloat() - other.toFloat());
	return (res);
}

Fixed Fixed::operator*(Fixed const &other)const {

	Fixed res(this->toFloat() * other.toFloat());
	return (res);
}

Fixed Fixed::operator/(Fixed const &other)const {

	if (other.getRawBits() == 0)
	{
		std::cout << BOLD_ON RED << "What a dirty division by 0" << RESET << std::endl;
		return Fixed(-1);
	}
	Fixed res(this->toFloat() / other.toFloat());
	return (res);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this); // copy object
	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
	out << fixe.toFloat();
	return (out);
}