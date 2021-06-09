//
// Created by moaad on 5/15/2021.
//

#ifndef CPPCOURSE_VECTOR2D
#define CPPCOURSE_VECTOR2D


class Vector2d {


private:
    double x, y;

public:

    Vector2d(double x, double y) : x(x), y(y) {};

    double getX() const { return x; }

    double getY() const { return y; }


    Vector2d operator-(const Vector2d &rhs) const;

    Vector2d operator+(const Vector2d &rhs) const;

    Vector2d operator/(double num) const;

    double operator*(const Vector2d &rhs) const;

    bool operator==(const Vector2d &rhs) const;

};

Vector2d operator*(double scalar, const Vector2d &rhs);

double normalizeVec(Vector2d vec);

#endif //CPPCOURSE_VECTOR2D
