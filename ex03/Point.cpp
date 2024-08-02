/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:25:16 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/02 15:09:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}

Point::Point( const float x, const float y ) : fpX(x), fpY(y) {
	// fpX and fpY are initialized using the Fixed(float) constructor
}

Point::Point( const Point& otherPoint ) {
	*this = otherPoint;
}

Point&	Point::operator=( const Point& otherPoint )
{
	if (this == &otherPoint)
		return *this;
	this->fpX = otherPoint.fpX;
	this->fpY = otherPoint.fpY;
	return *this;
}

Point::~Point() {}

Fixed	Point::getX() const
{
	return this->fpX;
}

Fixed	Point::getY() const
{
	return this->fpY;
}
