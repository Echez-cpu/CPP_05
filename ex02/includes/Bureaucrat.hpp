#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <climits>

#include "AForm.hpp"

class AForm;  // Forward Declaration

typedef std::string str;

class Bureaucrat {
	public:
		Bureaucrat(str name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat const &source);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const &original_copy);
		str				getName() const;
		int				getGrade() const;

		void			promote();
		void			demote();
		void			signForm(str name, bool sign);
		void			executeForm(AForm const  &form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
	private:
		str const	input_name;
		int			input_grade;
};

std::ostream &	operator<<(std::ostream & output, Bureaucrat const &bureaucrat);

#endif
