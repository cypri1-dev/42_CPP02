/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:22:33 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/18 16:51:04 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	// a.setRawBits(2);
	// b.setRawBits(3);
	// c = b;

	// std::cout << BOLD_ON << a.getRawBits() << RESET << std::endl;
	// std::cout << BOLD_ON << b.getRawBits() << RESET << std::endl;
	// std::cout << BOLD_ON << c.getRawBits() << RESET << std::endl;
	return 0;
}

// int main (void)
// {
// 	Fixed a;
// 	Fixed b( a );
// 	Fixed c;
	
// 	c = b;

// 	std::cout << BOLD_ON << a.getRawBits() << RESET << std::endl;
// 	std::cout << BOLD_ON << b.getRawBits() << RESET << std::endl;
// 	std::cout << BOLD_ON << c.getRawBits() << RESET << std::endl;
	

	
// 	return (0);
// }