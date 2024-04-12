// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include "four_momentum.h"

int main()
{
  // Testing Four-Momentum
  FourMomentum fm1;
  FourMomentum fm2{3.0, 4.0, 5.0, -6.0};
  //fm1.print_info();
  //fm2.print_info();

  FourMomentum fm3{fm2};
  fm3.set_energy(4530323.34);
  fm3.set_px(2.323); fm3.set_py(-124.12); fm3.set_pz(-2.12123);
  //fm3.print_info();

  FourMomentum fm4;
  fm4 = fm3;
  //fm4.print_info();

  FourMomentum fm5{std::move(fm2)};
  //fm5.print_info();
  //fm2.print_info();

  FourMomentum fm6;
  fm6 = std::move(fm3);
  //fm6.print_info();

  vector<double> fm6_vec = fm6.get_all();

  // for(auto element{fm6_vec.begin()}; element<fm6_vec.end(); ++element)
  // {
  //   std::cout<<*element<<std::endl;
  // }

  return 0;
}