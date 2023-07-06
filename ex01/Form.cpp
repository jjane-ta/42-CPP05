#include "Form.hpp"


// OCCP
Form::Form ( std::string name, int grade2sign, int grade2exec):
    _name(name),
    _grade2sign(grade2sign),
    _grade2exec(grade2exec),
    _is_signed(false)
{
    if (this->_grade2sign > this->_minGrade || this->_grade2exec > this->_minGrade)
        throw Form::GradeTooLowException();
    if (this->_grade2sign < this->_maxGrade || this->_grade2exec < this->_maxGrade)
        throw Form::GradeTooHighException();
}

Form::~Form ( void )
{}

Form::Form (const Form &form):
    _name(form._name),
    _grade2sign(form._grade2sign),
    _grade2exec(form._grade2exec),
    _is_signed(false)
{}

Form & Form::operator = (Form &form){
    (void)form;
    std::cout << "Is not possible make a copy of form without authorization\n";
    return(*this);
}

const std::string Form::getName ( void ) const{
    std::string form_name = this->_name.size() ? this->_name : "TOP-SECRET";
    return (form_name);
}

int Form::getGrade2Sign ( void ) const{
    return (this->_grade2sign);
}

int Form::getGrade2Exec ( void ) const{
    return (this->_grade2exec);
}

bool Form::isSigned ( void ){
    return (this->_is_signed);
}

void Form::beSigned ( const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > this->_grade2sign){
        throw Form::GradeTooLowException();
    } else {
        this->_is_signed = true;
    }
}

// Exceptions
Form::GradeTooHighException::GradeTooHighException() :
    std::runtime_error("\033[1;31mstd::exception => Form::GradeTooHighException\033[0m\n"){}

Form::GradeTooLowException::GradeTooLowException() : 
    std::runtime_error("\033[1;31mstd::exception => Form::GradeTooLowException\033[0m\n"){}

// Overload stream output
std::ostream &operator<<(std::ostream &os, Form &form)
{
    const std::string color("\033[1;34m");
    const std::string reset_color("\033[0m");
    std::string form_name = form.getName().size() ? form.getName() : "TOP-SECRET";
    std::string form_status = form.isSigned() ? "✅" : "❌";

    os << color << "fom " << std::left << std::setfill(' ') <<  std::setw(11) << form_name  + ",";
    os << " grade{to_sign: "<< reset_color;
    os << std::right << std::setfill(' ') <<  std::setw(3) << form.getGrade2Sign();
    os << color << ", to_exec: " << reset_color;
    os << std::right << std::setfill(' ') <<  std::setw(3) << form.getGrade2Exec();
    os << color << "} is signed " << form_status <<"\n" << reset_color;
    return os;  
}