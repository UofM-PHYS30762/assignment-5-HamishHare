// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Tau header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef TAU_H
#define TAU_H

#include <string>
#include "lepton.h"

class Tau : public Lepton
{
private:
  string decay_type;
  const double tau_rest_mass{1776.86}; // MeV/c^2
public:
  // Rule of 5
  // .. Default constructor
  Tau();
  // .. Parameterised constructor
  Tau(const int& charge_quanta, const double& energy,
       const double& px, const double& py, const double& pz);
  // .. Destructor
  ~Tau(){std::cout<<"Calling Tau destructor"<<std::endl;}
  // .. Copy constructor
  Tau(const Tau& tau_to_copy);
  // .. Move constructor
  Tau(Tau&& tau_to_move);
  // .. Copy assignment operator
  Tau& operator=(const Tau& tau_to_copy);
  // .. Move assignment operator
  Tau& operator=(Tau&& tau_to_move);

  // Getters
  string get_decay_type() const {return decay_type;}
  // Setters
  // TODO: decay setting

  // Print information
  void print_info() const;
};

#endif // MUON_H