#ifndef ANT_H
#define ANT_H

#include "vector3d.h"

class FoodMap;

class Ant
{
public:
    Ant(FoodMap& food);

    void update();

    const Vector3D& get_postion() const;

protected:
    bool hasFood{false};

    double speed{1.0};

    Vector3D postion;
    Vector3D orention{0,1,0};

    FoodMap& foodmap;
};

#endif // ANT_H
