/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:20:59 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/29 20:13:56 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	_fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

/**
 * Copy constructor
 * this->setRawBits(otherFixed.getRawBits());
 * no need to do this because we have redifned the copy assignment operator
 */
Fixed::Fixed(const Fixed& otherFixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = otherFixed;
}

Fixed& Fixed::operator=(const Fixed& otherFixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &otherFixed)
		return *this;
	this->_fixedPointValue = otherFixed.getRawBits();
	return *this;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" <<std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}


