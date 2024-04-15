// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Four-momentum implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <iomanip>
#include <vector>
#include "four_momentum.h"
using std::vector;

// Validation
// .. check that the energy is not negative
void FourMomentum::validate_energy()
{
  if(energy<0)
  {
    std::cout<<"Particle energies cannot be negative. You entered "
             <<energy<<" MeV/c."<<std::endl;
    throw std::invalid_argument("Invalid particle energy.");
  }
}

// Rule of 5
// .. Parameterised constructor
FourMomentum::FourMomentum(const double& initial_energy, const double& initial_px,
                           const double& initial_py, const double& initial_pz) : 
                           energy{initial_energy}, momentum_x{initial_px},
                           momentum_y{initial_py}, momentum_z{initial_pz}
{
  std::cout<<"Calling parameterised FourMomentum constructor"<<std::endl;
  // Validation
  validate_energy();
}
// .. Copy constructor
FourMomentum::FourMomentum(const FourMomentum& momenta_to_copy)
{
  std::cout<<"Calling FourMomentum copy constructor"<<std::endl;
  // Copy the data members
  energy = momenta_to_copy.energy;
  momentum_x = momenta_to_copy.momentum_x;
  momentum_y = momenta_to_copy.momentum_y;
  momentum_z = momenta_to_copy.momentum_z;
}
// .. Move constructor
// (NOTE: since this class only contains doubles, this has the
//  same functionality as the copy constructor.)
FourMomentum::FourMomentum(FourMomentum&& momenta_to_move)
{
  std::cout<<"Calling FourMomentum move constructor"<<std::endl;
  // Move the data members over
  energy = std::move(momenta_to_move.energy);
  momentum_x = std::move(momenta_to_move.momentum_x);
  momentum_y = std::move(momenta_to_move.momentum_y);
  momentum_z = std::move(momenta_to_move.momentum_z);
}
// .. Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& momenta_to_copy)
{
  std::cout<<"Calling FourMomentum copy assignment operator"<<std::endl;
  if(&momenta_to_copy == this) return *this; // no self-assignment
  
  // Copy the data members
  energy = momenta_to_copy.energy;
  momentum_x = momenta_to_copy.momentum_x;
  momentum_y = momenta_to_copy.momentum_y;
  momentum_z = momenta_to_copy.momentum_z;

  return *this;
}
// .. Move assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum&& momenta_to_move)
{
  std::cout<<"Calling FourMomentum move assignment operator"<<std::endl;
  if(&momenta_to_move == this) return *this; // no self-assignment

  // Move the data members over
  energy = std::move(momenta_to_move.energy);
  momentum_x = std::move(momenta_to_move.momentum_x);
  momentum_y = std::move(momenta_to_move.momentum_y);
  momentum_z = std::move(momenta_to_move.momentum_z);
  
  return *this;
}


// Getters
vector<double> FourMomentum::get_all() const
{
  vector<double> four_momentum{energy, momentum_x, momentum_y, momentum_z};
  return four_momentum;
}
// Setters
void FourMomentum::set_energy(const double& new_energy)
{
  energy = new_energy;
  // Validation
  validate_energy();
}
void FourMomentum::set_px(const double& new_px)
{
  // TODO: Validate input
  momentum_x = new_px;
}
void FourMomentum::set_py(const double& new_py)
{
  // TODO: Validate input
  momentum_y = new_py;
}
void FourMomentum::set_pz(const double& new_pz)
{
  // TODO: Validate input
  momentum_z = new_pz;
}

void FourMomentum::set_all(const double& new_energy, const double& new_px,
                           const double& new_py, const double& new_pz)
{
  // Set elements
  energy = new_energy;
  momentum_x = new_px;
  momentum_y = new_py;
  momentum_z = new_pz;
  // Validate elements
  validate_energy();
}

void FourMomentum::set_all(const vector<double>& new_momentum_vector)
{
  // Validate input size
  if(new_momentum_vector.size() != 4)
  {
    std::cout<<"Provided four momentum should have 4 elements. You entered one with"
             <<new_momentum_vector.size()<<".";
    throw std::invalid_argument("Invalid particle mass.");
  }
  // Set elements
  energy = new_momentum_vector[0];
  momentum_x = new_momentum_vector[1];
  momentum_y = new_momentum_vector[2];
  momentum_z = new_momentum_vector[3];
  // Validate elements
  validate_energy();
}

// Print information
void FourMomentum::print_info() const
{
  std::cout<<std::scientific<<std::setprecision(2)
           <<"Four Momentum: ("<<energy<<", "
                               <<momentum_x<<", "
                               <<momentum_y<<", "
                               <<momentum_z<<") MeV/c"
           <<std::endl;
  // Undo the output formatting
  std::cout.unsetf(std::ios::scientific);
}