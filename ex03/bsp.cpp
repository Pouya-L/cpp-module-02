/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:37:43 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/02 16:53:27 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * abs() is a function in cmath lib used to get the absolute value of a number.
 * here, I added that function as getAbsoluteValue to the Fixed class.
 * @brief uses the gauss's formula (or the shoelace formula) to calculate the area
 * of a triangle based on the coordinates of it.
 * @param	a: one of the vertices of the triangle as a Point object
 * @param	b: one of the vertices of the triangle as a Point object
 * @param	c: one of the vertices of the triangle as a Point object
 * @return	area: the area of the triangle as a Fixed point number.
 *
 */
Fixed	gaussAreaFormula(Point a, Point b, Point c)
{
	Fixed area =	((a.getX() * (b.getY() - c.getY())) +
					(b.getX() * (c.getY() - a.getY())) +
					(c.getX() * (a.getY() - b.getY()))) * Fixed(0.5f);
	return area.getAbsoluteValue();
}

/**
 * The Barycentric algorithm is a method used to determine if a point lies inside a triangle.
 * the sub-triangles are formed by the point in question and the vertices of the original triangle.
 * Specifically, if you have a triangle ABC and a point P, the sub-triangles are:
 *	Triangle PBC, Triangle APC, Triangle ABP
 *	Steps of the Algorythm
 * 1.Calculate the Area of the Original Triangle (ABC):
 * Use the gaussAreaFormula to compute the area of the triangle formed by points A, B, and C.
 *
 * 2. Calculate the Areas of the Sub-Triangles:
 * Compute the area of the triangle formed by point P and vertices B and C.
 * Compute the area of the triangle formed by point P and vertices A and C.
 * Compute the area of the triangle formed by point P and vertices A and B.
 *
 * 3.Check if the Point is Inside the Triangle:
 * Sum the areas of the sub-triangles. If the sum of the areas of the sub-triangles
 * equals the area of the original triangle, then point P lies inside the triangle ABC.
 */
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abcArea = gaussAreaFormula(a, b, c);
	Fixed pbcArea = gaussAreaFormula(point, b, c);
	Fixed apcArea = gaussAreaFormula(a, point, c);
	Fixed abpArea = gaussAreaFormula(a, b, point);

	if (abcArea == pbcArea + apcArea + abpArea)
		return true;
	else
		return false;
}
