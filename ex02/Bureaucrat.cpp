#include "Bureaucrat.hpp"

const std::string Bureaucrat::c_bureaucrat = "\033[1;35m";
const std::string Bureaucrat::c_error = "\033[1;31m";
const std::string Bureaucrat::c_reset = "\033[0m";

// OCCP

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade)
{
    if (this->_grade > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
    if (this->_grade < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat Bureaucrat::operator=(const Bureaucrat &bureaucrat) { return Bureaucrat(bureaucrat); }

const std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::increaseGrade(void)
{
    if (this->_grade - 1 < this->_maxGrade)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decreaseGrade(void)
{
    std::cout << "Bureaucrat decreaseGrade called\n";

    if (this->_grade + 1 > this->_minGrade)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " sign " << form.getName() << ".\n";
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign form " << form.getName() << " because your grade is too low.\n";
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        std::cout << this->getName() << " execute " << form.getName() << ".\n";
        form.execute(*this);
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't exec form " << form.getName() << " because executor grade is too low.\n";
    }
}

// Exceptions
Bureaucrat::GradeTooHighException::GradeTooHighException()
    : std::runtime_error(Bureaucrat::c_error + "std::exception => Bureaucrat::GradeTooHighException\n" + Bureaucrat::c_reset) {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : std::runtime_error(Bureaucrat::c_error + "std::exception => Bureaucrat::GradeTooLowException\n" + Bureaucrat::c_reset) {}

// Overload stream output
std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
    std::string name = bureaucrat.getName();
    if (!name.size())
        name = "Incognito";
    return (os << Bureaucrat::c_bureaucrat << name << ", bureaucrat grade " << bureaucrat.getGrade() << Bureaucrat::c_reset << ".\n");
}
