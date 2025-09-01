#include "DiamondTrap.hpp"


int main() 
{
    std::cout << "=== Default constructor - ClapTrap default (ONCE) -> fragtrap default -> scavtrap default -> DiamondTrap Default ===\n";
    DiamondTrap d1;

    std::cout << "\n=== Parameterized constructor -ClapTrap name Diamondy_clap_name, DiamondTrap name Diamondy ===\n";
    DiamondTrap d2("Diamondy");

    std::cout << "\n=== Attack test (uses ScavTrap attack)===\n";
    d2.attack("EnemyTarget");

    std::cout << "\n=== whoAmI test -'DiamondTrap name: Diamondy, ClapTrap name: Diamondy_clap_name' ===\n";
    d2.whoAmI();

    std::cout << "\n=== takeDamage(30): inherited ===\n";
    d2.takeDamage(30);
    
    std::cout << "\n=== beRepaired(25): inherited ===\n";
    d2.beRepaired(25);

    std::cout << "\n=== beRepaired(100): inherited ===\n";
    d2.beRepaired(100); // should only repair to max HP
    
    std::cout << "\n=== Repair: inherited; should not do anything because of max ===\n";
    d2.beRepaired(1);  

    std::cout << "\n=== Copy constructor test - names and stats copied from d2 ===\n";
    DiamondTrap CopyD(d2);

    std::cout << "\n ====CopyD whoAmI - expect same names as d2 === \n";
    CopyD.whoAmI();

    std::cout << "\n === CopyD attack - should be same as d2 === \n";
    CopyD.attack("CopiedEnemy");

    std::cout << "\n === Assignment operator test - names and stats  same as d2 ===\n";
    DiamondTrap AssignD;
    AssignD = d2;

    std::cout << "\n === AssignD whoAmI - expect same names as d2 ===\n";
    AssignD.whoAmI();

    std::cout << "\n === AssignD attack - ==='\n";
    AssignD.attack("AssignedEnemy");

    std::cout << "\n=== Energy & HP exhaustion test - attacks until energy 0, then 'doesn't have any energy' messages ===\n";
    for (int i = 0; i < 50; ++i)
        AssignD.attack("Dummy");

    std::cout << "\n === AssignD takeDamage 150 - expect: HP drops to 0, cannot attack or repair ===\n";
    AssignD.takeDamage(150);  

    std::cout << "\n === AssignD attack after death - failure ===== \n";
    AssignD.attack("AfterDeath"); 

    std::cout << "\n === AssignD beRepaired after death - expect: cannot be repaired === \n";
    AssignD.beRepaired(20);

    
    std::cout << "\n=== test: make extra diamond ===\n";
    DiamondTrap d3("ExtraDiamond");

    std::cout << "\n=== expect: DiamondTrap name: ExtraDiamond, ClapTrap name: ExtraDiamond_clap_name === \n";
    d3.whoAmI();

    std::cout << "\n=== Destructor order - expect: reverse creation order: ExtraDiamond -> AssignD -> CopyD -> d2 -> d1(default) ===\n";

    return 0;
}






