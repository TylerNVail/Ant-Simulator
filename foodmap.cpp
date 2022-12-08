#include "foodmap.h"

#include "food.h"
#include "utilities.h"

FoodMap::FoodMap()
{
    build_vector_of_food();
}

void FoodMap::build_vector_of_food()
{
    for(int i{0}; i<numberOfFood; i++)
    {
        Food f;
        foodlist.push_back(f);
    }
}

const bool FoodMap::compare_ant_location_and_food_location(Vector3D& antPostion)
{
    Utilities utilities;

    bool antHasFoodOrNot{false};

    for(Food& f : foodlist)
    {
        const Vector3D& foodPostion=f.get_postion();

        antHasFoodOrNot=utilities.check_range(antPostion, foodPostion);
    }
    return antHasFoodOrNot;
}

const std::vector<Food> &FoodMap::get_food()
{
    return foodlist;
}
