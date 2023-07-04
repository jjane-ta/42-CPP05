#include "Bureaucrat.hpp"

// OCCP

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor called\n";
    if (this->_grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
    if (this->_grade < this->_maxGrade)
        throw Bureaucrat::GradeTooHightException();
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade)
{
    std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    std::cout << "Bureaucrat copy operator called\n";
    this->_grade = bureaucrat._grade;
    return (*this);
}

std::string Bureaucrat::getName(void) const
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
        throw Bureaucrat::GradeTooHightException();
}

void Bureaucrat::decreaseGrade(void)
{
    std::cout << "Bureaucrat decreaseGrade called\n";

    this->_grade++;
    if (this->_grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
}

// Exceptions
Bureaucrat::GradeTooHightException::GradeTooHightException() :
    std::runtime_error("\033[1;31mstd::exception => Bureaucrat::GradeTooHightException\033[0m\n"){}

Bureaucrat::GradeTooLowException::GradeTooLowException() : 
    std::runtime_error("\033[1;31mstd::exception => Bureaucrat::GradeTooLowException\033[0m\n"){}

// Overload stream output
std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat)
{
    if (bureaucrat.getName().size())
        return (os << "\033[1;35m" << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\033[0m.\n");
    return (os << "\033[1;35m" << "Incognito" << ", bureaucrat grade " << bureaucrat.getGrade() << "\033[0m.\n");
}