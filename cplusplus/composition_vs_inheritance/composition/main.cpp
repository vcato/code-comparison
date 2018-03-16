#include <iostream>
#include <vector>
#include <cassert>
#include <memory>


using std::ostream;
using std::vector;
using std::cout;
using std::unique_ptr;
using std::make_unique;


namespace {
struct Position {
  float x = 0;
  float y = 0;
};
}


namespace {
struct Circle {
  Position center;
  float radius = 1;

  void printOn(ostream &stream) const
  {
    stream <<
      "Circle: "
      "center_x=" << center.x << ", "
      "center_y=" << center.y << ", "
      "radius=" << radius << "\n";
  }
};
}


namespace {
struct Square {
  Position center;
  float size;

  void printOn(ostream &stream) const
  {
    stream <<
      "Square: "
      "center_x=" << center.x << ", "
      "center_y=" << center.y << ", "
      "size=" << size << "\n";
  }
};
}


namespace {
struct Printable {
  virtual void printOn(ostream &) const = 0;
};
}


namespace {
template <typename T>
struct PrintableRef : Printable {
  const T &ref;

  PrintableRef(const T &arg)
  : ref(arg)
  {
  }

  void printOn(ostream &stream) const override
  {
    ref.printOn(stream);
  }
};
}


static void
  printAllOn(ostream &stream,const vector<Printable *> &printable_ptrs)
{
  for (auto *printable_ptr : printable_ptrs) {
    assert(printable_ptr);
    printable_ptr->printOn(stream);
  }
}


int main()
{
  Circle circle;

  circle.center = {1,2};
  circle.radius = 3;

  Square square;

  square.center = {10,11};
  square.size = 12;

  PrintableRef<Circle> printable_circle(circle);
  PrintableRef<Square> printable_square(square);

  printAllOn(cout,{&printable_circle,&printable_square});
}
