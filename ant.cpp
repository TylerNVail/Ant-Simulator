#include "ant.h"
#include "antdecisions.h"

Ant::Ant(FoodMap& food) : foodmap{food}{}

const Vector3D &Ant::get_postion() const
{
    return postion;
}

void Ant::update()
{
    AntDecisions antDecisions;

    orention=antDecisions.calculate_new_oriention(orention);
    postion=postion+orention*speed;
}
