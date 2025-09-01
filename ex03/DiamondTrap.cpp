#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() 
{
    _name = "Default_Diamondy";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    _maxHitPoints = 100; // Set max hit points for FragTrap
    std::cout << "DiamondTrap default constructor called \n" << "Name: "
    << _name << ", Hit Points: " << _hitPoints
    << ", Energy Points: " << _energyPoints
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;

}

// Parameterized constructor
// the calling order of fragtrap and scavtrap should be this exactly to shut -weorder flag! 
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) // Initialize ClapTrap with modified name
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    _maxHitPoints = 100; // Set max hit points for FragTrap
    std::cout << "DiamondTrap parameterized constructor called \n"
    << "Name: " << _name << ", Hit Points: " << _hitPoints 
    << ", Energy Points: " << _energyPoints 
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& source) 
    : ClapTrap(source), FragTrap(source), ScavTrap(source), _name(source._name) // Copy base parts and own member
{
    std::cout << "DiamondTrap copy constructor called\n";
}
// Copy assignment operator
//direct inheeitance from 
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) 
{
    if (this != &rhs)
    {
        std::cout << "DiamondTrap copy assignment: renaming "
                  << _name << " -> " << rhs._name << "\n";
        ClapTrap::operator=(rhs);
        ScavTrap::operator=(rhs);
        FragTrap::operator=(rhs);
        _name = rhs._name; // Assign own member
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() 
{
    std::cout << "DiamondTrap destructor called for " << _name << "\n";
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target); // Use ScavTrap's attack method
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name 
              << ", ClapTrap name: " << ClapTrap::_name << "\n";
}
