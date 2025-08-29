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

    public:
		ClapTrap();                               // Default constructor
		ClapTrap(const ClapTrap& other);          // Copy constructor
		ClapTrap& operator=(const ClapTrap& other); // Assignment operator
		~ClapTrap();                              // Destructor

		// Subject-required constructor
		ClapTrap(const std::string& name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};
#endif

