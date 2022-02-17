///An int variable contains only whole numbers
//Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type.
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int encipher(string plaintext, int key);
int test_arguments(int arguments, string key[]);

///int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program. 0 is the standard for the “successful execution of the program”
int main(int argc, string argv[])
{
    int test = test_arguments(argc, argv);
    ///The if keyword in the C programming language is used to make decisions in your code based upon simple comparisons. It's the same concept humans use in making decisions based on the question “what if?” The evaluation is a comparison, a mathematical operation, the result of a function or some other condition.
    if (test)
    {
        return test;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        int key = atoi(argv[1]);
        return encipher(plaintext, key);
    }
}

int test_arguments(int arguments, string key[])
{
    if (arguments != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    for (int i = 0, n = strlen(key[1]); i < n; i++)
    {
        if (isalpha(key[1][i]))
        {
            printf("Usage: ./caesar key.\n");
            return 1;
        }
    }
    return 0;
}

int encipher(string plaintext, int key)
{
    printf("ciphertext: ");
    ///char: The most basic data type in C. It stores a single character and requires a single byte of memory in almost all compilers. int: As the name suggests, an int variable is used to store an integer. float: It is used to store decimal numbers (numbers with floating point value) with single precision
    char ci;
    int n = strlen(plaintext);
    char ciphertext[n];
    ///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
    for (int i = 0; i < n; i++)
    {
        int c = plaintext[i];

        if (isalpha(c))
        {
            ci = c + key % 26;
            ///In C, Boolean is a data type that contains two types of values, i.e., 0 and 1. Basically, the bool type value represents two types of behavior, either true or false. Here, '0' represents false value, while '1' represents true value. In C Boolean, '0' is stored as 0, and another integer is stored as 1
            bool test_boundaries = islower(ci) || isupper(ci);
            if (!test_boundaries)
            {
                ci -= 26;
            }
        }
        else
        {
            ci = c;
        }
        ciphertext[i] = ci;
    }
    printf("%s\n", ciphertext);
    ///The return type of method is int , so the method can not return null
    return 0;
}