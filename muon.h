// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Muon header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef MUON_H
#define MUON_H

#include <string>
#include "lepton.h"
#include "assignment5_consts.cpp"

class Muon : public Lepton
{
private:
  bool is_isolated;
  const double muon_rest_mass{105.6583755}; // MeV/c^2
public:
  // Rule of 5
  // .. Default constructor
  Muon();
  // .. Parameterised constructor
  Muon(const int& charge_quanta, const double& energy,
       const double& px, const double& py, const double& pz,
       const bool& isolated_flag);
  // .. Destructor
  ~Muon(){if(assignment5_consts::show_messages) std::cout<<"Calling Muon destructor"<<std::endl;}
  // .. Copy constructor
  Muon(const Muon& muon_to_copy);
  // .. Move constructor
  Muon(Muon&& muon_to_move);
  // .. Copy assignment operator
  Muon& operator=(const Muon& muon_to_copy);
  // .. Move assignment operator
  Muon& operator=(Muon&& muon_to_move);

  // Getters
  bool get_is_isolated() const {return is_isolated;}
  // Setters
  void set_is_isolated(const bool& isolated_flag){is_isolated = isolated_flag;}

  // Print information
  void print_info() const;
};

#endif // MUON_H