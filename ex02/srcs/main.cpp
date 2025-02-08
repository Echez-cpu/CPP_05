#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


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
        highRank.beSigned(shrubbery);
        midRank.beSigned(robotomy);
        highRank.beSigned(pardon);

        std::cout << "\n--- Executing Forms ---\n";
        shrubbery.execute(lowRank); // Should fail due to low grade
        shrubbery.execute(highRank); // Should create ASCII trees

        robotomy.execute(midRank); // Should succeed or fail randomly

        pardon.execute(lowRank); // Should fail due to low grade
        pardon.execute(highRank); // Should succeed
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
