#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>


//change "public Claptrap" to "public virtual Claptrap" to avoid adding another copy of Claptrap from scavtrap to DiamondTrap
//because virtual inheritance ensures only one shared instance of the base class exists in the inheritance hierarchy.
//otherwise, without virtual inheritance, DiamondTrap would inherit two separate instances of ClapTrap: one from ScavTrap and one from FragTrap.

class FragTrap : virtual public ClapTrap 
{
public:
    // Constructors and Destructor
    FragTrap();   // Default constructor
    FragTrap(const std::string &name); // Parameterized constructor
    FragTrap(const FragTrap &source); // Copy constructor   
    ~FragTrap();

    // Assignment operator
    FragTrap &operator=(const FragTrap &rhs);

    // Member functions
    void attack(const std::string& target);
    void highFivesGuys() const;
};

#endif

