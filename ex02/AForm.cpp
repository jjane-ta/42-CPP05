#include "AForm.hpp"


// OCCP
AForm::AForm ( std::string name, int grade2sign, int grade2exec):
    _name(name),
    _grade2sign(grade2sign),
    _grade2exec(grade2exec),
    _is_signed(false)
{
    if (this->_grade2sign > this->_minGrade || this->_grade2exec > this->_minGrade)
        throw AForm::GradeTooLowException();
    if (this->_grade2sign < this->_maxGrade || this->_grade2exec < this->_maxGrade)
        throw AForm::GradeTooHighException();
}

AForm::~AForm ( void )
{}

AForm::AForm (const AForm &aform):
    _name(aform._name),
    _grade2sign(aform._grade2sign),
    _grade2exec(aform._grade2exec),
    _is_signed(false)
{}

AForm & AForm::operator = (AForm &aform){
    (void)aform;
    std::cout << "Is not possible make a copy of form\n";
    return(*this);
}

const std::string AForm::getName ( void ) const{
    std::string form_name = this->_name.size() ? this->_name : "TOP-SECRET";
    return (form_name);
}

int AForm::getGrade2Sign ( void ) const{
    return (this->_grade2sign);
}

int AForm::getGrade2Exec ( void ) const{
    return (this->_grade2exec);
}

bool AForm::isSigned ( void ){
    return (this->_is_signed);
}

void AForm::beSigned ( const Bureaucrat & bureaucrat){
    if (bureaucrat.getGrade() > this->getGrade2Sign()){
        throw AForm::GradeTooLowException();
    } else {
        this->_is_signed = true;
    }
}

// Exceptions
AForm::GradeTooHighException::GradeTooHighException() :
    std::runtime_error("\033[1;31mstd::exception => AForm::GradeTooHighException\033[0m\n"){}

AForm::GradeTooLowException::GradeTooLowException() : 
    std::runtime_error("\033[1;31mstd::exception => AForm::GradeTooLowException\033[0m\n"){}

// Overload stream output
std::ostream &operator<<(std::ostream &os, AForm &aform)
{
    const std::string color("\033[1;34m");
    const std::string reset_color("\033[0m");
    std::string form_name = aform.getName().size() ? aform.getName() : "TOP-SECRET";
    std::string form_status = aform.isSigned() ? "✅" : "❌";

    os << color << "fom " << std::left << std::setfill(' ') <<  std::setw(11) << form_name  + ",";
    os << " grade{to_sign: "<< reset_color;
    os << std::right << std::setfill(' ') <<  std::setw(3) << aform.getGrade2Sign();
    os << color << ", to_exec: " << reset_color;
    os << std::right << std::setfill(' ') <<  std::setw(3) << aform.getGrade2Exec();
    os << color << "} is signed " << form_status <<"\n" << reset_color;
    return os;  
}