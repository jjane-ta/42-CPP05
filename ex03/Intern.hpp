#pragma once
#include <iostream>
// #include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
    virtual ~Intern(void);
    Intern(void);
    AForm *makeForm(std::string name, std::string target);

protected:
private:
    Intern(const Intern &instance);
    Intern operator=(const Intern &instance);
};
