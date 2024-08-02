/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:22:26 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/29 21:39:26 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed( const int n);
	Fixed( const float n);
	Fixed(const Fixed& otherFixed);
	Fixed& operator=(const Fixed& otherFixed);
	~Fixed();

	void	setRawBits( int const raw );
	int		getRawBits(void) const;
	float	toFloat( void ) const;
	int 	toInt( void ) const;

	// Comparison operators
	bool	operator>( const Fixed &otherFixed ) const ;
	bool	operator>=( const Fixed &otherFixed ) const ;
	bool	operator<( const Fixed &otherFixed ) const ;
	bool	operator<=( const Fixed &otherFixed ) const ;
	bool	operator==( const Fixed &otherFixed ) const ;
	bool	operator!=( const Fixed &otherFixed ) const ;

	// Arithmetic operators
	Fixed	operator+( const Fixed &otherFixed ) const ;
	Fixed	operator-( const Fixed &otherFixed ) const ;
	Fixed	operator*( const Fixed &otherFixed ) const ;
	Fixed	operator/( const Fixed &otherFixed ) const ;

	// Increment and Decrement operators
	/* The post-increment and post-decrement operators in C++ are defined with an int parameter to differentiate them
	 * from the pre-increment and pre-decrement operators. The int parameter is not used in the function body;
	 * it is just a convention to distinguish the two forms of the operators.
	*/
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );

	static Fixed& min(Fixed& n1, Fixed& n2);
	static const Fixed& min(const Fixed& n1, const Fixed& n2);
	static Fixed& max(Fixed& n1, Fixed& n2);
	static const Fixed& max(const Fixed& n1, const Fixed& n2);

};

std::ostream& operator<<(std::ostream& osb, const Fixed& fixedPointNumber);
