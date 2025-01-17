#include <iostream>
#include <cmath>
#include <istream>
#include <ostream>

class point 
{
    public:
        typedef double value_type;
        // constructores son funciones miembros especiales
        explicit point(value_type x = 0.0, value_type y = 0.0);
        void x(value_type x)  { itsX = x; }    // estos son algo como los setters
        void y(value_type y)  { itsY = y; }
        value_type x()  const { return itsX; } // al parecer esto seria algo similar a un getter
        value_type y()  const { return itsY; }
        
        value_type distance() const;
        bool operator == (const point& pt) const;
        inline static point origin();
    
    private:
        value_type itsX;
        value_type itsY;
};

// constructor
point::point (value_type x, value_type y) 
: itsX(x), itsY(y) 
{}

point::value_type point::distance() const 
{
    return std::sqrt(x() * x() + y() * y());
}

bool point::operator == (const point& pt)
const
{
    return x() == pt.x() && y() == pt.y();
}

inline point point::origin()
{
    return point();
}

int main (int argc, char **argv)
{
    point p1;
    point::value_type n;

    std::cin >> n;
    p1.x(n);
    std::cin >> n;
    p1.y(n);

    if (p1 == point::origin()){
        std::cout << "origin" << std::endl;
    }
    else {
        std::cout << p1.distance() << std::endl; 
    }
    return 0;
}