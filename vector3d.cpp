#include "vector3d.h"
#include <cmath>

Vector3D::Vector3D(){}

Vector3D::Vector3D(double x, double y, double z):components{x,y,z}{}

double& Vector3D::operator[](double componentNeeded)
{
    return(components[componentNeeded]);
}

double Vector3D::calculate_magnitude() const
{
    double magnitudeSquared{0.0};
    magnitudeSquared += components[0]*components[0];
    magnitudeSquared += components[1]*components[1];
    magnitudeSquared += components[2]*components[2];

    return sqrt(magnitudeSquared);
}

const double& Vector3D::operator[](double componentNeeded) const
{
    return(components[componentNeeded]);
}

Vector3D operator+(const Vector3D& vector,const Vector3D& vector2)
{
    Vector3D vectorsAdded{0.0,0.0,0.0};
    vectorsAdded[0]=vector[0]+vector2[0];
    vectorsAdded[1]=vector[1]+vector2[1];
    vectorsAdded[2]=vector[2]+vector2[2];

    return vectorsAdded;
}

Vector3D operator-(const Vector3D& vector,const Vector3D& vector2)
{
    Vector3D subtractedVector{0.0,0.0,0.0};
    subtractedVector[0]=vector[0]-vector2[0];
    subtractedVector[1]=vector[1]-vector2[1];
    subtractedVector[2]=vector[2]-vector2[2];

    return subtractedVector;
}

Vector3D operator*(const Vector3D& vector,const double& scalar)
{
    Vector3D multipliedByScalar{0.0,0.0,0.0};

    multipliedByScalar[0]=vector[0]*scalar;
    multipliedByScalar[1]=vector[1]*scalar;
    multipliedByScalar[2]=vector[2]*scalar;

    return multipliedByScalar;
}

Vector3D operator*(const double& scalar, const Vector3D& vector)
{
    Vector3D multipliedByScalar{0.0,0.0,0.0};
    multipliedByScalar[0]=scalar*vector[0];
    multipliedByScalar[1]=scalar*vector[1];
    multipliedByScalar[2]=scalar*vector[2];

    return multipliedByScalar;
}

Vector3D operator/(const Vector3D& vector,const double& scalar)
{
    Vector3D dividedByScalar{0.0,0.0,0.0};

    dividedByScalar[0]=vector[0]/scalar;
    dividedByScalar[1]=vector[1]/scalar;
    dividedByScalar[2]=vector[2]/scalar;

    return dividedByScalar;
}

double calculate_square_magnitude(const Vector3D& vector)
{
    double magnitudeSquared{0.0};
    magnitudeSquared += vector[0]*vector[0];
    magnitudeSquared += vector[1]*vector[1];
    magnitudeSquared += vector[2]*vector[2];
    return magnitudeSquared;
}

double calculate_magnitude(const Vector3D& vector)
{
    double magnitude{0.0};
    magnitude=sqrt(calculate_square_magnitude(vector));
    return magnitude;
}

Vector3D normalize(const Vector3D& vector)
{
    std::array<double,3> normalize{0.0,0.0,0.0};

    normalize[0]=vector[0]/calculate_magnitude(vector);
    normalize[1]=vector[1]/calculate_magnitude(vector);
    normalize[2]=vector[2]/calculate_magnitude(vector);

    return Vector3D{normalize[0],normalize[1],normalize[2]};
}

Vector3D calculate_cross_product(const Vector3D& vector1,const Vector3D& vector2)
{
    Vector3D crossProduct{0.0,0.0,0.0};

    crossProduct[0]=(vector1[1]*vector2[2])-(vector1[2]*vector2[1]);
    crossProduct[1]=(vector1[2]*vector2[0])-(vector1[0]*vector2[2]);
    crossProduct[2]=(vector1[0]*vector2[1])-(vector1[1]*vector2[0]);

    return Vector3D{crossProduct[0],crossProduct[1],crossProduct[2]};
}

double calculate_dot_product(const Vector3D& vector1,const Vector3D& vector2)
{
    Vector3D multiplyVectors{0.0,0.0,0.0};

    multiplyVectors[0]=vector1[0]*vector2[0];
    multiplyVectors[1]=vector1[1]*vector2[1];
    multiplyVectors[2]=vector1[2]*vector2[2];

    double dotProduct{0.0};

    dotProduct=(multiplyVectors[0]+multiplyVectors[1]+multiplyVectors[2]);

    return dotProduct;
}
