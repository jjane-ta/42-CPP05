#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (AForm::execute(executor))
    {
        std::cout << "The form must be signed\n";
        return 1;
    }
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox\n";
    return 0;
}
