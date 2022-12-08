#ifndef VECTOR3D_H
#define VECTOR3D_H
#include <array>
#include <vector>

class Vector3D
{
public:
    Vector3D();
    Vector3D(double x, double y, double z);

    double& operator[](double componentNeeded);
    const double& operator[](double componentNeeded) const;

    double calculate_magnitude() const;

protected:
    std::array<double,3> components{0.0,0.0,0.0};
};

Vector3D operator+(const Vector3D& vector, const Vector3D& vector2);
Vector3D operator-(const Vector3D& vector,const Vector3D& vector2);
Vector3D operator*(const Vector3D& vector,const double& scalar);
Vector3D operator*(const double& scalar,const Vector3D& vector);
Vector3D operator/(const Vector3D& vector,const double& scalar);

#endif // VECTOR3D_H


double calculate_square_magnitude(const Vector3D& vector);
double calculate_magnitude(const Vector3D& vector);

Vector3D normalize(const Vector3D& vector);

Vector3D calculate_cross_product(const Vector3D& vector1,const Vector3D& vector2);
double calculate_dot_product(const Vector3D& vector1,const Vector3D& vector2);
