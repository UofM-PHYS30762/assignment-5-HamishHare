// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include "lepton.h"
#include "four_momentum.h"
#include "electron.h"
#include "muon.h"

int main()
{
  // Muon m1;
  // m1.print_info();

  Muon m2{+1, 100.1, 200.2, 300.3, 400.4, true};
  // m2.print_info();

  // Muon m3{m2};
  // m3.set_is_isolated(false);
  // m3.print_info();
  // m2.print_info();

  // Muon m4{std::move(m2)};
  // m4.print_info();
  // m2.print_info(); // to prove m2 moved

  // Muon m5;
  // m5 = m2;
  // m5.set_charge(-1);
  // m5.print_info();
  // m2.print_info();

  Muon m6;
  m6 = std::move(m2);
  m6.set_charge(-1);
  m6.print_info();
  m2.print_info(); // to prove m2 moved

  // Electron e1;
  // e1.print_info();

  // Electron e2{1, 123.1, 234.1, 345.6, 456.7};
  // e2.print_info();

  // Electron e3{e2};
  // e3.set_charge(-1);
  // e3.print_info();
  // // e2.print_info();

  // Electron e4{std::move(e2)};
  // e4.print_info();
  // // e2.print_info(); // Prove e2 has been moved

  // Electron e5;
  // e5 = e2;
  // e5.print_info();
  // e2.print_info();

  // Electron e6;
  // e6 = std::move(e2);
  // e6.print_info();
  // e2.print_info(); // Prove e2 has been moved

  // std::cout<<e2.get_deposited_energies()[0]<<std::endl
  //          <<e2.get_deposited_energies()[1]<<std::endl
  //          <<e2.get_deposited_energies()[2]<<std::endl
  //          <<e2.get_deposited_energies()[3]<<std::endl;

  // vector<double> temp{12.3, 23.4, 34.5, 45.6};
  // //vector<double> temp{12.3, 23.4, 34.5}; // too few elements
  // //vector<double> temp{12.3, 23.4, 34.5, 45.6, 56.7}; // too many elements
  // //vector<double> temp{12.3, 23.4, 34.5, -45.6};  // a negative value
  // e2.set_deposited_energies(temp);
  // e2.print_info();

  return 0;
}