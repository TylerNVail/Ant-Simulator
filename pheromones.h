#ifndef PHEROMONES_H
#define PHEROMONES_H

#include <iostream>
#include <vector>

class Pheromones
{
public:
    Pheromones();

    double addPheromonesLocation(double antLocation);

private:
    double pheromoneLocation;
};

#endif // PHEROMONES_H
