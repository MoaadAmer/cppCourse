//
// Created by moaad on 5/15/2021.
//

#include "Vector2d.h"
#include "math.h"


Vector2d Vector2d::operator-(const Vector2d &rhs) const {

    Vector2d v(x - rhs.getX(), y - rhs.y);
    return v;
}

Vector2d Vector2d::operator/(double num) const {
    return Vector2d(x / num, y / num);
}

double Vector2d::operator*(const Vector2d &rhs) const {
    return x * rhs.getX() + y * rhs.getY();
}

Vector2d Vector2d::operator+(const Vector2d &rhs) const {
    return Vector2d(x + rhs.getX(), y + rhs.getY());
}

bool Vector2d::operator==(const Vector2d &rhs) const {
    return (x == rhs.getX()) && (y == rhs.getY());
}

Vector2d operator*(double scalar, const Vector2d &rhs) {
    return Vector2d(scalar * rhs.getX(), scalar * rhs.getY());
}
//
//Vector2d Vector2d::operator*(double scalar) const {
//    return Vector2d(x * scalar, y * scalar);
//}

double normalizeVec(Vector2d vec) {
    return sqrt(vec.getX() * vec.getX() + vec.getY() * vec.getY());
}
