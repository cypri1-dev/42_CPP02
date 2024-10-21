/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:58:29 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/21 13:48:37 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>
#include <climits>

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
		static const int _nbBits; //shared between all instances
	public:
		Fixed(); //default constructor
		Fixed(const int integer); //constructor const int
		Fixed(const float floater); //constructor const float
		Fixed(const Fixed &other); //copy constructor
		Fixed &operator=(const Fixed &other); //assignment operator '='
		~Fixed(); //Default destructor
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void )const;
		int toInt( void )const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixe); //assignment operator '<<'

/*

int Var = 12;
[0000 0000] [0000 0000] [0000 0000] [0000 1100] int = 12

Fixed :
------------------Entiere---------        ---Mant-----
[0000 0000] [0000 0000] [0000 0000] <---> [0000 0000]

int32_t ---> 32 bits entier
int24_t ---> 24 bits entier + float8_t --> bits decimaux

Var to fixed => (Var << _nbBits) <=> (Var << 8) <=> (12 << 8) <=> (12 * 2^8)
[0000 0000] [0000 0000] [0000 1100] <---> [0000 0000]

fixed to Var => (Var >> _nbBits) <=> (Var >> 8) <=> (3072 >> 8) <=> (3072 / 2^8)
[0000 0000] [0000 0000] [0000 0000] <---> [0000 1100]

float Varbis = 12.852f;
VarBis to fixed = (VarBis * 2^8) <=> (12.852 * 2^8) <=> 3290.112
=> roundf(3290.112) => 3290

fixed to float = (3290 / 2^8) ==> 12.852

*/

#endif