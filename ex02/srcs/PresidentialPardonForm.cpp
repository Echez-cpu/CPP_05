#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(str target) : AForm::AForm("Presidential Pardon", 25, 5), input_target(target) {
	std::cout << "[Constructor] PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source) : AForm::AForm(source), input_target(source.input_target) {
	std::cout << "[Copy] PresidentialPardonForm copy constructor called." << std::endl;
	*this = source;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "[Destructor] PresidentialPardonForm default destructor called." << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &original_copy) {
	if (this != &original_copy) {
		this->input_target = original_copy.input_target;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & output, PresidentialPardonForm const &pres) {
	o << "Form name : " << rSym.getName() << std::endl;
	o << "Signed : ";
	if (rSym.getSigned())
		o << "True" << std::endl;
	else
		o << "False" << std::endl;
	o << "Need to be grade " << rSym.getSignGrade() << " to sign it, and grade " << rSym.getExecuteGrade() << " to execute it.";
	return o;
}


void	PresidentialPardonForm::execute(Bureaucrat & executor) const {
	executor.executeForm(*this);
	if (this->_signed == true)
		std::cout << this->_target.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		std::cout << this->_name << " is not signed, can't execute." << std::endl;
}
