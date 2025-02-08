#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "\n--- Bureaucrats Creation ---\n";
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 50);
        Bureaucrat lowRank("Charlie", 150);

        std::cout << "\n--- Creating Forms ---\n";
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Human");
        PresidentialPardonForm pardon("Criminal");

        std::cout << "\n--- Signing Forms ---\n";
        highRank.signForm(shrubbery);
        midRank.signForm(robotomy);
        highRank.signForm(pardon);

        std::cout << "\n--- Executing Forms ---\n";
        lowRank.executeForm(shrubbery); // Should fail due to low grade
        highRank.executeForm(shrubbery); // Should create ASCII trees

        midRank.executeForm(robotomy); // Should succeed or fail randomly

        lowRank.executeForm(pardon); // Should fail due to low grade
        highRank.executeForm(pardon); // Should succeed
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
