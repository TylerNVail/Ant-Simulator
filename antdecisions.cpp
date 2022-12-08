#include "antdecisions.h"
#include "randomnumbergenerator.h"
#include "utilities.h"

AntDecisions::AntDecisions(){}

Vector3D AntDecisions::calculate_new_oriention(const Vector3D &orention) //save testing for later
{
    RandomNumberGenerator randomNumber;

    Utilities utilities;

    double newAngle=randomNumber.generate_random_number(minimumAngleOfTurn,maximumAngleOfTurn);

    Vector3D newOriention=utilities.rotate_vector(newAngle, orention);

    return newOriention;

}
