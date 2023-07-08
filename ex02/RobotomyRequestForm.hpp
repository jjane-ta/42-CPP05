
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

// sound rizzz, bzzzzzz
    
	Form ( std::string name, int grade2sign, int grade2exec );
	virtual ~Form ( void );
	Form (const Form &form);
	Form & operator = (Form &form);

	const std::string	getName			( void ) const;
	int					getGrade2Sign	( void ) const;
	int					getGrade2Exec	( void ) const;
	bool				isSigned		( void );
	void				beSigned		( const Bureaucrat &bureaucrat);

	class GradeTooHighException :public std::runtime_error { public: GradeTooHighException();};
    class GradeTooLowException  :public std::runtime_error { public: GradeTooLowException ();};

private:	

	const std::string	_name;
	const int			_grade2sign;
	const int			_grade2exec;
	bool				_is_signed;

	static const int    _maxGrade = 1;
    static const int    _minGrade = 150;
};

// Overload output stream
std::ostream & operator << (std::ostream& os, Form &form);

#endif /* __FORM_H__ */

