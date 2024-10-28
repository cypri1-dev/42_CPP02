/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:18:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/28 14:58:05 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main (void)
{
	std::cout << BOLD_ON BLUE << "Let's test it!" << RESET << std::endl;
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point test(2, 2);
	// Point test(1, 1);
	// Point test(6, 6);
	// Point test(-1, 1);
	// Point test(3, 2);
	/****************************/
	// Point a(0.0, 0.0);
	// Point b(2.5, 0.0);
	// Point c(0, 2.5);
	// Point test(1.0, 1.0);
	// Point test(0.5, 0.5);
	// Point test(3.0, 3.0);
	// Point test(2.5, 2.5);
	// Point test(1.5, 1.0);

	if (bsp(a, b, c, test))
		std::cout << BOLD_ON GREEN << "Point is inside" << RESET << std::endl;
	else
		std::cout << BOLD_ON YELLOW << "Point is not inside" << RESET << std::endl;
}