#include "../includes/Form.hpp"

Form::Form(str name, int signGrade) : input_name(name), input_signed(false), input_signGrade(signGrade), input_executeGrade(signGrade - 1) {

	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw From::GradeTooLowException();
	std::cout << "[Constructor] Form parameterized constructor called." << std::endl;
}

Form::Form() : input_name(""), input_signed(false), input_signGrade(150), input_executeGrade(150) {
	std::cout << "[C] Form default constructor called." << std::endl;
}

Form::Form(Form const &source) : input_name(source.getName()), input_signGrade(source.getSignGrade()), input_executeGrade(source.getExecuteGrade()) {
	std::cout << "[Copy] Form copy constructor called." << std::endl;
	*this = source;
}

Form::~Form() {
	std::cout << "[Destructor] Form default destructor called." << std::endl;
}

Form &	Form::operator=(Form const &original_copy) {
	if (this != &original_copy) {
		this->input_signed = original_copy.getSigned();
	}
	return *this;
}

std::ostream   &operator<<(std::ostream & output, Form const &f) {
	output << "Form name : " << f.getName() << std::endl;
	output << "Signed : ";
	if (f.getSigned())
		output << "True" << std::endl;
	else
		output << "False" << std::endl;
	output << "Need to be grade " << f.getSignGrade() << " to sign it, and grade " << f.getExecuteGrade() << " to execute it.";
	return output;
}


str		Form::getName() const {
	return this->input_name;
}

bool	Form::getSigned() const {
	return this->input_signed;
}

int		Form::getSignGrade() const {
	return this->input_signGrade;
}

int		Form::getExecuteGrade() const {
	return this->input_executeGrade;
}


void			Form::beSigned(Bureaucrat &pupil) {
	if (this->input_signed) {
		std::cout << this->input_name << " is already signed." << std::endl; 
		return;
	}
	if (pupil.getGrade() > this->input_signGrade) {
		pupil.signForm(this->input_name, this->input_signed);
		throw Form::GradeTooLowException();
	}
	else {
		this->input_signed = true;
		pupil.signForm(this->input_name, this->input_signed);
	}
}

const char *	Form::GradeTooHighException::what() const throw() {
	return ("The Form is too proud (higher than 1).");
}

const char *	Form::GradeTooLowException::what() const throw() {
	return ("The Form (lower than 150) is forbidden");
}
