#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include <string>
# include <iostream>


class DiamondTrap : public FragTrap, public ScavTrap //no claptrap here because claptrap it diamond's grandparent!
{
    private:
        std::string _name; // DiamondTrap's own name == the difference between scavtrap and fragtrap

    public:
        DiamondTrap();                               // Default constructor
        DiamondTrap(const std::string& name);        // Parameterized constructor
        DiamondTrap(const DiamondTrap& source);      // Copy constructor
        DiamondTrap& operator=(const DiamondTrap& rhs); // Copy assignment operator
        ~DiamondTrap();                              // Destructor

        void attack(const std::string& target);      // Override attack to use ScavTrap's version
        void whoAmI();                               // Unique method to reveal both names
};
#endif