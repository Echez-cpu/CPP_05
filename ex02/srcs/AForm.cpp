#include "../includes/AForm.hpp"

AForm::AForm(str name, int signGrade, int executeGrade) : input_name(name), input_signed(false), input_signGrade(signGrade), input_executeGrade(executeGrade) {

	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "[Constructor] AForm parameterized constructor called." << std::endl;
}

AForm::AForm() : input_name(""), input_signed(false), input_signGrade(150), input_executeGrade(150) {
	std::cout << "[C] AForm default constructor called." << std::endl;
}

AForm::AForm(Form const &source) : input_name(source.getName()), input_signGrade(source.getSignGrade()), input_executeGrade(source.getExecuteGrade()) {
	std::cout << "[Copy] AForm copy constructor called." << std::endl;
	*this = source;
}

AForm::~AForm() {
	std::cout << "[Destructor] AForm default destructor called." << std::endl;
}

AForm &	AForm::operator=(Form const &original_copy) {
	if (this != &original_copy) {
		this->input_signed = original_copy.getSigned();
	}
	return *this;
}

std::ostream   &operator<<(std::ostream & output, AForm const &aF) {
	output << "AForm name : " << aF.getName() << std::endl;
	output << "Signed : ";
	if (aF.getSigned())
		output << "True" << std::endl;
	else
		output << "False" << std::endl;
	output << "Need to be grade " << aF.getSignGrade() << " to sign it, and grade " << f.getExecuteGrade() << " to execute it.";
	return output;
}


str		AForm::getName() const {
	return this->input_name;
}

bool	AForm::getSigned() const {
	return this->input_signed;
}

int		Form::getSignGrade() const {
	return this->input_signGrade;
}

int		AForm::getExecuteGrade() const {
	return this->input_executeGrade;
}


void			AForm::beSigned(Bureaucrat &pupil) {
	if (this->input_signed) {
		std::cout << this->input_name << " is already signed." << std::endl; 
		return;
	}
	if (pupil.getGrade() > this->input_signGrade) {
		pupil.signForm(this->input_name, this->input_signed);
		throw AForm::GradeTooLowException();
	}
	else {
		this->input_signed = true;
		pupil.signForm(this->input_name, this->input_signed);
	}
}

const char *	AForm::GradeTooHighException::what() const throw() {
	return ("The Form is too proud (higher than 1).");
}

const char *	AForm::GradeTooLowException::what() const throw() {
	return ("The Form (lower than 150) or (lower than Bureacrat) is forbidden");
}
