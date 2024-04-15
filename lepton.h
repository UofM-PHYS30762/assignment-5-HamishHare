// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Lepton header file
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#ifndef LEPTON_H
#define LEPTON_H

#include <string>
#include <memory> // smart pointers
#include "four_momentum.h"
using std::string;

class Lepton
{
protected:
  string particle_type{"WARNING!! base lepton"};
  std::unique_ptr<FourMomentum> four_momentum;
  double rest_mass{0}; // in MeV
  int charge{-1}; // in multiples of e
public:
  // Rule of 5
  // .. Default constructor
  Lepton();
  // .. Parameterised constructor
  Lepton(const string& type, const double& mass, const int& charge_quanta,
         const double& energy, const double& px, const double& py, const double& pz);
  // .. Destructor
  ~Lepton(){std::cout<<"Calling Lepton destructor"<<std::endl;}
  // .. Copy constructor
  Lepton(const Lepton& lepton_to_copy);
  // .. Move constructor
  Lepton(Lepton&& lepton_to_move);
  // .. Copy assignment operator
  Lepton& operator=(const Lepton& lepton_to_copy);
  // .. Move assignment operator
  Lepton& operator=(Lepton&& lepton_to_move);

  // Getters
  string get_type() const {return particle_type;}
  double get_rest_mass() const {return rest_mass;}
  int get_charge() const {return charge;}
  vector<double> get_four_momentum() const {return four_momentum->get_all();}
  double get_energy() const {return four_momentum->get_energy();}
  double get_px() const {return four_momentum->get_px();}
  double get_py() const {return four_momentum->get_py();}
  double get_pz() const {return four_momentum->get_pz();}
  // Setters
  void set_type(const string& new_type);
  void set_rest_mass(const double& new_rest_mass);
  void set_charge(const int& new_charge);
  void set_four_momentum(const double& new_energy, const double& new_px,
                         const double& new_py, const double& new_pz); // individual entries
  void set_four_momentum(const vector<double>& new_momentum_vector); // with a vector
  void set_energy(const double& new_energy){four_momentum->set_energy(new_energy);}
  void set_px(const double& new_px){four_momentum->set_px(new_px);}
  void set_py(const double& new_py){four_momentum->set_py(new_py);}
  void set_pz(const double& new_pz){four_momentum->set_pz(new_pz);}

  // Print information
  virtual void print_info() const;
};

#endif // LEPTON_H