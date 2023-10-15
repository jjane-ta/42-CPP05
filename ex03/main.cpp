#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "Intern.hpp"
// #include "AForm.hpp"

void main_print_banner(std::string title);

void test1()
{
    main_print_banner("TEST 1 subject: make robotomy");
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
}

void test2()
{
    main_print_banner("TEST 2 subject: make pardon");
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
}

void test3()
{
    main_print_banner("TEST 3 subject: make shrubbery");
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
}

void test4()
{
    main_print_banner("TEST 4 subject: make shrubbery");
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("icecream creation", "Bender");
        if (rrf)
        {
            std::cout << *rrf;
            delete rrf;
        }
    }
}

int main(void)
{
    void (*functions[])() = {
        test1,
        test2,
        test3,
        test4,

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