#include "world.h"
#include "ant.h"

World::World()
{
    build_vector_of_ants();
}

World::~World()
{
    ants.clear();
}

void World::update()
{
    for(Ant& a : ants)
    {
        a.update();
    }
}

const std::vector<Ant> &World::get_ants()
{
    return ants;
}

double World::get_number_of_ants()
{
    return numberOfAnts;
}

void World::build_vector_of_ants()
{
    for(int i{0}; i<numberOfAnts; i++)
    {
        Ant a(foodmap);
        ants.push_back(a);
    }
}
