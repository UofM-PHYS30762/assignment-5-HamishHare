// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Electron implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <iomanip>
#include "electron.h"

// Rule of 5
// .. Default constructor
Electron::Electron() : deposited_energies{0.0, 0.0, 0.0, 0.0}
{
  std::cout<<"Calling default Electron constructor"<<std::endl;
  particle_type = "electron";
  rest_mass = electron_rest_mass;
  charge = -1;
  four_momentum->set_all(electron_rest_mass/speed_of_light, 0.0, 0.0, 0.0);
  // Assume all energy is deposited equally in first two (EM) layers
  deposited_energies[0] = (electron_rest_mass/speed_of_light) / 2.0;
  deposited_energies[1] = (electron_rest_mass/speed_of_light) / 2.0;
}
// .. Parameterised constructor
Electron::Electron(const int& charge_quanta, const double& energy,
                   const double& px, const double& py, const double& pz) :
                   deposited_energies{0.0, 0.0, 0.0, 0.0},
                   Lepton("electron", 0.0, charge_quanta, energy, px, py, pz)
{
  std::cout<<"Calling parameterised Electron constructor"<<std::endl;
  // TODO: Validation
  rest_mass = electron_rest_mass;
  // Assume all energy is deposited equally in first two (EM) layers
  deposited_energies[0] = energy / 2.0;
  deposited_energies[1] = energy / 2.0;
}
// .. Copy constructor
Electron::Electron(const Electron& electron_to_copy) : Lepton(electron_to_copy)
{
    std::cout << "Calling Electron copy constructor" << std::endl;
    // Copy the remaining (electron only) data members
    deposited_energies = electron_to_copy.deposited_energies;
}
// .. Move constructor
Electron::Electron(Electron&& electron_to_move) : Lepton(std::move(electron_to_move))
{
  std::cout<<"Calling Electron move constructor"<<std::endl;
  // Move the remaining (electron only) data members
  deposited_energies = std::move(electron_to_move.deposited_energies);
}
// // .. Copy assignment operator
// Lepton& Lepton::operator=(const Lepton& lepton_to_copy)
// {
//   std::cout<<"Calling Lepton copy assignment operator"<<std::endl;
//   if(&lepton_to_copy == this) return *this; // no self-assignment
  
//   // Copy the data members
//   particle_type = lepton_to_copy.particle_type;
//   four_momentum = std::make_unique<FourMomentum>(*lepton_to_copy.four_momentum);;
//   rest_mass = lepton_to_copy.rest_mass;
//   charge = lepton_to_copy.charge;

//   return *this;
// }
// // .. Move assignment operator
// Lepton& Lepton::operator=(Lepton&& lepton_to_move)
// {
//   std::cout<<"Calling Lepton move assignment operator"<<std::endl;
//   if(&lepton_to_move == this) return *this; // no self-assignment

//   // Move the data members
//   particle_type = lepton_to_move.particle_type;
//   four_momentum = std::move(lepton_to_move.four_momentum);
//   rest_mass = lepton_to_move.rest_mass;
//   charge = lepton_to_move.charge;
  
//   return *this;
// }

// Print information
void Electron::print_info() const
{
  std::cout<<"================================"<<std::endl;
  // Call the Lepton print function first
  Lepton::print_info();
  // Print out the energy lost by the electron
  size_t layer_num{0};
  std::cout<<std::scientific<<std::setprecision(3)
           <<"+-------------------------------------+"<<std::endl
           <<"|          CALORIMETER INFO:          |"<<std::endl
           <<"+-------------------------------------+"<<std::endl;
  for(auto energy_loss{deposited_energies.begin()};
      energy_loss<deposited_energies.end(); ++energy_loss)
  {
    string buffer = (layer_names[layer_num].length()==5) ? "" : " ";
    std::cout<<"| Energy lost in "<<layer_names[layer_num]<<buffer<<": "
             <<*energy_loss<<" MeV"<<" |"<<std::endl;
    layer_num++;
  }
  std::cout<<"+-------------------------------------+"<<std::endl;
  std::cout<<"================================"<<std::endl;
}