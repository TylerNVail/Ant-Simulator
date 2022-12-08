#ifndef WORLD_H
#define WORLD_H

#include "ant.h"
#include "foodmap.h"

class Ant;

class World
{
public:
    World();
    ~World();

    void update();

    double get_number_of_ants();

    void build_vector_of_ants();

    const std::vector<Ant>& get_ants();

protected:
    double numberOfFoods{10};
    double numberOfAnts{300};

    FoodMap foodmap;

    std::vector<Ant> ants;
};

#endif // WORLD_H
