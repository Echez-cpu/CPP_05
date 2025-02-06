#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

int main() {
    try {
        std::cout << "===== Creating Forms =====" << std::endl;
        Form f1("Tax Report", 50);
        Form f2("Classified Document", 1);
        Form f3("Simple Request", 100);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        std::cout << "\n===== Creating Bureaucrats =====" << std::endl;
        Bureaucrat highRank("Gabriel", 1);
        Bureaucrat midRank("Raphael", 50);
        Bureaucrat lowRank("Azazel", 100);

        std::cout << highRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << lowRank << std::endl;

        std::cout << "\n===== Signing Forms =====" << std::endl;

        // High-rank bureaucrat signs all forms
        highRank.signForm(f1);
        highRank.signForm(f2);
        highRank.signForm(f3);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        // Mid-rank bureaucrat tries to sign
        midRank.signForm(f1);  // Should succeed (50 required, 50 provided)
        midRank.signForm(f2);  // Should fail (1 required, 50 provided)

        // Low-rank bureaucrat tries to sign
        lowRank.signForm(f3);  // Should succeed (100 required, 100 provided)
        lowRank.signForm(f1);  // Should fail (50 required, 100 provided)

        std::cout << "\n===== Exception Testing =====" << std::endl;
        try {
            Form invalidForm("Impossible Form", 0);  // Invalid, should throw
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << '\n';
        }

        try {
            Form invalidForm("Unreachable Form", 151);  // Invalid, should throw
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
    }

    return 0;
}
