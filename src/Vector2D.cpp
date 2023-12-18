#include "Vector2D.h"

Vector2D::Vector2D(int x, int y) : x(x), y(y) {}

int Vector2D::getX() const {
    return x;
}

int Vector2D::getY() const {
    return y;
}

void Vector2D::setX(int v) {
    x = v;
}

void Vector2D::setY(int v) {
    y = v;
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator*=(int scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(int scalar) {
    if (scalar == 0) throw std::invalid_argument("Division by zero");
    x /= scalar;
    y /= scalar;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(int scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(int scalar) const {
    if (scalar == 0) throw std::invalid_argument("Division by zero");
    return Vector2D(x / scalar, y / scalar);
}

bool Vector2D::operator==(const Vector2D& oth)
{
    if(this->getX() == oth.getX() && this->getY() == oth.getY()) return true;
    return false;
}
