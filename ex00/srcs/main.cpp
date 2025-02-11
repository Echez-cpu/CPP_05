#include "../includes/Bureaucrat.hpp"

int main() {
    Bureaucrat *Gabriel = NULL; // i am using pointers, i could also just do it on the stack
    Bureaucrat *Lucifer = NULL;

    try {
        Gabriel = new Bureaucrat("Gabriel", 5);
        std::cout << *Gabriel << std::endl;
        Gabriel->promote();
        std::cout << "After promotion: " << *Gabriel << std::endl;
    }
    catch (const std::exception  &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

        if(Gabriel  == NULL) // incase i decide to initialize with an invalid rank
            return(0);
    
    // Test Bureaucrat copy constructor
    try {
        Lucifer = new Bureaucrat(*Gabriel);
        std::cout << "Copied Bureaucrat Lucifer: " << *Lucifer << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    // Test invalid Bureaucrat creation (grade too high)
    try {
        Bureaucrat TooHigh("Metatron", 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception for high grade: " << e.what() << '\n';
    }

    // Test invalid Bureaucrat creation (grade too low)
    try {
        Bureaucrat TooLow("Beelzebub", 151); // Should throw exception
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception for low grade: " << e.what() << '\n';
    }

    try {
        Bureaucrat TopBureaucrat("Michael", 1);
        std::cout << "Attempting to promote: " << TopBureaucrat << std::endl;
        TopBureaucrat.promote(); // Should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception for over-promotion: " << e.what() << '\n';
    }

    try {
        Bureaucrat LowestBureaucrat("Azazel", 150);
        std::cout << "Attempting to demote: " << LowestBureaucrat << std::endl;
        LowestBureaucrat.demote(); // Should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cerr << "Caught exception for over-demotion: " << e.what() << '\n';
    }

    // Test copy assignment
    try {
        Bureaucrat CopyTarget("Raphael", 10);
        CopyTarget = *Lucifer; // Using the copy assignment operator
        std::cout << "After assignment, CopyTarget: " << CopyTarget << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in copy assignment: " << e.what() << '\n';
    }

    delete Gabriel;
    delete Lucifer;

    return 0;
}
