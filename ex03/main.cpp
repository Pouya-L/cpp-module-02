/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 20:46:56 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/02 16:47:17 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main() {
	// Define points for the triangle
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);

	// Define points to test
	Point insidePoint(1, 1);
	Point outsidePoint(6, 6);
	Point edgePoint(0, 2.5);

	// Test the bsp function
	std::cout << "Inside Point (1,1): " << bsp(a, b, c, insidePoint) << std::endl;
	std::cout << "Outside Point (6,6): " << bsp(a, b, c, outsidePoint) << std::endl;
	std::cout << "Edge Point (0,2.5): " << bsp(a, b, c, edgePoint) << std::endl;

	return 0;
}
