/******************************************************************************
 * point.cpp
 *
 * Copyright (c) 2022 Aliasgar Surti <aliasgar.surti500@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation; or, when distributed
 * separately from the Linux kernel or incorporated into other
 * software packages, subject to the following license:
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this source file (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "point.h"
#include <math.h>
#include <iostream>

bool Point::operator==(const Point &p) {
  if ((p.m_x == this->m_x) && (p.m_y == this->m_y)) {
    return true;
  }
  return false;
}

void Point::displace(int dx, int dy) {
  this->m_x += dx;
  this->m_y += dy;
}

Quadrant Point::quadrant() const {
  if (Point::isOrigin()) {
    return Quadrant::NONE;
  } else if (m_x > 0 && m_y > 0) {
    return Quadrant::Q1;
  } else if (m_x < 0 && m_y > 0) {
    return Quadrant::Q2;
  } else if (m_x < 0 && m_y < 0) {
    return Quadrant::Q3;
  } else if (m_x > 0 && m_y < 0) {
    return Quadrant::Q4;
  }
}

double Point::distanceFromOrigin() const {
  return (sqrt((m_x) * (m_x) + (m_y) * (m_y)));
}

bool Point::isOrigin() const {
  if (m_x == 0 && m_y == 0) {
    return true;
  } else {
    return false;
  }
}

bool Point::isOnXAxis() const {
  if (m_x == 0) {
    return true;
  } else {
    return false;
  }
}

bool Point::isOnYAxis() const {
  if (m_y == 0) {
    return true;
  } else {
    return false;
  }
}

void Point::display() {
  std::cout << "x : " << m_x;
  std::cout << ", y : " << m_y << std::endl;
}
