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

        try {
            f1.beSigned(highRank);
            std::cout << "✔️ " << highRank.getName() << " signed " << f1.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "❌ " << highRank.getName() << " couldn't sign " << f1.getName() << " because " << e.what() << std::endl;
        }

        try {
            f2.beSigned(midRank);
            std::cout << "✔️ " << midRank.getName() << " signed " << f2.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "❌ " << midRank.getName() << " couldn't sign " << f2.getName() << " because " << e.what() << std::endl;
        }

        try {
            f3.beSigned(lowRank);
            std::cout << "✔️ " << lowRank.getName() << " signed " << f3.getName() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "❌ " << lowRank.getName() << " couldn't sign " << f3.getName() << " because " << e.what() << std::endl;
        }

        std::cout << "\n===== Form Status After Signing =====" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
        std::cout << f3 << std::endl;

        std::cout << "\n===== Exception Testing =====" << std::endl;

        try {
            Form invalidForm1("Impossible Form", 2);  // Invalid, should throw
            invalidForm1.beSigned(midRank);

        } catch (const std::exception& e) {
            std::cerr << "❌ Exception caught: " << e.what() << '\n';
        }

        try {
            Form invalidForm("Unreachable Form", 151);  // Invalid, should throw

            //invalidForm.beSigned(lowRank);

        } catch (const std::exception& e) {
            std::cerr << "❌ Exception caught: " << e.what() << '\n';
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << '\n';
    }

    return 0;
}


