// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include "lepton.h"
#include "four_momentum.h"

int main()
{
  // Lepton l1;
  // l1.print_info();
  // l1.set_charge(1);
  // l1.set_rest_mass(105.6583755);
  // l1.set_type("muon");
  // // l1.set_energy(12.34); l1.set_px(23.45); l1.set_py(34.56); l1.set_pz(45.67);
  // // l1.print_info();
  // l1.set_four_momentum(123.4, 234.5, 345.6, 456.7);
  // l1.print_info();

  // Lepton l2{"electron", 0.511, -1, 23.121, 123.13443, 435345.2, 912.3};
  // l2.print_info();

  // std::cout<<"type: "<<l2.get_type()<<std::endl;
  // std::cout<<"rest mass: "<<l2.get_rest_mass()<<std::endl;
  // std::cout<<"charge: "<<l2.get_charge()<<std::endl;
  // std::cout<<"four momentum (0): "<<l2.get_four_momentum()[0]<<std::endl;
  // std::cout<<"energy: "<<l2.get_energy()<<std::endl;
  // std::cout<<"px: "<<l2.get_px()<<std::endl;
  // std::cout<<"py: "<<l2.get_py()<<std::endl;
  // std::cout<<"pz: "<<l2.get_pz()<<std::endl;

  // Lepton l3{l2};
  // l3.print_info();

  // Lepton l4{std::move(l2)};
  // l4.print_info();
  // l2.print_info();

  // Lepton l5;
  // l5 = l2;
  // l5.print_info();

  // Lepton l6;
  // l6 = std::move(l1);
  // l6.print_info();
  // l1.print_info();

  FourMomentum f1{};
  f1.print_info();
  f1.set_all(1.234, 2.345, 3.456, 4.567);
  f1.print_info();
  vector<double> temp{12.34, 23.45, 34.56, 45.67};
  f1.set_all(temp);
  f1.print_info();
  
  return 0;
}