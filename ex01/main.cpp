#include "ScavTrap.hpp"
int main() 
{
    std::cout << "\n=== Default constructor: base then derived messages ===\n"; 
    ScavTrap scav;

    std::cout << "\n=== Attack: ScavTrap prints its own message ===\n";
    scav.attack("Enemy");

    std::cout << "\n=== TakeDamage: inherited from ClapTrap ===\n";
    scav.takeDamage(30);

    std::cout << "\n=== Repair: inherited from ClapTrap ===\n";
    scav.beRepaired(20);

    std::cout << "\n=== guardGate: ScavTrap's own method ===\n";
    scav.guardGate();

    std::cout << "\n=== Parameterized constructor: base + derived message ===\n";
    ScavTrap scav2("SC4V-TP");

    std::cout << "\n=== Attack: new message, no ClapTrap output ===\n";
    scav2.attack("Another Enemy");

    std::cout << "\n=== TakeDamage: inherited ===\n";
    scav2.takeDamage(50);

    std::cout << "\n=== Repair: inherited ===\n";
    scav2.beRepaired(25);

    std::cout << "\n=== Repair max: inherited ===\n";
    scav2.beRepaired(100); // should only repair to max HP
    
    std::cout << "\n=== Repair: inherited; should not do anything because of max ===\n";
    scav2.beRepaired(1);   // should not change anything

    std::cout << "\n=== guardGate: new message ===\n";
    scav2.guardGate();

    std::cout << "\n=== Copy constructor: base copy then derived message ===\n";
    ScavTrap scav3(scav2);

    std::cout << "\n=== Attack: copied instance behaves like original ===\n";
    scav3.attack("Enemy for Copy");

    std::cout << "\n=== guardGate: copied instance ===\n";
    scav3.guardGate();

    std::cout << "\n=== Copy assignment: default constructor runs first, then base + derived assignment ===\n";
    ScavTrap scav4;
    scav4 = scav2;

    // Note on copy assignment: Before the assignment, the default constructor runs
    // to create the target object(scav4). Then the assignment operator copies values from the source.


    std::cout << "\n=== Attack: assigned instance behaves like original ===\n";
    scav4.attack("Assigned Enemy");

    std::cout << "\n=== guardGate: assigned instance ===\n";
    scav4.guardGate();

    std::cout << "\n=== Energy exhaustion test ===\n";
    ScavTrap energyTest("NoEnergy");
    for (int i = 0; i <= 50; ++i) // 50 EP + 1 fail
        energyTest.attack("DummyTarget");

    std::cout << "\n=== HP exhaustion test ===\n";
    ScavTrap hpTest("NoHP");
    hpTest.takeDamage(120); // kill immediately
    hpTest.attack("TargetAfterDeath"); // should fail
    hpTest.beRepaired(10);             // should fail
    hpTest.guardGate();                // should still work, not dependent on HP/EP

    std::cout << "\n=== Destructor order: destroys in reverse creation ===\n";
    std::cout << "Expected: noHP -> NoEnergy -> scav4 (renamed to SC4V-TP) -> scav3 (copy of SC4V-TP) -> scav2 (SC4V-TP) -> scav (Default_ScavTrap)\n";

    // Note on destructors: Each ScavTrap object is destroyed in reverse order of creation.
    // First the derived (~ScavTrap) destructor runs, then the base (~ClapTrap) destructor.
    // That's why multiple destructor messages appear when multiple objects go out of scope.


    return 0;
}



