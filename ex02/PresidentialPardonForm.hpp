#pragma once
#include <iostream>
#include <fstream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(std::string target);
    virtual ~PresidentialPardonForm(void);
    virtual int execute(Bureaucrat const &executor) const;

protected:
private:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm &instance);
    PresidentialPardonForm operator=(const PresidentialPardonForm &instance);
};
