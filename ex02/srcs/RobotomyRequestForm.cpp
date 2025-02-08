#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(str target) : AForm("Robocop", 72, 45), input_target(target) {
	std::cout << "[Constructor] RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source) : AForm::AForm(source), input_target(source.input_target) {
	std::cout << "[C] RobotomyRequestForm copy constructor called." << std::endl;
	*this = source;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "[Destructor] RobotomyRequestForm default destructor called." << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &original_copy) {
	if (this != &original_copy) {
	AForm::operator=(original_copy);		
	this->input_target = original_copy.input_target;
	}
	return *this;
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &robo) {
	output << "Form name : " << robo.getName() << std::endl;
	output << "Signed : ";
	if (robo.getSigned())
		output << "True" << std::endl;
	else
		output << "False" << std::endl;
	output << "Need to be grade " << robo.getSignGrade() << " to sign it, and grade " << robo.getExecuteGrade() << " to execute it.";
	return output;
}

void	RobotomyRequestForm::execute(Bureaucrat & executor) const {
	executor.executeForm(*this);
	if (getSigned() == true) {
		std::cout << "*Some drilling noise*" << std::endl;
		std::cout << "*Some drilling noise*" << std::endl;
		std::cout << "*Some drilling noise*" << std::endl;
		
		srand(time(NULL));   // call this in the main function
		int	nb = rand() % 100 + 1;
		if (nb % 2 == 0)
			std::cout << this->input_target << " has been robotomized." << std::endl;
		else
			std::cout << this->input_target << " failed." << std::endl;
	}
}
