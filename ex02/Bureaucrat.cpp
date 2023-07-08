#include "Bureaucrat.hpp"

// OCCP

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    // std::cout << "Bureaucrat constructor called\n";
    if (this->_grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
    if (this->_grade < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void)
{
    // std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade)
{
    // std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    // std::cout << "Bureaucrat copy operator called\n";
    this->_grade = bureaucrat._grade;
    return (*this);
}

const std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void Bureaucrat::increaseGrade(void)
{
    std::cout << "Bureaucrat increaseGrade called\n";

    this->_grade--;
    if (this->_grade < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade(void)
{
    std::cout << "Bureaucrat decreaseGrade called\n";

    this->_grade++;
    if (this->_grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm( Form *form ) const
{
    if (!form) {
        std::cout << this->getName() << " couldn't sign anything because form is lost.\n";
        return;
    }
    try {
        form->beSigned(*this);
        std::cout << this->getName() << " signed " << form->getName() << ".\n";
    } catch(const Form::GradeTooLowException & e) {
        std::cout << this->getName() << " couldn't sign form " << form->getName() << " because your grade is too low.\n";
    }
}

// Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException() :
    std::runtime_error("\033[1;31mstd::exception => Bureaucrat::GradeTooHighException\033[0m\n"){}

Bureaucrat::GradeTooLowException::GradeTooLowException() : 
    std::runtime_error("\033[1;31mstd::exception => Bureaucrat::GradeTooLowException\033[0m\n"){}

// Overload stream output
std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
    if (bureaucrat.getName().size())
        return (os << "\033[1;35m" << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\033[0m.\n");
    return (os << "\033[1;35m" << "Incognito" << ", bureaucrat grade " << bureaucrat.getGrade() << "\033[0m.\n");
}
