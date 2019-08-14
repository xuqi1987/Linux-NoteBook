//
// Created by xuqi on 2019-08-14.
//

#include <memory>
#include <iostream>

using namespace std;

class A {
 public:
  A() {cout << "A" << endl;};
  ~A() {cout << "~A" << endl;};
};

void fun(shared_ptr<A> ptr) {
  cout << ptr.use_count()<< endl;;
}

int main()
{
  shared_ptr<A> a = make_shared<A>();

  shared_ptr<A> c = make_shared<A>();

  cout << a.use_count()<< endl;;

  fun(a);

  {
    shared_ptr<A> b = a;
    cout << a.use_count()<< endl;
    a = c;

    cout << b.use_count()<< endl;
  }

  cout << a.use_count()<< endl;

  return 0;
}