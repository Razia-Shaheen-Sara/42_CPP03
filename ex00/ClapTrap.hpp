#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap
{
    private:
        std::string		_name;
        unsigned int	_hitPoints;
        unsigned int	_energyPoints;
        unsigned int	_attackDamage;
		unsigned int	_maxHitPoints; // To track maximum hit points

    public:
        ClapTrap();                               // Default constructor
        ClapTrap(const ClapTrap& source);          // Copy constructor
        ClapTrap& operator=(const ClapTrap& rhs); // Copy assignment operator
        ~ClapTrap();                              // Destructor

		ClapTrap(const std::string& name);        // Parameterized constructor
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
#endif
