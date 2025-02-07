#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

typedef std::string str;

#include "Bureaucrat.hpp"

class Bureaucrat; // forward Declaration...

class AForm {
	public:
		AForm(str name, int signGrade, int executeGrade);
		AForm();
		AForm(AForm const &source);
		virtual ~AForm();

		AForm  &operator=(AForm const &original_copy);
		str		getName() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExecuteGrade() const;

		void			beSigned(Bureaucrat &pupil);
		virtual void	execute(Bureaucrat  &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what() const throw();
		};
	protected:
		str const	input_name;
		bool		input_signed;
		int const	input_signGrade;
		int const	input_executeGrade;
};

std::ostream &	operator<<(std::ostream & output, AForm const &aF);

#endif
