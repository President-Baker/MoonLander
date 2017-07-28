#ifndef LANDER_H
#define LANDER_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "uiInteract.h"
#define HTHRUST 0.1
#define VTHRUST 0.3

class Lander
{
private:
   unsigned int fuel;
   Point point;
   Velocity velocity;
   bool alive;
   bool landed;

public:
   Lander() : point(Point()), velocity(Velocity()), alive(true) {}

   Point getPoint() const
   {
      return point;
   }
   
   Velocity getVelocity() const
   {
      return velocity;
   }

   bool isAlive()
   {
      return alive;
   }

   bool isLanded()
   {
      return landed;
   }

   unsigned int getFuel() const
   {
      return fuel;
   }

   bool canThrust()
   {
		if (getFuel() > 0)
		{
			return true;
		}
		else if (getFuel() <= 0)
		{
			setFuel(0);
			return false;
		}
   }

   void setLanded(bool landed)
   {
      this->landed = landed;
   }

   void setAlive(bool alive)
   {
      this->alive = alive;
   }

   void setFuel(unsigned int fuel)
   {
      this->fuel = fuel;
   }

   void applyGravity(float gravity)
   {
		velocity.setDy(velocity.getDy() + (-gravity));
   }

   void applyThrustLeft()
   {
		if (fuel > 0)
		{
			velocity.setDx(velocity.getDx() + HTHRUST);
			fuel--;
		}
   }

   void applyThrustRight()
   {
		if (fuel > 0)
		{
			velocity.setDx(velocity.getDx() - HTHRUST);
			fuel--;
		}
   }

   void applyThrustBottom()
   {
		if (fuel > 0)
		{
			velocity.setDy(velocity.getDy() + VTHRUST);
			if (fuel < 3)
				fuel = 0;
			else
				fuel -= 3;
		}
   }

   void advance()
   {
		point.addY(velocity.getDy());
		point.addX(velocity.getDx());
   }

   void draw()
   {
      drawLander(point);
   }
};


#endif