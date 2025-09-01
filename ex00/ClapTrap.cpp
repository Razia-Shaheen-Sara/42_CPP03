#include "ClapTrap.hpp"

//Attacking and repairing each cost 1 energy point.
//Default constructor
ClapTrap::ClapTrap() 
    : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap default constructor called\n";
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& source) 
{
    _name = source._name;
    _hitPoints = source._hitPoints;
    _energyPoints = source._energyPoints;
    _attackDamage = source._attackDamage;
    std::cout << "ClapTrap copy constructor called\n";
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    if (&rhs != &(*this))  // check self-assignment
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator called\n";
    return *this; //self pointer dereferenced
}

// Parameterized constructor (required by subject)
ClapTrap::ClapTrap(const std::string& name) 
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap constructor with name called\n"  << std::endl;
}

// ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}
ClapTrap::~ClapTrap()
{
    std::cout << "Claptrap Destructor called for " << _name << "\n";
}

void ClapTrap::attack(const std::string& target) 
{
    if (_energyPoints > 0 && _hitPoints > 0) 
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage! Attack Cost: 1 EP. (EP left: " 
                  << _energyPoints << ")\n" 
                  << std::endl;
    } 
    else 
        std::cout << "ClapTrap " << _name << " cannot attack due to insufficient energy point or hitpoint!\n" << std::endl;
}


//It takes away "amount" number from ClapTrap’s hit points when it gets hit
void ClapTrap::takeDamage(unsigned int amount) 
{
    unsigned int newHitPoints = 0;
    if (amount == 0)
    {
        std::cout << "ClapTrap " << _name << " takes no damage because given amount = 0\n" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot take any damage because hitPoints = 0!\n" << std::endl;
        return;
    }
    if (amount >= _hitPoints) //prevent negative hit points
        newHitPoints = 0;
    else
        newHitPoints = _hitPoints - amount;
    _hitPoints = newHitPoints;
    std::cout << "ClapTrap " << _name << " takes " << amount 
              << " damage, HP now " << _hitPoints << "\n" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    unsigned int newHitPoints = 0;
    if (amount == 0)
    {
        std::cout << "ClapTrap " << _name << " repairs nothing because given amount = 0!\n" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair because hitpoint = 0\n" << std::endl;
        return;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " cannot repair due to insufficient energy!\n" << std::endl;
        return;
    }
    newHitPoints = _hitPoints + amount;
    _hitPoints = newHitPoints;
    _energyPoints--; // // Decrease energy points by 1 for repairing
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount 
              << " points, HP now " << _hitPoints 
              << " ;Repair Cost:1 EP; (EP left: " << _energyPoints << ")\n" << std::endl;
}
