#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5) {}
PresidentialPardonForm::~PresidentialPardonForm(void) {}
int PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (AForm::execute(executor))
    {
        std::cout << "The form must be signed\n";
        return 1;
    }
    else
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
    return 0;
}
