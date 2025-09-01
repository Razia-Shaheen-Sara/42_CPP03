#include "FragTrap.hpp"
int main() 
{
    std::cout << "\n=== Default constructor: base then derived messages ===\n"; 
    FragTrap frag;

    std::cout << "\n=== Attack: FragTrap prints its own message ===\n";
    frag.attack("Frag's Enemy");

    std::cout << "\n=== TakeDamage: inherited from ClapTrap ===\n";
    frag.takeDamage(30);

    std::cout << "\n=== Repair: inherited from ClapTrap ===\n";
    frag.beRepaired(20);

    std::cout << "\n=== highfive: FragTrap's own method ===\n";
    frag.highFivesGuys();

    std::cout << "\n=== Parameterized constructor: base + derived message ===\n";
    FragTrap frag1("FRAG-TP");

    std::cout << "\n=== Attack: new message, no ClapTrap output ===\n";
    frag1.attack("Another Enemy");

    std::cout << "\n=== TakeDamage: inherited ===\n";
    frag1.takeDamage(50);

    std::cout << "\n=== Repair: inherited ===\n";
    frag1.beRepaired(25);

    std::cout << "\n=== highfive: new message ===\n";
    frag1.highFivesGuys();

    std::cout << "\n=== Copy constructor: base copy then derived message ===\n";
    FragTrap fragCopy(frag1);

    std::cout << "\n=== Attack: copied instance behaves like original ===\n";
    fragCopy.attack("Copy's Enemy");

    std::cout << "\n=== highfive: copied instance ===\n";
    fragCopy.highFivesGuys();

    std::cout << "\n=== Copy assignment: default constructor runs first, then base + derived assignment ===\n";
    FragTrap frag3;
    frag3 = frag1;

    // Note on copy assignment: Before the assignment, the default constructor runs
    // to create the target object(frag3). Then the assignment operator copies values from the source.

    std::cout << "\n=== Attack: assigned instance behaves like original ===\n";
    frag3.attack("Assigned Enemy");

    std::cout << "\n=== highfive: assigned instance ===\n";
    frag3.highFivesGuys();

    std::cout << "\n=== Destructor order: destroys in reverse creation ===\n";
    std::cout << "Expected: frag3 (renamed to FRAG-TP) -> fragCopy (copy of FRAG-TP) -> frag (FRAG-TP) -> frag (Default_FragTrap)\n";

    // Note on destructors: Each FragTrap object is destroyed in reverse order of creation.
    // First the derived (~FragTrap) destructor runs, then the base (~ClapTrap) destructor.
    // That's why multiple destructor messages appear when multiple objects go out of scope.

    return 0;
}



