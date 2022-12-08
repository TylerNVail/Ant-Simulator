#include "utilities.h"

Utilities::Utilities(){}

Vector3D Utilities::rotate_vector(double angleRadians, const Vector3D &vector)
{
    Vector3D rotatedVector = vector;
    double cs = cos(angleRadians);
    double sn = sin(angleRadians);

    double x = vector[0] * cs - vector[1] * sn;
    double y = vector[0] * sn + vector[1] * cs;
    rotatedVector[0]=x;
    rotatedVector[1]=y;

    return rotatedVector;
}

const bool Utilities::check_range(const Vector3D &antPostion,const Vector3D &foodPostion)
{
    bool antHasFoodOrNot{false};

    double antMagitude = antPostion.calculate_magnitude();
    double foodMagitude = foodPostion.calculate_magnitude();

    if(antMagitude - foodMagitude<howCloseDoesFoodHaveToBe)
    {
        antHasFoodOrNot=true;
    }

    return antHasFoodOrNot;
}
