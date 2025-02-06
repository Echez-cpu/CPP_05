Bureaucrat::Bureaucrat(str name, int grade) : input_name(name) {
	std::cout << "[Constructor] Bureaucrat base (parameterized) constructor has been called." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->input_grade = grade;
}


