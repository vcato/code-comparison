#include <iostream>
#include <vector>
#include <cassert>


using std::ostream;
using std::vector;
using std::cout;


namespace {
struct Printable {
  virtual void printOn(ostream &) const = 0;
};
}


namespace {
struct Circle : Printable {
  float center_x = 0;
  float center_y = 0;
  float radius = 1;

  void printOn(ostream &stream) const override
  {
    stream <<
      "Circle: "
      "center_x=" << center_x << ", "
      "center_y=" << center_y << ", "
      "radius=" << radius << "\n";
  }
};
}


namespace {
struct Square : Printable {
  float center_x;
  float center_y;
  float size;

  void printOn(ostream &stream) const override
  {
    stream <<
      "Square: "
      "center_x=" << center_x << ", "
      "center_y=" << center_y << ", "
      "size=" << size << "\n";
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

  circle.center_x = 1;
  circle.center_y = 2;
  circle.radius = 3;

  Square square;

  square.center_x = 10;
  square.center_y = 11;
  square.size = 12;

  printAllOn(cout,{&circle,&square});
}
