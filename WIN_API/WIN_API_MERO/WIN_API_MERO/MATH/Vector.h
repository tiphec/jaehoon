#pragma once
#include <math.h>

class Vector {

public:
    Vector() :_x(0.0f), _y(0.0f) {


    }

    Vector(float x, float y) : _x(x), _y(y) {


    }

    Vector(const Vector& other) : _x(other._x), _y(other._y) {


    }

    ~Vector() {


    }


    float& operator[](int temp) {

        if (temp == 0) {

            return _x;

        }
        else {

            return _y;
        }
    }

    Vector operator+(const Vector& other) const {



        Vector result;

        result._x = this->_x + other._x;
        result._y = this->_y + other._y;

        return result;

    }

    Vector operator-(const Vector& other) const {

        Vector result;

        result._x = this->_x - other._x;
        result._y = this->_y - other._y;

        return result;
    }
    float Dot(const Vector& other) {

        float result;

        result = (this->_x * other._x) + (this->_y * other._y);

        return result;
    }
    float Cross(const Vector& other) {

        float result;

        result = (this->_x * other._y) - (this->_y * other._x);

        return result;

    }
    float Length() {

        return sqrtf((_x * _x) + (_y * _y));
    }
    Vector operator*(const float& value) const
    {
        return Vector(_x * value, _y * value);
    }
    Vector NormalVector() 
    {
        return Vector(_x / Length(), _y / Length());
    }

public:
    float _x;
    float _y;

};
