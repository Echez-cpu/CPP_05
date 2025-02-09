#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(str target) : AForm::AForm("shrubbery Ascii things", 145, 137), input_target(target) {
	std::cout << "[Constructor] ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) : AForm::AForm(source), input_target(source.input_target) {
	std::cout << "[Copy] ShrubberyCreationForm copy constructor called." << std::endl;
	*this = source;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "[Destructor] ShrubberyCreationForm default destructor called." << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &original_copy) {
	if (this != &original_copy) {

    AForm::operator=(original_copy); 
    this->input_target = original_copy.input_target;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & output, ShrubberyCreationForm const &shru) {
	output << "Form name : " << shru.getName() << std::endl;
	output << "Signed : ";
	if (shru.getSigned())
		output << "True" << std::endl;
	else
		output << "False" << std::endl;
	output << "Need to be grade " << shru.getSignGrade() << " to sign it, and grade " << shru.getExecuteGrade() << " to execute it.";
	return output;
}


void	ShrubberyCreationForm::execute(Bureaucrat & executor) const {
	str				outfile = this->input_target + "_shrubbery";
	std::ofstream	output(outfile.c_str());


		if (!output) {
      		   std::cerr << "Error: Could not create file " << outfile << std::endl;
      		   return;
    		}
	
	executor.executeForm(*this);
	if (getSigned() == true) {
		output << "       _-_" << std::endl;
		output << "    /~~   ~~\\" << std::endl;
		output << " /~~         ~~\\" << std::endl;
		output << "{               }" << std::endl;
		output << " \\  _-     -_  /" << std::endl;
		output << "   ~  \\ //  ~" << std::endl;
		output << "_- -   | | _- _" << std::endl;
		output << "  _ -  | |   -_" << std::endl;
		output << "      // \\\\" << std::endl;
	}
	else
		std::cout << getName() << " is not signed, can't execute." << std::endl;
}
