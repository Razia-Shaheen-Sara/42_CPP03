#include "FragTrap.hpp"

// LESSON:
// Constructors are special: the init list (: ClapTrap(name)) lets you reuse the base constructor and tweak attributes/messages.
// Base functions (like attack() or operator=) can be reused by calling them in the derived class.
// If you want to change part of their behavior, you can either wrap them (call + add extra) or fully reimplement in the derived class.


// Default constructor
FragTrap::FragTrap() : ClapTrap() 
{
    _name = "Default_Fraggy";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    _maxHitPoints = 100; // Set max hit points for FragTrap
    std::cout << "FragTrap default constructor called \n" << "Name: "
    << _name << ", Hit Points: " << _hitPoints
    << ", Energy Points: " << _energyPoints
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) 
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    _maxHitPoints = 100; // Set max hit points for FragTrap
    std::cout << "FragTrap parameterized constructor called \n"
    << "Name: " << _name << ", Hit Points: " << _hitPoints 
    << ", Energy Points: " << _energyPoints 
    << ", Attack Damage: " << _attackDamage << "\n" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& source) : ClapTrap(source) 
{
    std::cout << "FragTrap copy constructor called\n";
}

// Copy assignment operator
//here we call claptrap's operator= to handle the members because it is same, i just "ADD" the message
FragTrap& FragTrap::operator=(const FragTrap& rhs) 
{
    if (this != &rhs)
    {
        std::cout << "FragTrap copy assignment: renaming "
                  << _name << " -> " << rhs._name << "\n";
        ClapTrap::operator=(rhs);  // let base handle the members
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called for " << _name << "\n";
}

//we do not call ClapTrap::attack() because the message is different
//we can only call if the message is same or if we want to add extra functionality
void FragTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        --_energyPoints;
        std::cout << "FragTrap " << _name 
                  << " attacks " << target
                  << ", causing " << _attackDamage 
                  << " points of damage!\n";
    }
    else
    {
        std::cout << "FragTrap " << _name 
                  << " cannot attack due to insufficient EP or HP!\n";
    }
}

void FragTrap::highFivesGuys() const
{
    std::cout << "FragTrap " << _name << " requests a high five! ✋\n";
}