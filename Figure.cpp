#include <iostream>
#include <sstream>
#include <cmath>
#include "Figure.h"

//Методы класса Dot

Dot::Dot() {
    x = 0;
    y = 0;
}

Dot::Dot(double X, double Y) {
    x = X;
    y = Y;
}



Dot operator""_dot(const char* str, size_t size) {
    std::istringstream is(str);
    char tmp;
    double x, y;
    is >> x >> tmp >> y;
    return {x, y};
}

Dot& Dot::operator=(const Dot &A) {
    this->x = A.x;
    this->y = A.y;
    return *this;
}

Dot Dot::operator+(const Dot &A) {
    Dot res;
    res.x = this->x + A.x;
    res.y = this->y + A.y;
    return res;
}

Dot Dot::operator-(const Dot &A) {
    Dot res;
    res.x = this->x - A.x;
    res.y = this->y - A.y;
    return res;
}

Dot Dot::operator/(const double &A) {
    Dot res;
    res.x = this->x / A;
    res.y = this->y / A;
    return res;
}

std::ostream &operator<<(std::ostream &os, const Dot& A) {
    os << "(" << A.x << "; " << A.y << ")";
    return os;
}

std::istream &operator>>(std::istream &is, Dot& A) {
    is >> A.x >> A.y;
    return is;
}

double Dot::Length(const Dot &A) {
    double res;
    res = sqrt(pow(this->x - A.x, 2) + pow(this->y - A.y, 2));
    return res;
}

//конец Dot

//Методы класса Octagon

double Octagon::Area() {
    double res = 4*sin(0.785398)*pow(this->Center().Length(this->coordinates[0]), 2);
    return res;
}

Dot Octagon::Center() {
    Dot res(0, 0);
    for (int i = 0; i < 8; ++i) {
        res = res + coordinates[i];
    }
    res = res / 8.0;
    return res;
}

void Octagon::PrintOut(std::ostream& os) {
    for (int i = 0; i < 8; ++i) {
        os << this->coordinates[i];
        if (i != 7) {
            os << ", ";
        }
    }
    os << '\n';
}

Octagon::Octagon() {
    coordinates = new Dot[8];
    for (int i = 0; i < 8; ++i) {
        coordinates[i] = "0.0 0.0"_dot;
    }
}

Octagon::Octagon(std::istream &is) {
    coordinates = new Dot[8];
    for (size_t i = 0; i < 8; ++i) {
        is >> coordinates[i];
    }
}

Octagon::~Octagon() {
    delete[] this->coordinates;
}

//конец Octagon

//методы класса Triangle

Triangle::Triangle() {
    coordinates = new Dot[3];
    for (int i = 0; i < 3; ++i) {
        coordinates[i] = "0.0 0.0"_dot;
    }
}

Triangle::Triangle(std::istream &is) {
    coordinates = new Dot[3];
    for (size_t i = 0; i < 3; ++i) {
        is >> coordinates[i];
    }
}

Dot Triangle::Center() {
    Dot res(0, 0);
    for (int i = 0; i < 3; ++i) {
        res = res + coordinates[i];
    }
    res = res / 3.0;
    return res;
}

double Triangle::Area() {
    double x1 = this->coordinates[0].x;
    double x2 = this->coordinates[1].x;
    double x3 = this->coordinates[2].x;
    double y1 = this->coordinates[0].y;
    double y2 = this->coordinates[1].y;
    double y3 = this->coordinates[2].y;

    double res = std::abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / 2;
    return res;
}

void Triangle::PrintOut(std::ostream& os) {
    for (int i = 0; i < 3; ++i) {
        os << this->coordinates[i];
        if (i != 2) {
            os << ", ";
        }
    }
    os << '\n';
}

Triangle::~Triangle() {
    delete[] coordinates;
}

//конец Triangle

//методы класса Square

Square::Square() {
    coordinates = new Dot[2];
    for (int i = 0; i < 2; ++i) {
        coordinates[i] = "0.0 0.0"_dot;
    }
}

Square::Square(std::istream &is) {
    coordinates = new Dot[2];
    for (size_t i = 0; i < 2; ++i) {
        is >> coordinates[i];
    }
}

Dot Square::Center() {
    Dot res = (this->coordinates[0] + this->coordinates[1]) / 2;
    return res;
}

double Square::Area() {
    double res = this->coordinates[0].Length(this->coordinates[1]);
    res = pow(res , 2) / 2;
    return  res;
}

void Square::PrintOut(std::ostream& os) {
    Dot C = this->Center();
    double tmp;
    Dot res[2];
    for (int i = 0; i < 2; ++i) {
        res[i] = this->coordinates[i];
        res[i] = res[i] - C;
        tmp = res[i].y;
        res[i].y = res[i].x;
        res[i].x = -tmp;
        res[i] = res[i] + C;
    }
    os << res[0] << ", " << this->coordinates[0] << ", "
    << res[1] << ", " << this->coordinates[1] << '\n';
}

Square::~Square() {
    delete[] coordinates;
}