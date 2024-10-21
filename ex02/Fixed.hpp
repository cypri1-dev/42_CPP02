/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:47:38 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/21 14:48:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

class Fixed {
	private:
		int _value;
		static const int _nbBits;
	public:
		Fixed();
		Fixed(const int integer);
		Fixed(const float floater);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		
		int getRawBits( void )const;
		void setRawBits( int const raw );
		float toFloat( void )const;
		int toInt( void )const;
		
		bool operator>(Fixed const &other)const;
		bool operator<(Fixed const &other)const;
		bool operator>=(Fixed const &other)const;
		bool operator<=(Fixed const &other)const;
		bool operator==(Fixed const &other)const;
		bool operator!=(Fixed const &other)const;

		Fixed operator+(Fixed const &other);
		Fixed operator-(Fixed const &other);
		Fixed operator/(Fixed const &other);
		Fixed operator*(Fixed const &other);

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif 