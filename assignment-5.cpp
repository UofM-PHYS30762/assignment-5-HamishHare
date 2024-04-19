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

int main()
{
  // Electron e1;
  // e1.print_info();

  Electron e2{1, 123.1, 234.1, 345.6, 456.7};
  // e2.print_info();

  Electron e3{e2};
  e3.set_charge(-1);
  e3.print_info();
  // e2.print_info();

  Electron e4{std::move(e2)};
  e4.print_info();
  // e2.print_info(); // Prove e2 has been moved


  return 0;
}