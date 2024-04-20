// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Lepton implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <iomanip>
#include <stdexcept> // for throwing exceptions
#include "lepton.h"

// Rule of 5
// .. Default constructor
Lepton::Lepton() : four_momentum(std::make_unique<FourMomentum>())
{
  std::cout<<"Calling default Lepton constructor"<<std::endl;
}
// .. Parameterised constructor
Lepton::Lepton(const string& type, const double& mass, const int& charge_quanta,
               const double& energy, const double& px, const double& py, const double& pz) :
               particle_type{type}, rest_mass{mass}, charge{charge_quanta}
{
  std::cout<<"Calling parameterised Lepton constructor"<<std::endl;
  // TODO: Validation
  four_momentum = std::make_unique<FourMomentum>(energy, px, py, pz);
}
// .. Copy constructor
Lepton::Lepton(const Lepton& lepton_to_copy)
{
  std::cout<<"Calling Lepton copy constructor"<<std::endl;
  // Copy the data members
  particle_type = lepton_to_copy.particle_type;
  four_momentum = std::make_unique<FourMomentum>(*lepton_to_copy.four_momentum);;
  rest_mass = lepton_to_copy.rest_mass;
  charge = lepton_to_copy.charge;
}
// .. Move constructor
Lepton::Lepton(Lepton&& lepton_to_move)
{
  std::cout<<"Calling Lepton move constructor"<<std::endl;
  // Move the data members
  particle_type = lepton_to_move.particle_type;
  four_momentum = std::move(lepton_to_move.four_momentum);
  rest_mass = lepton_to_move.rest_mass;
  charge = lepton_to_move.charge;
}
// .. Copy assignment operator
Lepton& Lepton::operator=(const Lepton& lepton_to_copy)
{
  std::cout<<"Calling Lepton copy assignment operator"<<std::endl;
  if(&lepton_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  particle_type = lepton_to_copy.particle_type;
  four_momentum = std::make_unique<FourMomentum>(*lepton_to_copy.four_momentum);;
  rest_mass = lepton_to_copy.rest_mass;
  charge = lepton_to_copy.charge;

  return *this;
}
// .. Move assignment operator
Lepton& Lepton::operator=(Lepton&& lepton_to_move)
{
  std::cout<<"Calling Lepton move assignment operator"<<std::endl;
  if(&lepton_to_move == this) return *this; // no self-assignment

  // Move the data members
  particle_type = lepton_to_move.particle_type;
  four_momentum = std::move(lepton_to_move.four_momentum);
  rest_mass = lepton_to_move.rest_mass;
  charge = lepton_to_move.charge;
  
  return *this;
}

// Setters
void Lepton::set_type(const string& new_type)
{
  // TODO: Validate input
  particle_type = new_type;
}
void Lepton::set_rest_mass(const double& new_rest_mass)
{
  // TODO: Validate input
  rest_mass = new_rest_mass;
}
void Lepton::set_charge(const int& new_charge)
{
  // TODO: Validate input
  charge = new_charge;
}
void Lepton::set_four_momentum(const double& new_energy, const double& new_px,
                               const double& new_py, const double& new_pz)
{
  four_momentum->set_all(new_energy, new_px, new_py, new_pz);
}
void Lepton::set_four_momentum(const vector<double>& new_momentum_vector)
{
  four_momentum->set_all(new_momentum_vector);
}

// Print information
void Lepton::print_info() const
{
  // Check if the Lepton has been moved or not before printing
  if (four_momentum)
  {
    string particle_name = (charge>0) ? "anti" + particle_type : particle_type;
    std::cout<<std::scientific<<std::setprecision(3)
            //  <<"--------------------------------"<<std::endl
             <<"Particle: "<<particle_name<<std::endl
             <<"Rest Mass: "<<rest_mass<<" MeV"<<std::endl
             <<"Charge: "<<charge<<" e"<<std::endl;
    four_momentum->print_info();
    // std::cout<<"--------------------------------"<<std::endl;
    // Undo the output formatting
    std::cout.unsetf(std::ios::scientific);
  }
  else
  {
    std::cout<<"--------------------------------"<<std::endl
             <<"Lepton unavailable (it has been moved)"<<std::endl
             <<"--------------------------------"<<std::endl;
    throw std::runtime_error("Error: attempting to access a particle which has been moved.");
  }
}

// Friend functions
// .. Given two Leptons, return the sum of their four momenta
FourMomentum operator+(const Lepton &lepton1, const Lepton &lepton2)
{
  FourMomentum summed_momentum
  {
    lepton1.four_momentum->get_energy()+lepton2.four_momentum->get_energy(),
    lepton1.four_momentum->get_px()+lepton2.four_momentum->get_px(),
    lepton1.four_momentum->get_py()+lepton2.four_momentum->get_py(),
    lepton1.four_momentum->get_pz()+lepton2.four_momentum->get_pz()
  };
  return summed_momentum;
}
// .. Given two Leptons, return the dot product of their four momenta
double dot_product(const Lepton &lepton1, const Lepton &lepton2)
{
  double product
  {
    lepton1.four_momentum->get_energy()*lepton2.four_momentum->get_energy()+
    lepton1.four_momentum->get_px()*lepton2.four_momentum->get_px()+
    lepton1.four_momentum->get_py()*lepton2.four_momentum->get_py()+
    lepton1.four_momentum->get_pz()*lepton2.four_momentum->get_pz()
  };
  return product;
}