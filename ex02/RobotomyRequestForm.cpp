#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {}
RobotomyRequestForm::~RobotomyRequestForm(void) {}
int RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    int i;
    std::string drill[] = {"", "brr ", "brrrrrrr ", "brrrrrrrbrrrr "};

    if (AForm::execute(executor))
    {
        std::cout << "The form must be signed\n";
        return 1;
    }

    srand(time(NULL));
    i = rand() % 3 + 1;
    while (i)
    {
        std::cout << drill[i];
        i = rand() % 4;
    }
    std::cout << "...\n";
    if (rand() % 2)
        std::cout << this->getName() << " has been robotomized\n";
    else
        std::cout << this->getName() << " robotomy failed\n";
    return 0;
}
