#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(str name, int grade) : input_name(name) {
	std::cout << "[Constructor] Bureaucrat base (parameterized) constructor has been called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->input_grade = grade;
}

Bureaucrat::Bureaucrat() {
	std::cout << "[Default constructor] for Bureaucrat called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &source) : input_name(source.getName()) {
	std::cout << "[Constructor] Bureaucrat copy constructor called." << std::endl;
	*this = source;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "[Destructor] Bureaucrat default destructor called." << std::endl;
}

Bureaucrat   &Bureaucrat::operator=(Bureaucrat const &original_copy) {
	if (this != &original_copy) {
		this->input_grade = original_copy.input_grade;
	}
	return *this;
}

std::ostream    &operator<<(std::ostream & output, Bureaucrat const &Bureaucrat) {
	output << Bureaucrat.getName() << ", bureaucrat grade : " << Bureaucrat.getGrade();
	return output;
}


str	Bureaucrat::getName() const {
	return this->input_name;
}

int	Bureaucrat::getGrade() const {
	return this->input_grade;
}



void			Bureaucrat::promote() {
	if (this->input_grade > 1)
		this->input_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::demote() {
	if (this->input_grade < 150)
		this->input_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("A bureaucrat can't have a grade greater than 1.");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("A bureaucrat can't have a grade lower than 150.");
}



void			Bureaucrat::signForm(str name, bool sign) {
	if (sign)
		std::cout << this->input_name << " signed " << name << "." << std::endl;
	else
		std::cout << this->input_name << " couldn't sign " << name << " because he doesn't meet the requirements to do so." << std::endl;
}
