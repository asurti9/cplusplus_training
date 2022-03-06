/******************************************************************************
 * pointdb.cpp
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

#include "pointdb.h"
#include <algorithm>
#include <iostream>

dbError_t PointCollection::addPoint(int x, int y) {
  dbError_t retCode = dbError_t::FAILURE;
  auto &ref = points.emplace_back(x, y);
  if ((ref.x() == x) && (ref.y() == y)) {
    retCode = dbError_t::SUCCESS;
  }
  return retCode;
}

dbError_t PointCollection::removePoint(int x, int y) {
  // points.remove_if(isPointFound);
  std::list<Point>::iterator iter;
  dbError_t retCode = dbError_t::FAILURE;
  for (iter = points.begin(); iter != points.end(); ++iter) {
    if (iter->x() == x && iter->y() == y) {
      points.remove(Point{x, y});
      retCode = dbError_t::SUCCESS;
      break;
    }
  }
  return retCode;
}

bool PointCollection::isPointFound(int x, int y) {
  std::list<Point>::iterator iter;
  /*
    for (iter = points.begin(); iter != points.end(); ++iter) {
      if (iter->x() == x && iter->y() == y) {
        return true;
      }
    }
    return false;
  */
  iter = std::find_if(points.begin(), points.end(), [x, y](const Point &rp) {
    return rp.x() == x && rp.y() == y;
  });
  return iter != points.end();
}

void PointCollection::displayAll() {
  for (auto &pt : points) {
    pt.display();
  }
}

std::optional<Point *> PointCollection::findPointByXY(int x, int y) {
  std::list<Point>::iterator iter;
  iter = std::find(points.begin(), points.end(), Point{x, y});
  if (iter != points.end()) {
    return &*iter;
  }
  return std::nullopt;
}

int PointCollection::countPointsByQudrant(Quadrant quad) {
  int ret = 0;
  for (auto &pt : points) {
    if (pt.quadrant() == quad) {
      ++ret;
    }
  }
  return ret;
}

// considering the distance from origin
int PointCollection::countPointsByDistance(double rmax) {
  int ret = 0;
  for (auto &pt : points) {
    if (pt.distanceFromOrigin() == rmax) {
      ++ret;
    }
  }
  return ret;
}

int PointCollection::countPointsOnCircleBoundary(double radius) {
  int ret = 0;
  for (auto &pt : points) {
    if (pt.distanceFromOrigin() == radius) {
      ++ret;
    }
  }
  return ret;
}

int PointCollection::countPointsByDistanceAndQuadrant(Quadrant quad,
                                                      double rad) {
  int ret = 0;
  for (auto &pt : points) {
    if ((pt.distanceFromOrigin() == rad) && (pt.quadrant() == quad)) {
      ++ret;
    }
  }
  return ret;
}

std::list<Point> PointCollection::findPointsByQuadrant(Quadrant quad) {
  std::list<Point> results;
  // std::list<Point>::iterator iter;
  // for (iter = points.begin(); iter != points.end(); ++iter) {
  for (auto &pt : points) {
    if (pt.quadrant() == quad) {
      results.push_back(pt);
    }
  }
  return results;
}

std::list<Point> PointCollection::findPointsByDistance(double dist) {
  std::list<Point> results;
  for (auto &pt : points) {
    if (pt.distanceFromOrigin() == dist) {
      results.push_back(pt);
    }
  }
  return results;
}

Point &PointCollection::farthestPointFromOrigin() {
  Point ref;
  // assigning first point distance from origin for reference
  auto i = points.begin();
  int distanceFromOrigin = i->distanceFromOrigin();
  for (auto &pt : points) {
    if (pt.distanceFromOrigin() > distanceFromOrigin) {
      ref = pt; // default copy constructor
    }
  }
  return ref;
}

Point &PointCollection::nearestPointFromOrigin() {
  Point ref;
  // assigning first point distance from origin for reference
  auto i = points.begin();
  int distanceFromOrigin = i->distanceFromOrigin();
  for (auto &pt : points) {
    if (pt.distanceFromOrigin() < distanceFromOrigin) {
      ref = pt;
    }
  }
  return ref;
}
