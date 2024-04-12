// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Four-momentum header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include <iostream>
#include <vector>
using std::vector;

class FourMomentum
{
private:
  double energy{0}; // MeV/c
  double momentum_x{0}; // MeV/c
  double momentum_y{0}; // MeV/c
  double momentum_z{0}; // MeV/c

  // Validation
  void validate_energy();

public:
  // Rule of 5
  // TODO: FINISH THESE
  // .. Default constructor
  FourMomentum(){std::cout<<"Calling default FourMomentum constructor"<<std::endl;}
  // .. Parameterised constructor
  FourMomentum(const double& initial_energy, const double& initial_px,
               const double& initial_py, const double& initial_pz);
  // .. Destructor
  ~FourMomentum(){std::cout<<"Calling FourMomentum destructor"<<std::endl;}
  // .. Copy constructor
  FourMomentum(const FourMomentum& momenta_to_copy);
  // .. Move constructor
  FourMomentum(FourMomentum&& momenta_to_move);
  // .. Copy assignment operator
  FourMomentum& operator=(const FourMomentum& momenta_to_copy);
  // .. Move assignment operator
  FourMomentum& operator=(FourMomentum&& momenta_to_move);

  // Getters
  double get_energy() const {return energy;}
  double get_px() const {return momentum_x;}
  double get_py() const {return momentum_y;}
  double get_pz() const {return momentum_z;}
  vector<double> get_all() const; // see implementation
  // Setters
  void set_energy(const double& new_energy);
  void set_px(const double& new_px);
  void set_py(const double& new_py);
  void set_pz(const double& new_pz);

  // Print out the information
  void print_info();
};

#endif // FOUR_MOMENTUM_H