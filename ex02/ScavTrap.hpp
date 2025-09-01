#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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