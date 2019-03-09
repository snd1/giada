/* -----------------------------------------------------------------------------
 *
 * Giada - Your Hardcore Loopmachine
 *
 * -----------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019 Giovanni A. Zuliani | Monocasual
 *
 * This file is part of Giada - Your Hardcore Loopmachine.
 *
 * Giada - Your Hardcore Loopmachine is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * Giada - Your Hardcore Loopmachine is distributed in the hope that it
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Giada - Your Hardcore Loopmachine. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------- */


#ifndef G_UTILS_MATH_H
#define G_UTILS_MATH_H


namespace giada {
namespace u     {
namespace math 
{
float linearToDB(float f);
float dBtoLinear(float f);
int quantize(int x, int step);


/* -------------------------------------------------------------------------- */

/* map (1)
Maps 'x' in range [a, b] to a new range [w, z]. Source:
	https://en.wikipedia.org/wiki/Linear_equation#Two-point_form*/

template <typename TI, typename TO>
TO map(TI x, TI a, TI b, TO w, TO z)
{
	return (((x - a) / (double) (b - a)) * (z - w)) + w;
}


/* map (2)
Maps 'x' in range [0, b) to a new range [0, z]. */

template <typename TI, typename TO>
TO map(TI x, TI b, TO z)
{
	return (x / (double) b) * z;
}


/* -------------------------------------------------------------------------- */

/* bound (1)
Returns 'def' if 'x' is outside the range ('min', 'max'). */

template <typename T>
T bound(T x, T min, T max, T def)
{
    return x < min || x > max ? def : x;
}


/* bound (2)
Clamps 'x' in the range ('min', 'max'). */

template <typename T>
T bound(T x, T min, T max)
{
    if (x < min) return min; 
	if (x > max) return max;
	return x;
}
}}}  // giada::u::math::


#endif
