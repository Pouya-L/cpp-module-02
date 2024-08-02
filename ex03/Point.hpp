/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:21:02 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/02 15:18:49 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class	Point {
private:
	Fixed	fpX;
	Fixed	fpY;

public:
	Point();
	Point( const float x, const float y );
	Point( const Point& otherPoint );
	Point& operator=( const Point& otherPoint );
	~Point();
	Fixed	getX() const;
	Fixed	getY() const;

};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
Fixed	gaussAreaFormula(Point a, Point b, Point c);
