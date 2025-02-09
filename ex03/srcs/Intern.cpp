#include "../include/Intern.hpp"

Intern::Intern() {
	std::cout << "[Constructor] Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &source) {
	std::cout << "[Default] Intern copy constructor called." << std::endl;
	*this = source;
}

Intern::~Intern() {
	std::cout << "[Destructor] Intern default destructor called." << std::endl;
}

Intern &	Intern::operator=(Intern const &original_copy) {
	(void)original_copy;
	return *this;
}


AForm *			Intern::makeForm(str name, str target) const {
	AForm *	form = NULL;
	AForm *	(Intern::*funcPtr[3])(str target) const = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};
	str		forms[3] = {"presidential pardon", "robotomy request", "shrubbery Ascii things"};
	int		i = 0;

	while (i < 3) {
		if (forms[i] == name) {
			form = (this->*funcPtr[i])(target);
			std::cout << "Intern create " << name << " form." << std::endl;
			return form;
		}
    i++;
	}
	std::cout << "Intern can't create " << name << " form : Invalid form name." << std::endl;
	throw Intern::WrongNameException();
	return NULL;
}

AForm *			Intern::makePresidential(str target) const {
	AForm *	form = new PresidentialPardonForm(target);
	return form;
}

AForm *			Intern::makeRobotomy(str target) const {
	AForm *	form = new RobotomyRequestForm(target);
	return form;
}

AForm *			Intern::makeShrubbery(str target) const {
	AForm *	form = new ShrubberyCreationForm(target);
	return form;
}

const char *	Intern::WrongNameException::what() const throw() {
	return ("Invalid form name.");
}
