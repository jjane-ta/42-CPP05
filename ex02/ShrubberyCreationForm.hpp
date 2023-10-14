#pragma once
#include <iostream>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(std::string target);
    virtual ~ShrubberyCreationForm(void);
    virtual int execute(Bureaucrat const &executor) const;

protected:
private:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm &instance);
    ShrubberyCreationForm operator=(const ShrubberyCreationForm &instance);
};
