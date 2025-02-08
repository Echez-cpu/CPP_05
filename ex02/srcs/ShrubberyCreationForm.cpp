#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(str target) : AForm::AForm("Ascii things", 145, 137), input_target(target) {
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

std::ostream &	operator<<(std::ostream & output, ShrubberyCreationForm const &rSym) {
	o << "Form name : " << rSym.getName() << std::endl;
	o << "Signed : ";
	if (rSym.getSigned())
		o << "True" << std::endl;
	else
		o << "False" << std::endl;
	o << "Need to be grade " << rSym.getSignGrade() << " to sign it, and grade " << rSym.getExecuteGrade() << " to execute it.";
	return o;
}


void	ShrubberyCreationForm::execute(Bureaucrat & executor) const {
	str				outfile = this->input_target.getName() + "_shrubbery";
	std::ofstream	output(outfile.c_str());
	
	executor.executeForm(*this);
	if (this->_signed == true) {
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
		std::cout << this->_name << " is not signed, can't execute." << std::endl;
}
