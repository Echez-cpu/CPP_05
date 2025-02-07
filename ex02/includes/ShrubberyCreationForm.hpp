#ifndef  SHRUBBERYCREATIONFORM_HPP
#define  SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "AForm.hpp"

typedef std::string str;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(str target);
		ShrubberyCreationForm(ShrubberyCreationForm const &source);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &original_copy);

		void	execute(Bureaucrat & executor) const;
	private:
		str	input_target;
};

std::ostream &	operator<<(std::ostream & output, ShrubberyCreationForm const &shru);

#endif
