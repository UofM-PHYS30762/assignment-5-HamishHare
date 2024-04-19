// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Neutrino implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <algorithm> // for transform
#include <stdexcept> // for throwing exceptions
#include "neutrino.h"

namespace NeutrinoFuncs
{
  // Function to convert strings to lowercase
  void to_lowercase(string& input_string)
  {
    std::transform(input_string.begin(), input_string.end(), input_string.begin(),
                  [](unsigned char c){return std::tolower(c);});
  }
  
  // Function to validate neutrino flavour
  void validate_flavour(string& flavour_to_check)
  {
    if(!(flavour_to_check=="electron" || flavour_to_check=="muon" ||
         flavour_to_check == "tau"))
    {
      std::cout<<"Provided neutrino flavour '"<<flavour_to_check
               <<"' is not 'electron', 'muon', or 'tau'."<<std::endl;
      throw std::invalid_argument("Invalid neutrino flavour.");
    }
  }
}

// Rule of 5
// .. Default constructor
Neutrino::Neutrino() : has_interacted{false}
{
  std::cout<<"Calling default Neutrino constructor"<<std::endl;
  particle_type = "electron neutrino";
  rest_mass = neutrino_rest_mass;
  charge = -1;
  four_momentum->set_all(neutrino_rest_mass/speed_of_light, 0.0, 0.0, 0.0);
}
// .. Parameterised constructor
Neutrino::Neutrino(const bool& is_antiparticle, const double& energy,
                   const double& px, const double& py, const double& pz,
                   const bool& interacted_flag, string flavour) :
                   has_interacted{interacted_flag},
                   Lepton("temporary neutrino type", 0.0, 0, energy, px, py, pz)
{
  std::cout<<"Calling parameterised Neutrino constructor"<<std::endl;
  // TODO: Full Validation
  NeutrinoFuncs::to_lowercase(flavour);
  NeutrinoFuncs::validate_flavour(flavour);
  particle_type = flavour + (is_antiparticle ? " antineutrino" : " neutrino");
  rest_mass = neutrino_rest_mass;
}
// .. Copy constructor
Neutrino::Neutrino(const Neutrino& neutrino_to_copy) : Lepton(neutrino_to_copy)
{
    std::cout << "Calling Neutrino copy constructor" << std::endl;
    // Copy the remaining (neutrino only) data members
    has_interacted = neutrino_to_copy.has_interacted;
}
// .. Move constructor
Neutrino::Neutrino(Neutrino&& neutrino_to_move) : Lepton(std::move(neutrino_to_move))
{
  std::cout<<"Calling Neutrino move constructor"<<std::endl;
  // Move the remaining (neutrino only) data members
  has_interacted = std::move(neutrino_to_move.has_interacted);
}
// .. Copy assignment operator
Neutrino& Neutrino::operator=(const Neutrino& neutrino_to_copy)
{
  std::cout<<"Calling Neutrino copy assignment operator"<<std::endl;
  if(&neutrino_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  Lepton::operator=(neutrino_to_copy);
  // .. of the neutrino only
  has_interacted = neutrino_to_copy.has_interacted;

  return *this;
}
// .. Move assignment operator
Neutrino& Neutrino::operator=(Neutrino&& neutrino_to_move)
{
  std::cout<<"Calling Neutrino move assignment operator"<<std::endl;
  if(&neutrino_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  Lepton::operator=(std::move(neutrino_to_move));
  // .. of the neutrino only
  has_interacted = std::move(neutrino_to_move.has_interacted);
  
  return *this;
}

// Print information
void Neutrino::print_info() const
{
  std::cout<<"================================"<<std::endl;
  // Call the Lepton print function first
  Lepton::print_info();
  // Print out the Neutrino interaction info
  std::cout<<"Interacted: "<<(has_interacted ? "Yes" : "No")<<std::endl;
  std::cout<<"================================"<<std::endl;
}