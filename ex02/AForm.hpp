
#pragma once
#ifndef __AFORM_H__
# define __AFORM_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
class Bureaucrat;

// ************************************************************************** //
//                              AForm Class                                
// ************************************************************************** //

class AForm {

public:
    
	AForm ( std::string name, int grade2sign, int grade2exec );
	virtual ~AForm ( void );
	AForm (const AForm &aform);
	AForm & operator = (AForm &aform);

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
std::ostream & operator << (std::ostream& os, AForm &aform);

#endif /* __AFORM_H__ */

