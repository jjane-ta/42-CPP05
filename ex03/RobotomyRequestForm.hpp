#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(std::string target);
    virtual ~RobotomyRequestForm(void);
    virtual int execute(Bureaucrat const &executor) const;

protected:
private:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm &instance);
    RobotomyRequestForm operator=(const RobotomyRequestForm &instance);

    const std::string _target;
};
