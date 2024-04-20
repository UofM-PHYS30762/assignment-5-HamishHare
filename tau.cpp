// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Tau implementation
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <iostream>
#include <random>
#include "tau.h"
#include "neutrino.h" // used in decay products
#include "electron.h" // used in decay products
#include "muon.h" // used in decay products

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

// Decay functions
void Tau::decay()
{
  // NOTE: This is not physical, I'm just using the following ratios:
  //       65% Hadronic decay
  //       35% Lepton decay

  // TODO: Validate hasn't already decayed

  // Get a random number in the range [0 to 1)
  std::random_device rng;
  std::mt19937 generator(rng()); // seed the mt19937 generator with the system rng device
  std::uniform_real_distribution<double> distribution(0.0, 1.0); // define a uniform dist.
  double random_number = distribution(generator); // generate the random number
  std::cout<<"DEBUG: rng = "<<random_number<<std::endl;
  // Perform decay
  if(random_number<0.65) decay_hadronically();
  else decay_leptonically();
  
}
void Tau::decay_hadronically()
{
  // TODO: Validate hasn't already decayed
  std::cout<<"Tau has decayed hadronically"<<std::endl;
  decay_type = "hadronic";
}
void Tau::decay_leptonically()
{
  // NOTE: There are no physical values used here. I am using
  //       the following relationships:
  //       Lepton chance: 1/3 Electon, 1/3 Muon, 1/3 Tau
  //       Energy (out of original): 5% tau neutrino, 90% lepton, 5% lepton neutrino
  //       Momenta (out of original): 5% to tau neutrino, 90% lepton, 5% lepton neutrino
  double energy = four_momentum->get_energy();
  double px = four_momentum->get_px();
  double py = four_momentum->get_py();
  double pz = four_momentum->get_pz();
  // TODO: Validate hasn't already decayed

  // Start decay process
  std::cout<<"Tau has decayed leptonically"<<std::endl;
  decay_type = "leptonic";
  bool is_anti = (charge>0) ? true : false;
  std::shared_ptr<Neutrino> tau_neutrino_ptr{
    std::make_shared<Neutrino>(is_anti, 0.05*energy,0.05*px, 0.05*py, 0.05*pz,
                               false, "tau")};
  std::shared_ptr<Lepton> lepton_ptr;
  std::shared_ptr<Neutrino> lepton_neutrino_ptr;

  // Get a random number in the range [0 to 1)
  std::random_device rng;
  std::mt19937 generator(rng()); // seed the mt19937 generator with the system rng device
  std::uniform_real_distribution<double> distribution(0.0, 1.0); // define a uniform dist.
  double random_number = distribution(generator); // generate the random number
  std::cout<<"DEBUG: rng = "<<random_number<<std::endl;

  // Assign the random number to a decay chain
  if(random_number<0.333333)
  {
    // Electron decay
    std::cout<<"DEBUG: electron decay"<<std::endl;
    lepton_ptr = std::make_shared<Electron>(-1, 0.9*energy, 0.9*px, 0.9*py, 0.9*pz);
    lepton_neutrino_ptr = std::make_shared<Neutrino>(true, 0.05*energy,0.05*px,
                                                     0.05*py, 0.05*pz, false, "electron");
  }
  else if(random_number>0.666666)
  {
    // Muon decay
    std::cout<<"DEBUG: muon decay"<<std::endl;
    lepton_ptr = std::make_shared<Muon>(-1, 0.9*energy, 0.9*px, 0.9*py, 0.9*pz, false);
    lepton_neutrino_ptr = std::make_shared<Neutrino>(true, 0.05*energy,0.05*px,
                                                     0.05*py, 0.05*pz, false, "muon");
  }
  else
  {
    // Tau decay
    std::cout<<"DEBUG: tau decay"<<std::endl;
    lepton_ptr = std::make_shared<Tau>(-1, 0.9*energy, 0.9*px, 0.9*py, 0.9*pz);
    lepton_neutrino_ptr = std::make_shared<Neutrino>(true, 0.05*energy,0.05*px,
                                                     0.05*py, 0.05*pz, false, "tau");
  }

  // Add the decay products to the decay_products vector
  decay_products.push_back(lepton_ptr);
  decay_products.push_back(tau_neutrino_ptr);
  decay_products.push_back(lepton_neutrino_ptr);
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