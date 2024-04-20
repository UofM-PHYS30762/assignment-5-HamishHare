// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Tau implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include "tau.h"

// Rule of 5
// .. Default constructor
Tau::Tau()
{
  std::cout<<"Calling default Tau constructor"<<std::endl;
  particle_type = "tau";
  rest_mass = tau_rest_mass;
  charge = -1;
  four_momentum->set_all(tau_rest_mass/speed_of_light, 0.0, 0.0, 0.0);
  // TODO: DECAY!!!!
  decay_type = "leptonic";
}
// .. Parameterised constructor
Tau::Tau(const int& charge_quanta, const double& energy,
         const double& px, const double& py, const double& pz) :
         Lepton("tau", 0.0, charge_quanta, energy, px, py, pz)
{
  std::cout<<"Calling parameterised Tau constructor"<<std::endl;
  // TODO: Validation
  rest_mass = tau_rest_mass;
  // TODO:: DECAY!!!!
  decay_type = "leptonic";
}
// .. Copy constructor
Tau::Tau(const Tau& tau_to_copy) : Lepton(tau_to_copy)
{
    std::cout << "Calling Tau copy constructor" << std::endl;
    // Copy the remaining (tau only) data members
    decay_type = tau_to_copy.decay_type;
    // TODO: DECAY!!!!
}
// .. Move constructor
Tau::Tau(Tau&& tau_to_move) : Lepton(std::move(tau_to_move))
{
  std::cout<<"Calling Tau move constructor"<<std::endl;
  // Move the remaining (tau only) data members
  decay_type = std::move(tau_to_move.decay_type);
  // TODO: DECAY!!!!
}
// .. Copy assignment operator
Tau& Tau::operator=(const Tau& tau_to_copy)
{
  std::cout<<"Calling Tau copy assignment operator"<<std::endl;
  if(&tau_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  Lepton::operator=(tau_to_copy);
  // .. of the tau only
  decay_type = tau_to_copy.decay_type;
  // TODO: DECAY!!!!

  return *this;
}
// .. Move assignment operator
Tau& Tau::operator=(Tau&& tau_to_move)
{
  std::cout<<"Calling Tau move assignment operator"<<std::endl;
  if(&tau_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  Lepton::operator=(std::move(tau_to_move));
  // .. of the tau only
  decay_type = std::move(tau_to_move.decay_type);
  // TODO: DECAY!!!!
  
  return *this;
}

// Print information
void Tau::print_info() const
{
  std::cout<<"================================"<<std::endl;
  // Call the Lepton print function first
  Lepton::print_info();
  // Print out the Tau info
  std::cout<<"Decay Type: "<<decay_type<<std::endl;
  std::cout<<"================================"<<std::endl;
}