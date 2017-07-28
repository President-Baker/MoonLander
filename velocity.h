#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float Dx;
   float Dy;

public:
   Velocity() : Dx(0.0), Dy(0.0)
   {}

   Velocity(float Dx, float Dy) 
   {
      this->Dx = Dx;
      this->Dy = Dy;
   }

   float getDx()
   {
      return Dx;
   }

   float getDy()
   {
      return Dy;
   }

   void setDx(float Dx)
   {
      this->Dx = Dx;
   }

   void setDy(float Dy)
   {
      this->Dy = Dy;
   }
};

#endif