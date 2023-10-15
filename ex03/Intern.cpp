#include "Intern.hpp"
#include <stdlib.h>
Intern::~Intern(void) {}
Intern::Intern(void) {}
AForm *Intern::makeForm(std::string name, std::string target)
{
    AForm *ret = name == "robotomy request"      ? (AForm *)new RobotomyRequestForm(target)
                 : name == "presidential pardon" ? (AForm *)new PresidentialPardonForm(target)
                 : name == "shrubbery creation"  ? (AForm *)new ShrubberyCreationForm(target)
                                                 : NULL;
    std::cout << (ret ? "Intern creates " + ret->getName() + "\n" : "Unknown " + name + " form\n");
    return ret;
}
