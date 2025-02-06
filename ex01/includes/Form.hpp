#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

typedef std::string str;

#include "Bureaucrat.hpp"

class Form {
	public:
		Form(str name, int signGrade);
		Form();
		Form(Form const &source);
		~Form();

		Form &	operator=(Form const &original_copy);
		str		getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecuteGrade() const;

		void	beSigned(Bureaucrat &pupil);

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
		bool		input_signed;
		int const	input_signGrade;
		int const	input_executeGrade;
};

std::ostream &	operator<<(std::ostream & output, Form const &f);

#endif
