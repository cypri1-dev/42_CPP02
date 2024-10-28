/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:00:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/28 14:14:39 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed crossVector(Point const a, Point const b, Point const p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool isInside = false;
	Fixed crossVector1 = crossVector(a, b, point);
	Fixed crossVector2 = crossVector(b, c, point);
	Fixed crossVector3 = crossVector(c, a, point);

	isInside = ((crossVector1 > 0 && crossVector2 > 0 && crossVector3 > 0) || (crossVector1 < 0 && crossVector2 < 0 && crossVector3 < 0));
	return (isInside);
}