#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//change "public Claptrap" to "public virtual Claptrap" to avoid adding another copy of Claptrap from scavtrap to DiamondTrap
//because virtual inheritance ensures only one shared instance of the base class exists in the inheritance hierarchy.
//otherwise, without virtual inheritance, DiamondTrap would inherit two separate instances of ClapTrap: one from ScavTrap and one from FragTrap.


class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();                               // Default constructor
    ScavTrap(const std::string& name);        // Parameterized constructor
    ScavTrap(const ScavTrap& source);          // Copy constructor
    ScavTrap& operator=(const ScavTrap& rhs); // Copy assignment operator
    ~ScavTrap();                              // Destructor

    void	attack(const std::string& target); // Override attack method because subject requires different behavior
    void    guardGate();                         // Unique method for ScavTrap
};

#endif // SCAVTRAP_HPP