#ifndef  INTERN_HPP
#define  INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef std::string str;

class AForm;
class Bureaucrat;

class Intern {
	public:
		Intern();
		Intern(Intern const &source);
		~Intern();

		Intern &	operator=(Intern const &original_copy);

		AForm *		makeForm(str form, str target) const;

		class WrongNameException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
	private:
		AForm *		makePresidential(str target) const;
		AForm *		makeRobotomy(str target) const;
		AForm *		makeShrubbery(str target) const;
};

#endif
