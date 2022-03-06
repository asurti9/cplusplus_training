/******************************************************************************
 * pointdb.h
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

#ifndef __POINTDB_H
#define __POINTDB_H

#include "point.h"
#include <list>
#include <optional>

enum class ErrorType { SUCCESS, FAILURE, OTHER };

using dbError_t = ErrorType;

// template<typename T>
// using smart_ptr_t<T> = std::shared_pointer<T>;
// using smart_ptr_t<T> = std::unique_pointer<T>;

class PointCollection {
  std::list<Point> points;
  // std::list<Point*> points;
  // std::list<smart_ptr_t<Point>> spoints;
public:
  dbError_t addPoint(int x, int y);
  dbError_t removePoint(int x, int y);
  void displayAll(); // only for learning/testing
  bool isPointFound(int x, int y);
  std::optional<Point *> findPointByXY(int x, int y); // Hint:- std::option
  int countPointsByQudrant(Quadrant);
  int countPointsByDistance(double rmax);         // within boundary
  int countPointsOnCircleBoundary(double radius); // on boundary
  int countPointsByDistanceAndQuadrant(Quadrant, double);
  std::list<Point> findPointsByQuadrant(Quadrant); // std::set, new container
  std::list<Point> findPointsByDistance(double);
  Point &farthestPointFromOrigin();
  Point &nearestPointFromOrigin();
};
#endif
