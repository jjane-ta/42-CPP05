
#pragma once
#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class Bureaucrat;

// ************************************************************************** //
//                              PresidentialPardonForm Class                                
// ************************************************************************** //

class PresidentialPardonForm: AForm {

public:
    
	PresidentialPardonForm( std::string target );
	virtual ~PresidentialPardonForm ( void );
	PresidentialPardonForm (const PresidentialPardonForm & form);
	PresidentialPardonForm operator = (const PresidentialPardonForm & form);

private:
	static const int	_grade2sign;
	static const int	_grade2exec;
	std::string			_target;

};

// Overload output stream
std::ostream & operator << (std::ostream& os, PresidentialPardonForm &form);

#endif /* __PRESIDENTIALPARDONFORM_H__ */

