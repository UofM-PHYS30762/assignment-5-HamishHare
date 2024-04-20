// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <memory> // smart pointers
#include "lepton.h"
#include "four_momentum.h"
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"
using std::unique_ptr;

int main()
{
  // Create the vector of particles
  unique_ptr<Electron> e1 = std::make_unique<Electron>(-1, 100.1, 200.2, 300.3, 400.4);
  unique_ptr<Electron> e2 = std::make_unique<Electron>(-1, 123.1, 234.1, 345.6, 456.7);
  unique_ptr<Muon> m1 = std::make_unique<Muon>(-1, 81.6, 0.0, 0.0, 5.63, false);
  unique_ptr<Muon> m2 = std::make_unique<Muon>(-1, 984.2, 234.1, 0.0, 0.0, true);
  unique_ptr<Muon> m3 = std::make_unique<Muon>(-1, 489.21, 0.0, 23.4, 0.0, true);
  unique_ptr<Muon> m4 = std::make_unique<Muon>(-1, 92.7, 0.0, 0.0, 451.2, false);
  unique_ptr<Electron> ae1 = std::make_unique<Electron>(1, 712.1, 827.3, 0.0, 0.0);
  unique_ptr<Muon> am1 = std::make_unique<Muon>(1, 121.1, 0.0, 9.120, 0.0, false);
  unique_ptr<Neutrino> nm1 = std::make_unique<Neutrino>(false, 11.11, 22.22, 33.33, 44.44, false, "mUon");
  unique_ptr<Neutrino> ne1 = std::make_unique<Neutrino>(false, 10.01, 20.02, 30.03, 40.04, false, "eLecTRon");
  unique_ptr<Tau> t1 = std::make_unique<Tau>(-1, 34.2, 56.2, 24.45, 912.3); // FIX: add decay product control
  unique_ptr<Tau> t2 = std::make_unique<Tau>(-1, 21.3, 89.1, 63.5, 12.45); // FIX: add decay product control
  
  vector<unique_ptr<Lepton>> all_particles;
  all_particles.push_back(std::move(e1)); // 0
  all_particles.push_back(std::move(e2)); // 1
  all_particles.push_back(std::move(m1)); // 2
  all_particles.push_back(std::move(m2)); // 3
  all_particles.push_back(std::move(m3)); // 4
  all_particles.push_back(std::move(m4)); // 5
  all_particles.push_back(std::move(ae1)); // 6
  all_particles.push_back(std::move(am1)); // 7
  all_particles.push_back(std::move(nm1)); // 8
  all_particles.push_back(std::move(ne1)); // 9
  all_particles.push_back(std::move(t1)); // 10
  all_particles.push_back(std::move(t2)); // 11

  // Print out all the particles
  for(auto particle{all_particles.begin()};
      particle<all_particles.end(); ++particle)
  {
    (*particle)->print_info();
  }

  // Show the functionality
  std::cout<<std::endl<<std::endl;
  std::cout<<"==========================="<<std::endl;

  // .. sum the electrons
  std::cout<<"Electron sum:"<<std::endl;
  std::cout<<"e1:"<<std::endl;
  (*all_particles[0]).print_info();
  std::cout<<"e2:"<<std::endl;
  (*all_particles[1]).print_info();
  FourMomentum fm1{(*all_particles[0])+(*all_particles[1])};
  fm1.print_info();

  // .. dot products of four momenta
  std::cout<<"Dot product:"<<std::endl;
  std::cout<<"ae1:"<<std::endl;
  (*all_particles[6]).print_info();
  std::cout<<"am1:"<<std::endl;
  (*all_particles[7]).print_info();
  double dp1{dot_product(*all_particles[6], *all_particles[7])};
  std::cout<<dp1<<std::endl;

  // .. unique ptr for electron & moving
  std::cout<<"Moving electron:"<<std::endl;
  unique_ptr<Electron> moved_e = std::make_unique<Electron>(-1, 1.1, 2.2, 3.3, 4.4);
  std::cout<<"moved electron:"<<std::endl;
  moved_e->print_info();
  std::cout<<"new electron:"<<std::endl;
  Electron new_e = std::move(*moved_e);
  new_e.print_info();

  // .. shared ptr for tau
  std::cout<<"Shared tau:"<<std::endl;
  std::shared_ptr<Tau> sharedTau = std::make_shared<Tau>(-1, 3.2, 5.2, 2.45, 9.3);
  std::shared_ptr<Tau> tau1 = sharedTau;
  std::shared_ptr<Tau> tau2 = sharedTau;
  // .. printing information from either variable will give the same result
  std::cout<<"tau1:"<<std::endl;
  tau1->print_info();
  std::cout<<"tau2 (same info):"<<std::endl;
  tau2->print_info();

  return 0;
}