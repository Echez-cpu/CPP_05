#ifndef  ROBOTOMYREQUESTFORM_HPP
#define  ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include "AForm.hpp"

typedef std::string str;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(str target);
		RobotomyRequestForm(RobotomyRequestForm const &source);
		~RobotomyRequestForm();

		RobotomyRequestForm &	operator=(RobotomyRequestForm const &original_copy);

		void	execute(Bureaucrat & executor) const;
	private:
		str	input_target;
};

std::ostream &	operator<<(std::ostream & output, RobotomyRequestForm const &robo);

#endif
