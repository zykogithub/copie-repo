#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double M_PI = 3.141592; // utilisé car mon compilateur ne trouve pas M_PI dans cmaths

class Area{
    private :
        string _shape;
        double _width,_height,_radius;
        double areaRectangle(){
            return _width*_height;
        }
        double areaCircule(){
            return M_PI * _radius * _radius;
        }
        double areaSquare(){
            return _width * _width;
        }
        void invalidArgument(){
            cerr << "Invalid shape!" << endl;
        }
    public : 
        Area(const string& shape,double width,double height,double radius){
            _shape = shape;
            _width = width;
            _height = height;
            _radius = radius;
        }
        double getArea() {
            if (_shape == "circle") return areaCircule();
                
            else if (_shape == "square") return areaSquare();
                
            else if (_shape == "rectangle") return areaRectangle();
                
            else invalidArgument();
        }
        


};

int main() {
    Area f1(string("circle"), 0.0, 0.0, 5.0);
    cout << "Area of circle: " << f1.getArea() << endl;

    Area f2(string("square"), 4.0, 0.0, 0.0);
    cout << "Area of square: " << f2.getArea()<< endl;

    Area f3(string("rectangle"), 3.0, 5.0, 0.);
    cout << "Area of rectangle: " << f3.getArea() << endl;

    return 0;
}