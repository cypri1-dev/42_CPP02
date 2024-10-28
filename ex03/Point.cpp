/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:29:50 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/28 14:41:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// std::cout << BOLD_ON GREEN << "Default constructor called" << RESET << std::endl;
}

Point::Point(const float xVal, const float yVal) : _x(xVal), _y(yVal) {
	// std::cout << BOLD_ON BLUE << "Float constructor called" << RESET << std::endl;
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()) {
	// std::cout << BOLD_ON << "Copy constructor called" << RESET << std::endl;
}

Point &Point::operator=(const Point &other) {
	if (this == &other)
		return (*this);
	return (*this);
}

Point::~Point(){
	// std::cout << BOLD_ON RED << "Destructor called" << RESET << std::endl;
}

const Fixed &Point::getX(void)const {
	return (this->_x);
}

const Fixed &Point::getY(void)const {
	return (this->_y);
}