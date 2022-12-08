#ifndef FOODMAP_H
#define FOODMAP_H

#include "vector3d.h"
#include "food.h"

class FoodMap
{
public:
    FoodMap();

    void build_vector_of_food();

    const bool compare_ant_location_and_food_location(Vector3D& antPostion);

    const std::vector<Food> &get_food();

protected:
    std::vector<Food> foodlist;

    double numberOfFood{5};
};

#endif // FOODMAP_H
