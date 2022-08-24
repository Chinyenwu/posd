
class Rectangle {
public:
  Rectangle(double width, double height) {
    _width = width;
    _height = height;
  }

  double area() const {
    return _width * _height;
  }
private:
  //data members
  double _width, _height;
};
