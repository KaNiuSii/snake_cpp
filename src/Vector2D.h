#ifndef W_VECTOR2D_H
#define W_VECTOR2D_H

#include <stdexcept>

class Vector2D {
private:
    int x, y;

public:
    Vector2D(int x = 0, int y = 0);

    int getX() const;
    int getY() const;

    void setX(int v);
    void setY(int v);

    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(int scalar);
    Vector2D& operator/=(int scalar);

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(int scalar) const;
    Vector2D operator/(int scalar) const;

    bool operator==(const Vector2D& oth);
};

#endif //W_VECTOR2D_H
