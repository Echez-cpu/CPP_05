#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


int main() {

    srand(time(NULL));
    try {
        std::cout << "\n--- Bureaucrats Creation ---\n";
        Bureaucrat highRank("Alice", 1);
        Bureaucrat midRank("Bob", 30);
        Bureaucrat lowRank("Charlie", 150);
        Bureaucrat execFail("David", 140);

        std::cout << "\n--- Creating Forms ---\n";
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Human");
        PresidentialPardonForm pardon("Criminal");

        
        std::cout << "\n--- Signing Forms ---\n";
        shrubbery.beSigned(highRank);
        robotomy.beSigned(midRank);
        pardon.beSigned(highRank);

        try {
            pardon.beSigned(lowRank);
        } catch (std::exception &e) {
            std::cerr << "❌ Charlie failed to sign pardon: " << e.what() << std::endl;
        }

        try {
            robotomy.beSigned(execFail);
        } catch (std::exception &e) {
            std::cerr << "❌ David failed to sign robotomy: " << e.what() << std::endl;
        }

        std::cout << "\n--- Executing Forms ---\n";

        try {
            shrubbery.execute(lowRank);
        } catch (std::exception &e) {
            std::cerr << "❌ Charlie failed to execute shrubbery: " << e.what() << std::endl;
        }

        shrubbery.execute(highRank);

        robotomy.execute(midRank);
        try {
            robotomy.execute(execFail);
        } catch (std::exception &e) {
            std::cerr << "❌ David failed to execute robotomy: " << e.what() << std::endl;
        }

        try {
            pardon.execute(lowRank);
        } catch (std::exception &e) {
            std::cerr << "❌ Charlie failed to execute pardon: " << e.what() << std::endl;
        }

        pardon.execute(highRank);
        try {
            pardon.execute(execFail);
        } catch (std::exception &e) {
            std::cerr << "❌ David failed to execute pardon: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}




/*int	main() {
	Bureaucrat *	mum = new Bureaucrat("mum", 2);
	Bureaucrat *	rat = new Bureaucrat("rat", 10);
	Bureaucrat *	Miki = new Bureaucrat("Miki", 65);
	AForm *			shru = new ShrubberyCreationForm("rat");
	AForm *			robot = new RobotomyRequestForm("mum");

	try {
		robot->beSigned(*Mum);
		shru->beSigned(*rat);
		robot->execute(*mum);
		shru->execute(*mum);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << *shru << std::endl;
	std::cout << *robot << std::endl;

	delete robot;
	delete shru;
	delete Miki;
	delete rat;
	delete mum;
}*/

