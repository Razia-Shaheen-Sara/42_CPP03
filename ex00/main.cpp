#include "ClapTrap.hpp"

int main() 
{

    std::cout << "\n=== START TESTING ===\n";
    std::cout << "\n=== OCF Tests ===\n";

    // Default constructor
    std::cout << "\n--- Default constructor ---\n";
    ClapTrap defaultClap;

    // Copy constructor
    std::cout << "\n--- Copy constructor ---\n";
    ClapTrap copyClap(defaultClap);

    // Copy assignment operator
    std::cout << "\n--- Copy assignment operator ---\n";
    ClapTrap assignClap;
    assignClap = defaultClap;

    std::cout << "\n=== Action Tests ===\n";
    ClapTrap clap("CL4P-TP"); 

    std::cout << "\n=== Test: attack ===\n";
    clap.attack("DummyTarget");

    std::cout << "\n=== Test: takeDamage(0) → should not reduce HP ===\n";
    clap.takeDamage(0);

    std::cout << "\n=== Test: takeDamage(5) → should reduce HP by 5 ===\n";
    clap.takeDamage(5);

    std::cout << "\n=== Test: beRepaired(3) → should increase HP by 3 ===\n";
    clap.beRepaired(3);

    std::cout << "\n=== Test: beRepaired(100) → should only repair until _maxHitPoints ===\n";
    clap.beRepaired(100);

    std::cout << "\n=== Test: beRepaired(1) → should not repair for being at maxHitPoints  ===\n";
    clap.beRepaired(1); // should not change anything

    std::cout << "\n=== Test: beRepaired(0) → should not change anything ===\n";
    clap.beRepaired(0); // should not change anything
    
    std::cout << "\n=== Test: attack after damage & repair ===\n";
    clap.attack("DummyTarget");

    std::cout << "\n=== Test: Energy exhaustion on fresh instance (10 EP + 1) ===\n";
    ClapTrap energyTest("CLP_EP"); // starts with 10 EP
    for (int i = 0; i <= 10; ++i)     // 10 hits + 1 fail
    energyTest.attack("DummyTarget");

    std::cout << "\n=== Test: HitPoint exhaustion on fresh instance ===\n";
    ClapTrap hpTest("CLP_HP"); // fresh instance → HP = 10
    hpTest.takeDamage(5);  // HP → 5
    hpTest.takeDamage(5);  // HP → 0
    hpTest.takeDamage(5);  // HP → 0 (cannot go negative)

    std::cout << "\n=== Test: action with 0 HP → should fail ===\n";
    hpTest.attack("DummyTarget");    // cannot attack, HP = 0
    hpTest.beRepaired(3);            // cannot repair, HP = 0
    hpTest.takeDamage(2);            // cannot take more damage, HP = 0

    std::cout << "\n=== Destructor prints once per object ==> \n"
            <<  "===parameterized, regular, \n"
            << "===prarameterized, energy exhaustion, \n"
            << "===parameterized, hitpoint exhaustion, \n"
            << "===default constructor, \n"
            << "===copy constructor (also default)and, \n"
            << "===assignment operator objects ===\n" << std::endl;

    return 0;
}
