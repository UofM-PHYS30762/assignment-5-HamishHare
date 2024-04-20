// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Neutrino header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include <string>
#include "lepton.h"
#include "assignment5_consts.cpp"
using std::string;

class Neutrino : public Lepton
{
private:
  bool has_interacted;
  const double neutrino_rest_mass{0.0}; // MeV/c^2
public:
  // Rule of 5
  // .. Default constructor
  Neutrino();
  // .. Parameterised constructor
  Neutrino(const bool& is_antiparticle, const double& energy,
           const double& px, const double& py, const double& pz,
           const bool& interacted_flag, string flavour);
  // .. Destructor
  ~Neutrino(){if(assignment5_consts::show_messages) std::cout<<"Calling Neutrino destructor"<<std::endl;}
  // .. Copy constructor
  Neutrino(const Neutrino& neutrino_to_copy);
  // .. Move constructor
  Neutrino(Neutrino&& neutrino_to_move);
  // .. Copy assignment operator
  Neutrino& operator=(const Neutrino& neutrino_to_copy);
  // .. Move assignment operator
  Neutrino& operator=(Neutrino&& neutrino_to_move);

  // Getters
  bool get_has_interacted() const {return has_interacted;}
  // Setters
  void set_has_interacted(const bool& interacted_flag){has_interacted = interacted_flag;}

  // Print information
  void print_info() const;
};

#endif // NEUTRINO_H