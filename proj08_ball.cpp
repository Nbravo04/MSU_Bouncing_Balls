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

#include "proj08_ball.h"
#include "proj08_twod.h"

//Defualt Constructor
//Ball()=default;

//Constructor with supplied args
Ball::Ball(double m, TwoD pos, TwoD speed, double r)
{
  mass = m;
  coords = pos;
  velocity = speed;
  radius = r;
}
/*Using stringstream we set it to fixed and precision(2) and return a Ball as a
string in the form, "m.00, (x.00,y.00), (v_x.00, v_y.00), r.00"
*/
string Ball::to_string()
{
  stringstream ss;
  ss<< fixed << setprecision(2);
  ss<< mass<<", "<<coords.to_string()<<", "<<velocity.to_string()<<", "<< radius;

  return ss.str();
}

//Takes a ball and ball arg. Will return a bool based on whether or not the balls have contact with eachother. I used the distance formula for the two center points of the balls and then i compared it to the radius of both the balls added up together. If the total radius is greater than the distance formula then the balls are touching. 
bool Ball::contact_ball(Ball b)
{
  double t_radius = radius + b.radius;
  double x_1, x_2, y_1, y_2;
//setting up values for dist formula
  x_1 = coords.x;
  y_1 = coords.y;

  x_2 = b.coords.x;
  y_2 = b.coords.y;
//computing dist formula
  double x_sum = x_2 - x_1;
  double y_sum = y_2 - y_1;

  double p_sum = pow(x_sum,2)+pow(y_sum,2);
  double sum = sqrt(p_sum);
//if sum is less than t_radius the balls are touching
  if (sum < t_radius)
    return true;
  else
    return false;
}

//Takes a ball along with the size of our xy-plane and returns a bool whether the ball has contact with the wall.
bool Ball::contact_wall(long xdim, long ydim)
{
  if (coords.x + radius > xdim)
    return true;
  else if (coords.y + radius > ydim)
    return true;
  else if (coords.x - radius < 0)
    return true;
  else if (coords.y - radius < 0)
    return true;
  else
    return false;
}

//Takes two balls that have collided and updates the velocity of the first ball.
TwoD Ball::update_velocity_ball(Ball b)
{
  TwoD v_diff, pos_diff;

//This block is for the 3rd part of the equation
  v_diff = velocity.diff(b.velocity);
  pos_diff = coords.diff(b.coords);
  double pos_mag = pos_diff.magnitude_squared();
  double dot_pro_val = v_diff.dot_product(pos_diff);
  double vd_sum = dot_pro_val / pos_mag;

//This block is for the second part of the equation 
  double mass_top, mass_bot, t_mass;
  mass_top = 2*b.mass;
  mass_bot = mass + b.mass;
  t_mass = mass_top / mass_bot;

//The rest of the function is just multipling and calling other functions to solve for the new vector speed
  double sum = t_mass * vd_sum;

  auto vec_sum = pos_diff.mult(sum);

  auto updated_velo = velocity.diff(vec_sum);

  return updated_velo;  
}

//Takes a TwoD element and checks to see if it has hit either side of the x plane and also does the same for the y plane. This function then flips the sign associated with the x or y value.
TwoD Ball::update_velocity_wall(long xdim, long ydim)
{
  TwoD n_val;
  if (coords.x + radius > xdim or coords.x - radius <0)
  {
    n_val.x = velocity.x *-1;
    n_val.y = velocity.y;
  }
  if (coords.y + radius > ydim or coords.y - radius <0)
  {
    n_val.y = velocity.y *-1;
    n_val.x = velocity.x;
  }
  return n_val;
}
