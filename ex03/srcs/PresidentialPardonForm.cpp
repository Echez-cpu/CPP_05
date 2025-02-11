#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"

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
		AForm::operator=(original_copy);
		this->input_target = original_copy.input_target;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & output, PresidentialPardonForm const &pres) {
	output << "AForm name : " << pres.getName() << std::endl;
	output << "Signed : ";
	if (pres.getSigned())
		output << "True" << std::endl;
	else
		output << "False" << std::endl;
	output << "Need to be grade " << pres.getSignGrade() << " to sign it, and grade " << pres.getExecuteGrade() << " to execute it.";
	return output;
}


void	PresidentialPardonForm::execute(Bureaucrat & executor) const {
	// remember to check if signed before trying to execute
	executor.executeForm(*this);
	if (getSigned() == true)
		std::cout << this->input_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		std::cout << getName() << " is not signed, can't execute." << std::endl;
}
