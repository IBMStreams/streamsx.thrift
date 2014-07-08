// Copyright 2009 The Trustees of Indiana University.

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.streams_boost.org/LICENSE_1_0.txt)

//  Authors: Jeremiah Willcock
//           Douglas Gregor
//           Andrew Lumsdaine
#ifndef STREAMS_BOOST_GRAPH_TOPOLOGY_HPP
#define STREAMS_BOOST_GRAPH_TOPOLOGY_HPP

#include <streams_boost/config/no_tr1/cmath.hpp>
#include <cmath>
#include <streams_boost/random/uniform_01.hpp>
#include <streams_boost/random/linear_congruential.hpp>
#include <streams_boost/math/constants/constants.hpp> // For root_two
#include <streams_boost/algorithm/minmax.hpp>
#include <streams_boost/config.hpp> // For STREAMS_BOOST_STATIC_CONSTANT
#include <streams_boost/math/special_functions/hypot.hpp>

// Classes and concepts to represent points in a space, with distance and move
// operations (used for Gurson-Atun layout), plus other things like bounding
// boxes used for other layout algorithms.

namespace streams_boost {

/***********************************************************
 * Topologies                                              *
 ***********************************************************/
template<std::size_t Dims>
class convex_topology 
{
  public: // For VisualAge C++
  struct point 
  {
    STREAMS_BOOST_STATIC_CONSTANT(std::size_t, dimensions = Dims);
    point() { }
    double& operator[](std::size_t i) {return values[i];}
    const double& operator[](std::size_t i) const {return values[i];}

  private:
    double values[Dims];
  };

  public: // For VisualAge C++
  struct point_difference
  {
    STREAMS_BOOST_STATIC_CONSTANT(std::size_t, dimensions = Dims);
    point_difference() {
      for (std::size_t i = 0; i < Dims; ++i) values[i] = 0.;
    }
    double& operator[](std::size_t i) {return values[i];}
    const double& operator[](std::size_t i) const {return values[i];}

    friend point_difference operator+(const point_difference& a, const point_difference& b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = a[i] + b[i];
      return result;
    }

    friend point_difference& operator+=(point_difference& a, const point_difference& b) {
      for (std::size_t i = 0; i < Dims; ++i)
        a[i] += b[i];
      return a;
    }

    friend point_difference operator-(const point_difference& a) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = -a[i];
      return result;
    }

    friend point_difference operator-(const point_difference& a, const point_difference& b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = a[i] - b[i];
      return result;
    }

    friend point_difference& operator-=(point_difference& a, const point_difference& b) {
      for (std::size_t i = 0; i < Dims; ++i)
        a[i] -= b[i];
      return a;
    }

    friend point_difference operator*(const point_difference& a, const point_difference& b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = a[i] * b[i];
      return result;
    }

    friend point_difference operator*(const point_difference& a, double b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = a[i] * b;
      return result;
    }

    friend point_difference operator*(double a, const point_difference& b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = a * b[i];
      return result;
    }

    friend point_difference operator/(const point_difference& a, const point_difference& b) {
      point_difference result;
      for (std::size_t i = 0; i < Dims; ++i)
        result[i] = (b[i] == 0.) ? 0. : a[i] / b[i];
      return result;
    }

    friend double dot(const point_difference& a, const point_difference& b) {
      double result = 0;
      for (std::size_t i = 0; i < Dims; ++i)
        result += a[i] * b[i];
      return result;
    }

  private:
    double values[Dims];
  };

 public:
  typedef point point_type;
  typedef point_difference point_difference_type;

  double distance(point a, point b) const 
  {
    double dist = 0.;
    for (std::size_t i = 0; i < Dims; ++i) {
      double diff = b[i] - a[i];
      dist = streams_boost::math::hypot(dist, diff);
    }
    // Exact properties of the distance are not important, as long as
    // < on what this returns matches real distances; l_2 is used because
    // Fruchterman-Reingold also uses this code and it relies on l_2.
    return dist;
  }

  point move_position_toward(point a, double fraction, point b) const 
  {
    point result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = a[i] + (b[i] - a[i]) * fraction;
    return result;
  }

  point_difference difference(point a, point b) const {
    point_difference result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = a[i] - b[i];
    return result;
  }

  point adjust(point a, point_difference delta) const {
    point result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = a[i] + delta[i];
    return result;
  }

  point pointwise_min(point a, point b) const {
    STREAMS_BOOST_USING_STD_MIN();
    point result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (a[i], b[i]);
    return result;
  }

  point pointwise_max(point a, point b) const {
    STREAMS_BOOST_USING_STD_MAX();
    point result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (a[i], b[i]);
    return result;
  }

  double norm(point_difference delta) const {
    double n = 0.;
    for (std::size_t i = 0; i < Dims; ++i)
      n = streams_boost::math::hypot(n, delta[i]);
    return n;
  }

  double volume(point_difference delta) const {
    double n = 1.;
    for (std::size_t i = 0; i < Dims; ++i)
      n *= delta[i];
    return n;
  }

};

template<std::size_t Dims,
         typename RandomNumberGenerator = minstd_rand>
class hypercube_topology : public convex_topology<Dims>
{
  typedef uniform_01<RandomNumberGenerator, double> rand_t;

 public:
  typedef typename convex_topology<Dims>::point_type point_type;
  typedef typename convex_topology<Dims>::point_difference_type point_difference_type;

  explicit hypercube_topology(double scaling = 1.0) 
    : gen_ptr(new RandomNumberGenerator), rand(new rand_t(*gen_ptr)), 
      scaling(scaling) 
  { }

  hypercube_topology(RandomNumberGenerator& gen, double scaling = 1.0) 
    : gen_ptr(), rand(new rand_t(gen)), scaling(scaling) { }
                     
  point_type random_point() const 
  {
    point_type p;
    for (std::size_t i = 0; i < Dims; ++i)
      p[i] = (*rand)() * scaling;
    return p;
  }

  point_type bound(point_type a) const
  {
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();
    point_type p;
    for (std::size_t i = 0; i < Dims; ++i)
      p[i] = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (scaling, max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (-scaling, a[i]));
    return p;
  }

  double distance_from_boundary(point_type a) const
  {
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();
#ifndef STREAMS_BOOST_NO_STDC_NAMESPACE
    using std::abs;
#endif
    STREAMS_BOOST_STATIC_ASSERT (Dims >= 1);
    double dist = abs(scaling - a[0]);
    for (std::size_t i = 1; i < Dims; ++i)
      dist = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (dist, abs(scaling - a[i]));
    return dist;
  }

  point_type center() const {
    point_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = scaling * .5;
    return result;
  }

  point_type origin() const {
    point_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = 0;
    return result;
  }

  point_difference_type extent() const {
    point_difference_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = scaling;
    return result;
  }

 private:
  shared_ptr<RandomNumberGenerator> gen_ptr;
  shared_ptr<rand_t> rand;
  double scaling;
};

template<typename RandomNumberGenerator = minstd_rand>
class square_topology : public hypercube_topology<2, RandomNumberGenerator>
{
  typedef hypercube_topology<2, RandomNumberGenerator> inherited;

 public:
  explicit square_topology(double scaling = 1.0) : inherited(scaling) { }
  
  square_topology(RandomNumberGenerator& gen, double scaling = 1.0) 
    : inherited(gen, scaling) { }
};

template<typename RandomNumberGenerator = minstd_rand>
class rectangle_topology : public convex_topology<2>
{
  typedef uniform_01<RandomNumberGenerator, double> rand_t;

  public:
  rectangle_topology(double left, double top, double right, double bottom)
    : gen_ptr(new RandomNumberGenerator), rand(new rand_t(*gen_ptr)),
      left(std::min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (left, right)),
      top(std::min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (top, bottom)),
      right(std::max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (left, right)),
      bottom(std::max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (top, bottom)) { }

  rectangle_topology(RandomNumberGenerator& gen, double left, double top, double right, double bottom)
    : gen_ptr(), rand(new rand_t(gen)),
      left(std::min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (left, right)),
      top(std::min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (top, bottom)),
      right(std::max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (left, right)),
      bottom(std::max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (top, bottom)) { }

  typedef typename convex_topology<2>::point_type point_type;
  typedef typename convex_topology<2>::point_difference_type point_difference_type;

  point_type random_point() const 
  {
    point_type p;
    p[0] = (*rand)() * (right - left) + left;
    p[1] = (*rand)() * (bottom - top) + top;
    return p;
  }

  point_type bound(point_type a) const
  {
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();
    point_type p;
    p[0] = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (right, max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (left, a[0]));
    p[1] = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (bottom, max STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (top, a[1]));
    return p;
  }

  double distance_from_boundary(point_type a) const
  {
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();
#ifndef STREAMS_BOOST_NO_STDC_NAMESPACE
    using std::abs;
#endif
    double dist = abs(left - a[0]);
    dist = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (dist, abs(right - a[0]));
    dist = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (dist, abs(top - a[1]));
    dist = min STREAMS_BOOST_PREVENT_MACRO_SUBSTITUTION (dist, abs(bottom - a[1]));
    return dist;
  }

  point_type center() const {
    point_type result;
    result[0] = (left + right) / 2.;
    result[1] = (top + bottom) / 2.;
    return result;
  }

  point_type origin() const {
    point_type result;
    result[0] = left;
    result[1] = top;
    return result;
  }

  point_difference_type extent() const {
    point_difference_type result;
    result[0] = right - left;
    result[1] = bottom - top;
    return result;
  }

 private:
  shared_ptr<RandomNumberGenerator> gen_ptr;
  shared_ptr<rand_t> rand;
  double left, top, right, bottom;
};

template<typename RandomNumberGenerator = minstd_rand>
class cube_topology : public hypercube_topology<3, RandomNumberGenerator>
{
  typedef hypercube_topology<3, RandomNumberGenerator> inherited;

 public:
  explicit cube_topology(double scaling = 1.0) : inherited(scaling) { }
  
  cube_topology(RandomNumberGenerator& gen, double scaling = 1.0) 
    : inherited(gen, scaling) { }
};

template<std::size_t Dims,
         typename RandomNumberGenerator = minstd_rand>
class ball_topology : public convex_topology<Dims>
{
  typedef uniform_01<RandomNumberGenerator, double> rand_t;

 public:
  typedef typename convex_topology<Dims>::point_type point_type;
  typedef typename convex_topology<Dims>::point_difference_type point_difference_type;

  explicit ball_topology(double radius = 1.0) 
    : gen_ptr(new RandomNumberGenerator), rand(new rand_t(*gen_ptr)), 
      radius(radius) 
  { }

  ball_topology(RandomNumberGenerator& gen, double radius = 1.0) 
    : gen_ptr(), rand(new rand_t(gen)), radius(radius) { }
                     
  point_type random_point() const 
  {
    point_type p;
    double dist_sum;
    do {
      dist_sum = 0.0;
      for (std::size_t i = 0; i < Dims; ++i) {
        double x = (*rand)() * 2*radius - radius;
        p[i] = x;
        dist_sum += x * x;
      }
    } while (dist_sum > radius*radius);
    return p;
  }

  point_type bound(point_type a) const
  {
    STREAMS_BOOST_USING_STD_MIN();
    STREAMS_BOOST_USING_STD_MAX();
    double r = 0.;
    for (std::size_t i = 0; i < Dims; ++i)
      r = streams_boost::math::hypot(r, a[i]);
    if (r <= radius) return a;
    double scaling_factor = radius / r;
    point_type p;
    for (std::size_t i = 0; i < Dims; ++i)
      p[i] = a[i] * scaling_factor;
    return p;
  }

  double distance_from_boundary(point_type a) const
  {
    double r = 0.;
    for (std::size_t i = 0; i < Dims; ++i)
      r = streams_boost::math::hypot(r, a[i]);
    return radius - r;
  }

  point_type center() const {
    point_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = 0;
    return result;
  }

  point_type origin() const {
    point_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = -radius;
    return result;
  }

  point_difference_type extent() const {
    point_difference_type result;
    for (std::size_t i = 0; i < Dims; ++i)
      result[i] = 2. * radius;
    return result;
  }

 private:
  shared_ptr<RandomNumberGenerator> gen_ptr;
  shared_ptr<rand_t> rand;
  double radius;
};

template<typename RandomNumberGenerator = minstd_rand>
class circle_topology : public ball_topology<2, RandomNumberGenerator>
{
  typedef ball_topology<2, RandomNumberGenerator> inherited;

 public:
  explicit circle_topology(double radius = 1.0) : inherited(radius) { }
  
  circle_topology(RandomNumberGenerator& gen, double radius = 1.0) 
    : inherited(gen, radius) { }
};

template<typename RandomNumberGenerator = minstd_rand>
class sphere_topology : public ball_topology<3, RandomNumberGenerator>
{
  typedef ball_topology<3, RandomNumberGenerator> inherited;

 public:
  explicit sphere_topology(double radius = 1.0) : inherited(radius) { }
  
  sphere_topology(RandomNumberGenerator& gen, double radius = 1.0) 
    : inherited(gen, radius) { }
};

template<typename RandomNumberGenerator = minstd_rand>
class heart_topology 
{
  // Heart is defined as the union of three shapes:
  // Square w/ corners (+-1000, -1000), (0, 0), (0, -2000)
  // Circle centered at (-500, -500) radius 500*sqrt(2)
  // Circle centered at (500, -500) radius 500*sqrt(2)
  // Bounding box (-1000, -2000) - (1000, 500*(sqrt(2) - 1))

  struct point 
  {
    point() { values[0] = 0.0; values[1] = 0.0; }
    point(double x, double y) { values[0] = x; values[1] = y; }

    double& operator[](std::size_t i)       { return values[i]; }
    double  operator[](std::size_t i) const { return values[i]; }

  private:
    double values[2];
  };

  bool in_heart(point p) const 
  {
#ifndef STREAMS_BOOST_NO_STDC_NAMESPACE
    using std::abs;
#endif

    if (p[1] < abs(p[0]) - 2000) return false; // Bottom
    if (p[1] <= -1000) return true; // Diagonal of square
    if (streams_boost::math::hypot(p[0] - -500, p[1] - -500) <= 500. * streams_boost::math::constants::root_two<double>())
      return true; // Left circle
    if (streams_boost::math::hypot(p[0] - 500, p[1] - -500) <= 500. * streams_boost::math::constants::root_two<double>())
      return true; // Right circle
    return false;
  }

  bool segment_within_heart(point p1, point p2) const 
  {
    // Assumes that p1 and p2 are within the heart
    if ((p1[0] < 0) == (p2[0] < 0)) return true; // Same side of symmetry line
    if (p1[0] == p2[0]) return true; // Vertical
    double slope = (p2[1] - p1[1]) / (p2[0] - p1[0]);
    double intercept = p1[1] - p1[0] * slope;
    if (intercept > 0) return false; // Crosses between circles
    return true;
  }

  typedef uniform_01<RandomNumberGenerator, double> rand_t;

 public:
  typedef point point_type;

  heart_topology() 
    : gen_ptr(new RandomNumberGenerator), rand(new rand_t(*gen_ptr)) { }

  heart_topology(RandomNumberGenerator& gen) 
    : gen_ptr(), rand(new rand_t(gen)) { }

  point random_point() const 
  {
    point result;
    do {
      result[0] = (*rand)() * (1000 + 1000 * streams_boost::math::constants::root_two<double>()) - (500 + 500 * streams_boost::math::constants::root_two<double>());
      result[1] = (*rand)() * (2000 + 500 * (streams_boost::math::constants::root_two<double>() - 1)) - 2000;
    } while (!in_heart(result));
    return result;
  }

  // Not going to provide clipping to bounding region or distance from boundary

  double distance(point a, point b) const 
  {
    if (segment_within_heart(a, b)) {
      // Straight line
      return streams_boost::math::hypot(b[0] - a[0], b[1] - a[1]);
    } else {
      // Straight line bending around (0, 0)
      return streams_boost::math::hypot(a[0], a[1]) + streams_boost::math::hypot(b[0], b[1]);
    }
  }

  point move_position_toward(point a, double fraction, point b) const 
  {
    if (segment_within_heart(a, b)) {
      // Straight line
      return point(a[0] + (b[0] - a[0]) * fraction,
                   a[1] + (b[1] - a[1]) * fraction);
    } else {
      double distance_to_point_a = streams_boost::math::hypot(a[0], a[1]);
      double distance_to_point_b = streams_boost::math::hypot(b[0], b[1]);
      double location_of_point = distance_to_point_a / 
                                   (distance_to_point_a + distance_to_point_b);
      if (fraction < location_of_point)
        return point(a[0] * (1 - fraction / location_of_point), 
                     a[1] * (1 - fraction / location_of_point));
      else
        return point(
          b[0] * ((fraction - location_of_point) / (1 - location_of_point)),
          b[1] * ((fraction - location_of_point) / (1 - location_of_point)));
    }
  }

 private:
  shared_ptr<RandomNumberGenerator> gen_ptr;
  shared_ptr<rand_t> rand;
};

} // namespace streams_boost

#endif // STREAMS_BOOST_GRAPH_TOPOLOGY_HPP
