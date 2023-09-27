#include <iostream>

class IPolygon {
    public:
        IPolygon() = default;
        virtual double computeArea() const = 0;
        virtual ~IPolygon() = default;
};

class Square : public IPolygon {
    private:
        double side{};

    public:
        Square(double measureSide): side{ measureSide } {}
        double computeArea() const override { return side * side; }
        ~Square() = default;
};

class Rectangle : public IPolygon {
    private:
        double base{};
        double height{};

    public:
        Rectangle(double measureBase, double measureHeight): base{ measureBase }, height{ measureHeight } {}
        double computeArea() const override { return base * height; }
        ~Rectangle() = default;
};

class Triangle : public IPolygon {
    private:
        double base{};
        double height{};

    public:
        Triangle(double measureBase, double measureHeight): base{ measureBase }, height{ measureHeight } {}
        double computeArea() const override { return base * height / 2; }
        ~Triangle() = default;
};

double computePolygonArea(const IPolygon& polygon) {
    return polygon.computeArea();
}

int main() {
    IPolygon* square{ new Square{ 2.0 } };
    IPolygon* rectangle{ new Rectangle{ 3.0, 4.0 } };
    IPolygon* triangle{ new Triangle{ 2.0, 3.0 } };

    std::cout << "Square area => " << computePolygonArea(*square) << '\n'
        << "Rectangle area => " << computePolygonArea(*rectangle) << '\n'
        << "Triangle area => " << computePolygonArea(*triangle) << '\n';
}