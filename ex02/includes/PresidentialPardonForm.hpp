#ifndef  PRESIDENTIALPARDONFORM_HPP
#define  PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

typedef std::string str;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(str  target);
		PresidentialPardonForm(PresidentialPardonForm const &source);
		~PresidentialPardonForm();

		PresidentialPardonForm &	operator=(PresidentialPardonForm const &original_copy);

		void	execute(Bureaucrat & executor) const;
	private:
		str	input_target;
};

std::ostream &	operator<<(std::ostream & output, PresidentialPardonForm const &pres);

#endif
