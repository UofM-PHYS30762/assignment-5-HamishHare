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
// .. Copy assignment operator
Electron& Electron::operator=(const Electron& electron_to_copy)
{
  std::cout<<"Calling Electron copy assignment operator"<<std::endl;
  if(&electron_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  // .. of the base class
  Lepton::operator=(electron_to_copy);
  // .. of the electron only
  deposited_energies = electron_to_copy.deposited_energies;

  return *this;
}
// .. Move assignment operator
Electron& Electron::operator=(Electron&& electron_to_move)
{
  std::cout<<"Calling Electron move assignment operator"<<std::endl;
  if(&electron_to_move == this) return *this; // no self-assignment

  // Move the data members
  // .. of the base class
  Lepton::operator=(std::move(electron_to_move));
  // .. of the electron only
  deposited_energies = std::move(electron_to_move.deposited_energies);
  
  return *this;
}

// Validation functions for the Setters below
namespace ElectronFuncs
{
  void validate_positive_energy(const double& energy)
  {
    if(energy<0)
    {
      std::cout<<"Provided energy deposited values cannot be negative."<<std::endl;
      throw std::invalid_argument("Invalid energy deposited value.");
    }
  }
}

// Setters
void Electron::set_deposited_energies(const vector<double>& new_deposited_energies)
{
  // TODO: Validation and input handling
  // Validate input size
  if(new_deposited_energies.size() != 4)
  {
    std::cout<<"Provided energy deposited vector should have 4 elements. "
             <<"You entered one with "
             <<new_deposited_energies.size()<<"."<<std::endl;
    throw std::invalid_argument("Invalid energy deposited vector.");
  }
  // Validate all given energies are positive and sum them
  double total_energy{0};
  for(auto energy{new_deposited_energies.begin()};
      energy<new_deposited_energies.end(); ++energy)
  {
    ElectronFuncs::validate_positive_energy(*energy);
    total_energy += *energy;
  }
  const double small_tolerance{1.0e-12};
  // Check and handle the energy totals
  if(abs(total_energy - four_momentum->get_energy()) > small_tolerance)
  {
    std::cout<<std::setprecision(13)
            <<"Total energy of provided energy deposited vector ("<<total_energy
            <<" MeV/c) does not equal the energy of the electron ("
            <<four_momentum->get_energy()<<" MeV/c) to within 10^-12 tolerance. "
            <<"Workaround has been applied to allocate all electron energy to the"
            <<" EM layers of the calorimeter as best as possible."<<std::endl;
    // Allocate energies as best as possible
    double electron_energy{four_momentum->get_energy()};
    if(new_deposited_energies[0] > electron_energy)
    {
      deposited_energies = {electron_energy, 0.0, 0.0, 0.0};
    }
    else
    {
      deposited_energies = {new_deposited_energies[0],
                            electron_energy-new_deposited_energies[0],
                            0.0, 0.0};
    }
  }
  else deposited_energies = new_deposited_energies;
}
// void Electron::set_deposited_energy_layer(size_t layer_number, double new_deposited_energy)
// {
//   // TODO: Validation and input handling
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
  // Undo the output formatting
  std::cout.unsetf(std::ios::scientific);
  std::cout<<"================================"<<std::endl;
}