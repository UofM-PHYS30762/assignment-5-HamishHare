// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Electron header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef ELECTRON_H
#define ELECTRON_H

#include <string>
#include "lepton.h"
using std::string;
using std::vector;

class Electron : public Lepton
{
private:
  vector<double> deposited_energies;
  const double electron_rest_mass{0.51099895}; // MeV
public:
  // Rule of 5
  // .. Default constructor
  Electron();
  // .. Parameterised constructor
  Electron(const int& charge_quanta, const double& energy,
           const double& px, const double& py, const double& pz);
  // .. Destructor
  ~Electron(){std::cout<<"Calling Electron destructor"<<std::endl;}
  // // .. Copy constructor
  // Electron(const Electron& electron_to_copy);
  // // .. Move constructor
  // Electron(Electron&& electron_to_move);
  // // .. Copy assignment operator
  // Electron& operator=(const Electron& electron_to_copy);
  // // .. Move assignment operator
  // Electron& operator=(Electron&& electron_to_move);

  // Getters
  // Setters

  // Print information
  void print_info() const;
};

#endif // ELECTRON_H