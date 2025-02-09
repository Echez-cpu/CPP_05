#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"


int main() {
	try {
		std::cout << "\n--- Creating an Intern ---\n";
		Intern intern;

		std::cout << "\n--- Creating Bureaucrats ---\n";
		Bureaucrat manager("Alice", 1);
		Bureaucrat assistant("Bob", 50);

		std::cout << "\n--- Intern Creating Forms ---\n";
		AForm *pardonForm = intern.makeForm("presidential pardon", "Criminal");
		AForm *robotForm = intern.makeForm("robotomy request", "Patient");
		AForm *shrubForm = intern.makeForm("shrubbery creation", "Garden");

		std::cout << "\n--- Signing Forms ---\n";
		manager.signForm(*pardonForm);
		assistant.signForm(*robotForm);
		manager.signForm(*shrubForm);

		std::cout << "\n--- Executing Forms ---\n";
		manager.executeForm(*pardonForm);
		assistant.executeForm(*robotForm);
		manager.executeForm(*shrubForm);

		std::cout << "\n--- Attempting to Create an Invalid Form ---\n";
		try {
			AForm *invalidForm = intern.makeForm("coffee making", "Barista");
			delete invalidForm;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n--- Cleaning Up ---\n";
		delete pardonForm;
		delete robotForm;
		delete shrubForm;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
