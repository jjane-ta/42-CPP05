#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
int ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (AForm::execute(executor))
    {
        std::cout << "The form must be signed\n";
        return 1;
    }

    std::ofstream myfile((this->getName() + "_shrubbery").c_str(), std::ios::trunc);
    if (myfile.is_open())
    {
        myfile << "       ###          ###           ###          ###    " << std::endl;
        myfile << "      #o###        #o###         #o###        #o###   " << std::endl;
        myfile << "    #####o###    #####o###     #####o###    #####o### " << std::endl;
        myfile << "   #o#\\#|#/###  #o#\\#|#/###   #o#\\#|#/###  #o#\\#|#/### " << std::endl;
        myfile << "    ###\\|/#o#    ###\\|/#o#     ###\\|/#o#    ###\\|/#o# " << std::endl;
        myfile << "       }|{          }|{           }|{          }|{    " << std::endl;
        myfile << "       }|{          }|{           }|{          }|{    " << std::endl;
        myfile.close();
    }
    else
        std::cout << "Unable to open file\n";

    return 0;
}
