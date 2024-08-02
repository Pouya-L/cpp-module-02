/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:22:26 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/29 20:49:59 by plashkar         ###   ########.fr       */
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
	Fixed& operator=(const Fixed& otherfixed);
	~Fixed();

	void	setRawBits( int const raw );
	int		getRawBits(void) const;
	float	toFloat( void ) const;
	int 	toInt( void ) const;
};

std::ostream& operator<<(std::ostream& osb, const Fixed& fixedPointNumber);
