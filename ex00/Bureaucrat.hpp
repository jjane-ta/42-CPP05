
#pragma once
#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

# include <iostream>
# include <iomanip>
# include <string>
# include <stdexcept>

// ************************************************************************** //
//                              Bureaucrat Class                                
// ************************************************************************** //

class Bureaucrat {

public:
    
	Bureaucrat ( std::string name, int grade );
	virtual ~Bureaucrat ( void );
	Bureaucrat (const Bureaucrat &bureaucrat);
	Bureaucrat & operator = (const Bureaucrat &bureaucrat);

	std::string	getName         ( void ) const;
	int         getGrade        ( void ) const;
    void        increaseGrade   ( void );
	void        decreaseGrade   ( void );
        
private:
    
    class GradeTooHightException :public std::runtime_error { public: GradeTooHightException();};
    class GradeTooLowException   :public std::runtime_error { public: GradeTooLowException  ();};

	const std::string	_name;
	int                 _grade; //[1-150]
    static const int    _maxGrade = 1;
    static const int    _minGrade = 150;
};

// Overload output stream
std::ostream & operator << (std::ostream& os, Bureaucrat &bureaucrat);

#endif /* __BUREAUCRAT_H__ */

