
#pragma once
#ifndef __FORM_H__
# define __FORM_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
class Bureaucrat;

// ************************************************************************** //
//                              Form Class                                
// ************************************************************************** //

class Form {

public:
    
	Form ( std::string name, int grade );
	virtual ~Form ( void );
	Form (const Form &form);
	Form operator = (const Form &form);

	const std::string	getName		( void ) const;
	int					getGrade	( void ) const;
	bool				isSigned	( void );
	void				beSigned	( const Bureaucrat &bureaucrat);

	class GradeTooHighException :public std::runtime_error { public: GradeTooHighException();};
    class GradeTooLowException  :public std::runtime_error { public: GradeTooLowException ();};

private:	

	const std::string	_name;
	const int			_grade;
	bool				_is_signed;

	static const int    _maxGrade = 1;
    static const int    _minGrade = 150;
};

// Overload output stream
std::ostream & operator << (std::ostream& os, Form &form);

#endif /* __FORM_H__ */

