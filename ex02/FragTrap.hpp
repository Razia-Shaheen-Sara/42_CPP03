#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap 
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