/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:36:43 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/02 14:57:11 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_fixedPointValue = 0;
	// std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( const int n )
{
	this->_fixedPointValue = n << _fractionalBits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n )
{
	this->_fixedPointValue = static_cast<int>(roundf(n * (1 << _fractionalBits)));
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& otherFixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = otherFixed;
}

Fixed& Fixed::operator=(const Fixed& otherfixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherfixed)
		return *this;
	this->_fixedPointValue = otherfixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixedPointValue = raw;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>( this->getRawBits()) / (1 << _fractionalBits);
}

int 	Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& osb, const Fixed& fixedPointNumber)
{
	osb << fixedPointNumber.toFloat();
	return (osb);
}

Fixed	Fixed::getAbsoluteValue() const
{
	if (this->toFloat() < 0)
		return Fixed(this->toFloat() * -1);
	else
		return *this;
}


// Comparison operators

bool	Fixed::operator>( const Fixed &otherFixed ) const
{
	return (this->getRawBits() > otherFixed.getRawBits());
}

bool	Fixed::operator>=( const Fixed &otherFixed ) const
{
	return (this->getRawBits() >= otherFixed.getRawBits());
}

bool	Fixed::operator<( const Fixed &otherFixed ) const
{
	return (this->getRawBits() < otherFixed.getRawBits());
}

bool	Fixed::operator<=( const Fixed &otherFixed ) const
{
	return (this->getRawBits() <= otherFixed.getRawBits());
}

bool	Fixed::operator==( const Fixed &otherFixed ) const
{
	return (this->getRawBits() == otherFixed.getRawBits());
}

bool	Fixed::operator!=( const Fixed &otherFixed ) const
{
	return (this->getRawBits() != otherFixed.getRawBits());
}

// Arithmetic operators

Fixed	Fixed::operator+( const Fixed &otherFixed ) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + otherFixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator-( const Fixed &otherFixed ) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - otherFixed.getRawBits());
	return (result);
}

/**
 * This multiplies the raw fixed-point values of the two operands. but
 * the result of the multiplication will have 2 * _fractionalBits.
 * so to convert the result back to the original fixed-point format with _fractionalBits,
 * we need to shift the result right by _fractionalBits bits.
 */
Fixed	Fixed::operator*( const Fixed &otherFixed ) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() * otherFixed.getRawBits() >> _fractionalBits));
	return (result);
}

/**
 * before performing the division, we shift the numerator left by _fractionalBits bits.
 * This operation scales the numerator up to ensure that the division result will have the correct fixed-point format.
 */
Fixed	Fixed::operator/( const Fixed &otherFixed ) const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << _fractionalBits) / otherFixed.getRawBits());
	return (result);
}

// Increment and Decrement operators

Fixed&	Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

/**
 * The use of a temporary variable (temp) in the postfix increment operator is necessary
 * to return the original value of the object before the increment operation.
 * This is the key difference between the postfix (x++) and prefix (++x) increment operators.
 */
Fixed	Fixed::operator++( int )
{
	Fixed temp = *this;
	this->_fixedPointValue++;
	return (temp);
}

Fixed&	Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed temp = *this;
	this->_fixedPointValue--;
	return (temp);
}

//min and max functions

/**
 * The ? and : operators are a shorthand way of writing an if-else statement. The syntax is:
 * [ condition ? expression_if_true : expression_if_false; ]
 */
Fixed& Fixed::min(Fixed& n1, Fixed& n2)
{
	return n1 < n2 ? n1 : n2;
}

const Fixed& Fixed::min(const Fixed& n1, const Fixed& n2)
{
	return n1 < n2 ? n1 : n2;
}

Fixed& Fixed::max(Fixed& n1, Fixed& n2)
{
	return n1 > n2 ? n1 : n2;
}

const Fixed& Fixed::max(const Fixed& n1, const Fixed& n2)
{
	return n1 > n2 ? n1 : n2;
}



