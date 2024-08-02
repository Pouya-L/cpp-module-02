/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:56:33 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/29 19:36:16 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

/**
 * getRawBits() should be marked as consts, When a member function is marked
 * as const, it promises not to modify the object on which it is called.
 * This allows the function to be called on const objects.
 */
class Fixed {
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& otherFixed);
	Fixed& operator=(const Fixed& otherFixed);\
	~Fixed();
	
	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
};
