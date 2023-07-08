
#pragma once
#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

// ************************************************************************** //
//                              Bureaucrat Class                                
// ************************************************************************** //

class Bureaucrat {

public:
    
	Bureaucrat ( std::string name, int grade );
	virtual ~Bureaucrat ( void );
	Bureaucrat (const Bureaucrat &bureaucrat);
	Bureaucrat & operator = (const Bureaucrat &bureaucrat);

	const std::string	getName         ( void ) const;
	int         		getGrade        ( void ) const;
    void        		increaseGrade   ( void );
	void        		decreaseGrade   ( void );
	void				signForm		( Form *form ) const;

	class GradeTooHighException :public std::runtime_error { public: GradeTooHighException();};
    class GradeTooLowException  :public std::runtime_error { public: GradeTooLowException ();};
        
private:   

	const std::string	_name;
	int                 _grade; //[1-150]
    static const int    _maxGrade = 1;
    static const int    _minGrade = 150;
};

// Overload output stream
std::ostream & operator << (std::ostream& os, Bureaucrat &bureaucrat);

#endif /* __BUREAUCRAT_H__ */

