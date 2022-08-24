#ifndef SORT
#define SORT
#include <algorithm>
#include <iterator>
#include "shape.h"
/*
class Sort{
  public:
    Sort(std::vector<Shape *> *shapes) : _shapes(shapes) {}
    template <class Compare>
    void sortArea(Compare comp)
    {
        std::sort(_shapes->begin(), _shapes->end(), comp);
    }

    template <class Compare>
    void sortPerimeter(Compare comp)
    {
        std::sort(_shapes->begin(), _shapes->end(), comp);
    }

    template <class Compare>
    void _quickSort(Compare comp)
    {
        quickSort(_shapes->begin(), _shapes->end()- 1, comp);
    }
    std::vector<Shape *> *_shapes;
};*/
/*
template <class RandomAccessIterator, class Compare>
RandomAccessIterator _partition(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
    RandomAccessIterator i = first-1;
    RandomAccessIterator j ;
    for(j = first; j<last; j++){
      if(comp(*j, *last)){
          i++;
          std::iter_swap(i, j);
      }
    }
    std::iter_swap(i + 1, last);
    return i + 1;
}*/

template <class RandomAccessIterator, class Compare>
RandomAccessIterator _partition2(RandomAccessIterator first, RandomAccessIterator last, Compare comp){
    auto pivit = std::prev(last,1);
    auto i = first;
    for(auto j = first; j!=pivit; ++j){
      if(comp(*j, *pivit)){
          std::swap(*i++, *j);
      }
    }
    std::swap(*i, *pivit);
    return i;
}

template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
  if (first < last)
  {
      RandomAccessIterator q = _partition2(first, last, comp);
      quickSort(first, q , comp);
      quickSort(q + 1, last, comp);
  }
}

auto lambdaAreaAscending = [](Shape *a, Shape *b) { return a->area() < b->area(); };
auto lambdaPerimeterAscending = [](Shape *a, Shape *b) { return a->perimeter() < b->perimeter(); };
auto lambdaAreaDescending = [](Shape *a, Shape *b) { return a->area() > b->area(); };
auto lambdaPerimeterDescending = [](Shape *a, Shape *b) { return a->perimeter() > b->perimeter(); };

bool areaAscendingCompare(Shape *a, Shape *b) {
  return a->area()<b->area();
};

bool areaDescendingCompare(Shape *a, Shape *b) {
  return a->area()>b->area();
};

bool perimeterAscendingCompare(Shape *a, Shape *b) {
  return a->perimeter()<b->perimeter();
};

bool perimeterDescendingCompare(Shape *a, Shape *b) {
  return a->perimeter()>b->perimeter();
};

class AscendingCompare{
  public:
    AscendingCompare(std::string feature): feature(feature) {}
    std::string feature;
    bool operator()(Shape *a, Shape *b)
    {
        if (feature == "area")
            return a->area() < b->area();
        else if (feature == "perimeter")
            return a->perimeter() < b->perimeter();
        else
            throw "Wrong constructor parameter";
    }
};

class DescendingCompare{
  public:
    DescendingCompare(std::string feature): feature(feature) {}
    std::string feature;
    bool operator()(Shape *a, Shape *b)
    {
        if (feature == "area")
            return a->area() > b->area();
        else if (feature == "perimeter")
            return a->perimeter() > b->perimeter();
        else
            throw "Wrong constructor parameter";
    }
};

#endif
