#include "ScavTrap.hpp"

//REQUIREMENTS:
//Scavtrap is derived from Claptrap using public inheritance.
//Scavtrap constructors, destructor, and attack() will print different messages from Claptrap's.
//ScavTrap will use the attributes of ClapTrap (update ClapTrap accordingly:: means to make them protected).

// LESSON:
// Constructors are special: the init list (: ClapTrap(name)) lets you reuse the base constructor and tweak attributes/messages.
// Base functions (like attack() or operator=) can be reused by calling them in the derived class.
// If you want to change part of their behavior, you can either wrap them (call + add extra) or fully reimplement in the derived class.


// Default constructor
ScavTrap::ScavTrap() : ClapTrap() 
{
    _name = "Default_ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called \n" << "Name: "
    << _name << ", Hit Points: " << _hitPoints
    << ", Energy Points: " << _energyPoints
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) 
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called "
    << "Name: " << _name << ", Hit Points: " << _hitPoints 
    << ", Energy Points: " << _energyPoints 
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& source) : ClapTrap(source) 
{
    std::cout << "ScavTrap copy constructor called\n";
}

// Copy assignment operator
//here we call claptrap's operator= to handle the members because it is same, i just "ADD" the message
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) 
{
    if (this != &rhs)
    {
        std::cout << "ScavTrap copy assignment: renaming "
                  << _name << " -> " << rhs._name << "\n";
        ClapTrap::operator=(rhs);  // let base handle the members
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap destructor called for " << _name << "\n";
}

//we do not call ClapTrap::attack() because the message is different
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        --_energyPoints;
        std::cout << "ScavTrap " << _name 
                  << " attacks " << target
                  << ", causing " << _attackDamage 
                  << " points of damage!\n";
    }
    else
    {
        std::cout << "ScavTrap " << _name 
                  << " cannot attack due to insufficient EP or HP!\n";
    }
}

// Unique method for ScavTrap
void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!\n";
}
