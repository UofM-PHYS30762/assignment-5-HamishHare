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
#include "neutrino.h"

int main()
{
  // Neutrino n1;
  // n1.print_info();

  Neutrino n2{false, 432.1, 543.2, 654.3, 765.4, true, "mUoN"};
  n2.print_info();
  // Neutrino n3{true, 432.1, 543.2, 654.3, 765.4, false, "tAU"};
  // n3.print_info();
  // std::cout<<n2.get_has_interacted()<<std::endl;
  
  // Neutrino n4{true, 432.1, 543.2, 654.3, 765.4, true, "t\nU"};
  // n3.print_info();

  // Neutrino n5{n2};
  // n5.set_has_interacted(false);
  // n5.print_info();
  // n2.print_info();

  // Neutrino n6{std::move(n2)};
  // n6.set_has_interacted(false);
  // n6.print_info();
  // n2.print_info(); // to prove moved

  // Neutrino n7;
  // n7 = n2;
  // n7.print_info();
  // n2.print_info();

  Neutrino n8;
  n8 = std::move(n2);
  n8.print_info();
  n2.print_info(); // to prove moved

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