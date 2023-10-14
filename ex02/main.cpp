#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <filesystem>

void main_print_banner(std::string title);

void test1()
{
    main_print_banner("TEST 1 signed no exec Shrubbery");
    {
        ShrubberyCreationForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);
        Bureaucrat b("LowBureaucrat_ToExec", 150);

        a.signForm(sr);
        b.executeForm(sr);
    }
}

void test2()
{
    main_print_banner("TEST 2 signed and exec Shrubbery");
    {
        ShrubberyCreationForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

void test3()
{
    main_print_banner("TEST 3 PresidentialPardonForm");
    {
        PresidentialPardonForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

void test4()
{
    main_print_banner("TEST 4 signed and exec Shrubbery");
    {
        RobotomyRequestForm sr("test");
        Bureaucrat a("HightBureaucrat_ToSign", 1);

        a.signForm(sr);
        a.executeForm(sr);
    }
}

int main(void)
{
    void (*functions[])() = {
        test1,
        test2,
        test3,
        test4,
        // test5,
        // test6,
        // test7,
        // test8,
        // test9,
        // test10
    };

    for (int test_num = 0; test_num < (int)(sizeof(functions) / sizeof(void *)); test_num++)
    {
        try
        {
            functions[test_num]();
        }
        catch (std::exception &e)
        {
            std::cout << e.what();
        }
        main_print_banner("END TEST");
    }
}

void main_print_banner(std::string title)
{
    std::cout << std::endl;
    std::cout << std::setfill('*') << std::setw(title.size()) << "" << std::endl;
    std::cout << title << std::endl;
    std::cout << std::setfill('*') << std::setw(title.size()) << "" << std::endl;
    std::cout << std::endl;
}