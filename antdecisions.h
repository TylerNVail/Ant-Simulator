#ifndef ANTDECISIONS_H
#define ANTDECISIONS_H

#include "vector3d.h"

class AntDecisions
{
public:
    AntDecisions();

    Vector3D calculate_new_oriention(const Vector3D& orention);

protected:
    double minimumAngleOfTurn{-.4};
    double maximumAngleOfTurn{.4};
};

#endif // ANTDECISIONS_H
