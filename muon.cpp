// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Muon implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include "muon.h"

// Rule of 5
// .. Default constructor
Muon::Muon() : is_isolated{false}
{
  std::cout<<"Calling default Muon constructor"<<std::endl;
  particle_type = "muon";
  rest_mass = muon_rest_mass;
  charge = -1;
  four_momentum->set_all(muon_rest_mass/speed_of_light, 0.0, 0.0, 0.0);
}
// .. Parameterised constructor
Muon::Muon(const int& charge_quanta, const double& energy,
           const double& px, const double& py, const double& pz,
           const bool& isolated_flag) :
           is_isolated{isolated_flag},
           Lepton("muon", 0.0, charge_quanta, energy, px, py, pz)
{
  std::cout<<"Calling parameterised Muon constructor"<<std::endl;
  // TODO: Validation
  rest_mass = muon_rest_mass;
}
// .. Copy constructor
Muon::Muon(const Muon& muon_to_copy) : Lepton(muon_to_copy)
{
  std::cout << "Calling Muon copy constructor" << std::endl;
  // Copy the remaining (muon only) data members
  is_isolated = muon_to_copy.is_isolated;
}
// .. Move constructor
Muon::Muon(Muon&& muon_to_move) : Lepton(std::move(muon_to_move))
{
  std::cout<<"Calling Muon move constructor"<<std::endl;
  // Move the remaining (muon only) data members
  is_isolated = std::move(muon_to_move.is_isolated);
}
// .. Copy assignment operator
Muon& Muon::operator=(const Muon& muon_to_copy)
{
  std::cout<<"Calling Muon copy assignment operator"<<std::endl;
  if(&muon_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  Lepton::operator=(muon_to_copy);
  // .. of the muon only
  is_isolated = muon_to_copy.is_isolated;

  return *this;
}
// .. Move assignment operator
Muon& Muon::operator=(Muon&& muon_to_move)
{
  std::cout<<"Calling Muon move assignment operator"<<std::endl;
  if(&muon_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  Lepton::operator=(std::move(muon_to_move));
  // .. of the muon only
  is_isolated = std::move(muon_to_move.is_isolated);
  
  return *this;
}

// Print information
void Muon::print_info() const
{
  std::cout<<"================================"<<std::endl;
  // Call the Lepton print function first
  Lepton::print_info();
  // Print out the Muon isolation info
  std::cout<<"Isolated: "<<(is_isolated ? "Yes" : "No")<<std::endl;
  std::cout<<"================================"<<std::endl;
}