#ifndef UTILITIES_H
#define UTILITIES_H

#include "vector3d.h"

class Utilities
{
public:
    Utilities();

    Vector3D rotate_vector(double angleRadians, const Vector3D& vector);

    const bool check_range(const Vector3D& antPostion,const Vector3D& foodPostion);

protected:
    double howCloseDoesFoodHaveToBe{1};
};

#endif // UTILITIES_H
