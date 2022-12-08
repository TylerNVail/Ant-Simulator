#ifndef FOOD_H
#define FOOD_H

#include "vector3d.h"

#include <vector>

class Food
{
public:
    Food();

    const Vector3D& get_postion();

protected:
    Vector3D postion;
};

#endif // FOOD_H
