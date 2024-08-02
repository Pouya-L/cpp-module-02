/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:36:43 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/30 18:14:29 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

/** Basically the exact opposite of what we did in toInt()*/
Fixed::Fixed( const int n )
{
	this->_fixedPointValue = n << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

/**
 * What this function does is the following
 * Scaling n by 2^_fractionalBits.
 *	Rounding the result to the nearest integer.
 *		Storing the result in _fixedPointValue.
 * [Example with 5.75 and _fractionalBits = 8										]
 * [n * (1 << _fractionalBits) becomes 5.75 * 256 = 1472.							]
 * [Rounding the Result: roundf(1472) is 1472 (since 1472 is already an integer).	]
 * [casting to an int: static_cast<int>(1472) is 1472.								]
 * [Assigning to _fixedPointValue: this->_fixedPointValue = 1472.					]
 */
Fixed::Fixed( const float n )
{
	this->_fixedPointValue = static_cast<int>(roundf(n * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = otherFixed;
}

Fixed& Fixed::operator=(const Fixed& otherfixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherfixed)
		return *this;
	this->_fixedPointValue = otherfixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

/**
 * !! The division should be performed after casting the fixed-point value to	!!
 * !! a float to ensure proper floating-point arithmetic.						!!
 *
 * This is a common technique in fixed-point arithmetic to handle the conversion between
 * fixed-point and floating-point numbers by using a power of two as a scaling factor.
 *
 * The expression (1 << _fractionalBits) is a bitwise operation used to calculate a power of two.
 * This results in 256, which is 2^8
 *
 * Division by Scaling Factor: The fixed-point value (obtained from getRawBits()) is
 * divided by (1 << _fractionalBits) to convert it to a floating-point number.
 * This effectively scales the fixed-point value down by the appropriate power of
 * two to get the correct floating-point representation.
 */
float	Fixed::toFloat( void ) const
{
	return static_cast<float>( this->getRawBits()) / (1 << _fractionalBits);
}

/**
 * The toInt method in the Fixed class converts the fixed-point value to an integer.
 * it shifts _fixedPointValue to the right by _fractionalBits positions.
 * Shifting right by _fractionalBits effectively divides the fixed-point value by 2^_fractionalBits.
 *	[let's imagine the decimal number of 10.2: 10.2 * 256 = 2611.2 			]
 *	[since fixedPointnumbers are ints, 2611.2 would be 2611					]
 *	[Binary representation of 2611: 00001010 00110011						]
 *	[Shifting right by 8 bits: 00000000 00001010 (which is 10 in decimal)	]
 */
int 	Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

/**
 * By converting the fixed-point value to a floating-point number, the function ensures
 * that the output is in a human-readable format that accurately represents the original value.
 */
std::ostream& operator<<(std::ostream& osb, const Fixed& fixedPointNumber)
{
	osb << fixedPointNumber.toFloat();
	return (osb);
}

