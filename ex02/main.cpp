/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:26 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/31 11:37:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {

	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	
	// Opérateur d'affectation
	a = Fixed(1234.4321f);
	std::cout << "a (après affectation) = " << a << std::endl;

	// Tests des opérateurs de comparaison
	std::cout << "b > c : " << (b > c) << std::endl;
	std::cout << "b < c : " << (b < c) << std::endl;
	std::cout << "b >= d : " << (b >= d) << std::endl;
	std::cout << "b <= d : " << (b <= d) << std::endl;
	std::cout << "b == d : " << (b == d) << std::endl;
	std::cout << "b != c : " << (b != c) << std::endl;

	// Tests des opérateurs arithmétiques
	Fixed e = b + c;
	Fixed f = b - c;
	Fixed g = b * c;
	Fixed h = b / c;
	
	std::cout << "b + c = " << e << std::endl;
	std::cout << "b - c = " << f << std::endl;
	std::cout << "b * c = " << g << std::endl;
	std::cout << "b / c = " << h << std::endl;
	
	// Division par zéro
	Fixed zero;
	std::cout << "c / zero = " << (c / zero) << std::endl;
	
	// Incrémentation et décrémentation
	Fixed i;
	std::cout << "i (initial) = " << i << std::endl;
	std::cout << "++i = " << ++i << std::endl;
	std::cout << "i++ = " << i++ << std::endl;
	std::cout << "i (après i++) = " << i << std::endl;
	std::cout << "--i = " << --i << std::endl;
	std::cout << "i-- = " << i-- << std::endl;
	std::cout << "i (après i--) = " << i << std::endl;

	// Fonctions min et max
	std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl;
	return 0;
}
