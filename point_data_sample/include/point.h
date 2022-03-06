/******************************************************************************
 * point.h
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

#ifndef __POINT_H
#define __POINT_H

enum class Quadrant { Q1, Q2, Q3, Q4, NONE };

class IPoint {
public:
  virtual void displace(int dx, int dy) = 0;
  virtual Quadrant quadrant() const = 0;
  virtual double distanceFromOrigin() const = 0;
  // bool isOrigin() const;
  // bool isOnXAxis() const;
  // bool isOnYAxis() const;
};

class Point {
  int m_x;
  int m_y;

public:
  Point() = default;
  Point(int x, int y) : m_x(x), m_y(y) {}
  int x() const { return m_x; }
  int y() const { return m_y; }
  void displace(int dx, int dy);
  Quadrant quadrant() const;
  double distanceFromOrigin() const;
  bool isOrigin() const;
  bool isOnXAxis() const;
  bool isOnYAxis() const;
  void display(); // only for learning/internal testing
  bool operator==(const Point &p);
};

/* class 2DObject {
      Point m_point;
      Color m_color;
      double m_weight;
   };
*/

#endif
