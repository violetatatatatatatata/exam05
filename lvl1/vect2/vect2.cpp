#include "vect2.hpp"

vect2::vect2()
{
    _x = 0;
    _y = 0;
}

vect2::vect2(int num1, int num2)
{
    _x = num1;
    _y = num2;
}

vect2::vect2(const vect2 &obj)
{
    *this = obj;
}

vect2 &vect2::operator=(const vect2 &obj)
{
    if (this != &obj)
    {
        _x = obj._x;
        _y = obj._y;
    }
    return *this;
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return _x;
    return _y;
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return _x;
    return _y;
}

vect2 &vect2::operator++()
{
    ++_x;
    ++_y;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    ++_x;
    ++_y;
    return tmp;
}

vect2 &vect2::operator--()
{
    --_x;
    --_y;
    return *this;
}

vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    --_x;
    --_y;
    return tmp;
}

vect2 &vect2::operator+=(const vect2 &obj)
{
    _x = _x + obj._x;
    _y = _y + obj._y;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &obj)
{
    _x = _x - obj._x;
    _y = _y - obj._y;
    return *this;
}

vect2 &vect2::operator*=(int num)
{
    _x = _x * num;
    _y = _y * num;
    return *this;
}

vect2 vect2::operator+(const vect2 &obj) const
{
    vect2 tmp(*this);
    tmp._x = tmp._x + obj._x;
    tmp._y = tmp._y + obj._y;
    return tmp;
}

vect2 vect2::operator-(const vect2 &obj) const
{
    vect2 tmp(*this);
    tmp._x = tmp._x - obj._x;
    tmp._y = tmp._y - obj._y;
    return tmp;
}

vect2 vect2::operator*(int num) const
{
    vect2 tmp(*this);
    tmp._x = tmp._x * num;
    tmp._y = tmp._y * num;
    return tmp;
}

vect2 vect2::operator-() const
{
    vect2 tmp(*this);
    tmp._x = -tmp._x;
    tmp._y = -tmp._y;
    return tmp;
}

bool vect2::operator==(const vect2 &obj) const
{
    if ((_x == obj._x) && (_y == obj._y))
        return true;
    return false;
}

bool vect2::operator!=(const vect2 &obj) const
{
    return (!(*this == obj));
}

vect2 operator*(int num, const vect2 &obj)
{
    vect2 tmp(obj);
    tmp *= num;
    return tmp;
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
    os << "{" << obj[0] << ", " << obj[1] << "}";
    return os;
}