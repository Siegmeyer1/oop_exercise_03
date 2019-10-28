#ifndef OOP_EXERCISE_03_FIGURE_H
#define OOP_EXERCISE_03_FIGURE_H


class Dot {
public:
    double x;
    double y;
    Dot();
    Dot(double X, double Y);
    Dot& operator=(const Dot &A);
    Dot operator+(const Dot &A);
    Dot operator-(const Dot &A);
    Dot operator/(const double &A);
    friend std::ostream &operator<<(std::ostream &os, const Dot& A);
    friend std::istream &operator>>(std::istream &is, Dot& A);
    double Length(const Dot &A);
};

Dot operator""_dot(const char* str, size_t size);

class Figure {
public:
    virtual Dot Center() = 0;
    virtual void PrintOut(std::ostream& os) = 0;
    virtual double Area() = 0;
    virtual ~Figure() = default;
};

class Octagon : public Figure {
private:
    Dot* coordinates;
public:
    Octagon();
    explicit Octagon(std::istream& is);
    Dot Center() override;
    void PrintOut(std::ostream& os) override;
    double Area() override;
    ~Octagon() override;
};


class Triangle : public Figure {
private:
    Dot *coordinates;
public:
    Triangle();
    explicit Triangle(std::istream& is);
    Dot Center() override;
    void PrintOut(std::ostream& os) override;
    double Area() override;
    ~Triangle() override;
};

class Square : public Figure {
private:
    Dot *coordinates;
public:
    Square();
    explicit Square(std::istream& is);
    Dot Center() override;
    double Area() override;
    void PrintOut(std::ostream& os) override;
    ~Square() override;
};


#endif //OOP_EXERCISE_03_FIGURE_H
