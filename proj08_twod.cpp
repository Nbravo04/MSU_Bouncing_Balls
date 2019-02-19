/*
Nicholas Bravata
Project 08 Bouncing Balls
Section 003
11/5/2017
*/
#include<iostream>
using std::fixed;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <cmath>
using std::pow; using std::sqrt;
#include <iomanip>
using std::setprecision;

#include "proj08_twod.h"

//Default constructor
//TwoD()=default;
//Constructor with 2 elements
TwoD::TwoD(double xval, double yval)
{
  x = xval;
  y = yval;
}

/*Using stringstream we set it to fixed and precision(2) and return a TwoD as a
string in the form, "(x.00,y.00)"
*/
string TwoD::to_string()
{
  stringstream ss;
  ss << fixed << setprecision(2);
  ss <<"("<<x<<", "<<y<<")";
  return ss.str();
}

//Calculates the difference between two TwoD elements
TwoD TwoD::diff(TwoD val)
{
  TwoD n_val;

  n_val.x = x - val.x;
  n_val.y = y - val.y;

  return n_val;
}

//Calculates the product of a TwoD element with a double that is passed into the funct.
TwoD TwoD::mult(double val)
{
  TwoD n_val;

  n_val.x = x * val;
  n_val.y = y * val;

  return n_val;
}

//Calculates the product of two TwoD elements and returns a new TwoD
double TwoD::dot_product(TwoD val)
{
  TwoD n_val;

  n_val.x = x * val.x;
  n_val.y = y * val.y;

  double r_val = n_val.x + n_val.y;

  return r_val;
}

//Calculates the magnitude_squared of TwoD element and returns a double
double TwoD::magnitude_squared()
{
  x = pow(x,2);
  y = pow(y,2);

  double r_val = x+y;

  return r_val;
}
