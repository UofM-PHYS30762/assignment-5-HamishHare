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
#include "tau.h"

int main()
{
  // Tau t1;
  // t1.print_info();
  // t1.decay_hadronically();
  // t1.decay_leptonically();
  // t1.decay();

  Tau t2{1, 34.2, 56.2, 24.45, 912.3};
  t2.print_info();

  // Tau t3{t2};
  // t3.print_info();
  // // std::cout<<t3.get_decay_type()<<std::endl;
  // t2.print_info();

  // Tau t4{std::move(t2)};
  // t4.print_info();
  // t2.print_info(); // prove moved

  // Tau t5;
  // t5 = t2;
  // t5.print_info();
  // t2.print_info();

  // Tau t6;
  // t6 = std::move(t2);
  // t6.print_info();
  // t2.print_info(); // prove moved

  // Neutrino nT{true, 111.11, 222.22, 333.33, 444.44, false, "TaU"};
  // nT.print_info();

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