///In alternative encryption, we "encrypt" a message (that is, we hide it in a reversible way) by replacing each letter with another. To do this, we use a key
///The #include directive tells the C preprocessor to include the contents of the file specified in the input stream to the compiler and then continue with the rest of the original file. ... A header file may contain any valid C program fragment.
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int test_arguments(int arguments, string key[]);
int encipher(string plaintext, string key);


///int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program. 0 is the standard for the “successful execution of the program”
int main(int argc, string argv[])
{
    //Call the function responsible to test the arguments
    if (test_arguments(argc, argv))
    {
        return 1;
    }
    else
    {
        //Encipher the text
        string key = argv[1];
        string text = get_string("plaintext: ");
        // encipher(text, key);
        return encipher(text, key);
    }

}


int test_arguments(int arguments, string key[])
{
    if (arguments != 2)
    {
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    else if (strlen(key[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0, n = strlen(key[1]); i < n; i++)
    {
        char i_char = key[1][i];

        ///(String Length) In the C Programming Language, the strlen function returns the length of the string pointed to by s. It does not include the null character in the length calculation
        if (!isalpha(i_char))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }
        for (int j = 0; j < n; j++)
        {
            char j_char = key[1][j];
            ///The toupper() function is used to convert lowercase alphabet to uppercase. i.e. If the character passed is a lowercase alphabet then the toupper() function converts a lowercase alphabet to an uppercase alphabet. It is defined in the ctype. h header file
            if (toupper(i_char) == toupper(j_char) && i != j)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    return 0;
}


int encipher(string text, string key)
{
    int value;
    char ci;
    int n = strlen(text);
    char ciphertext[n];

    for (int i = 0; i < n; i++)
    {
        ///char: The most basic data type in C. It stores a single character and requires a single byte of memory in almost all compilers. int: As the name suggests, an int variable is used to store an integer. float: It is used to store decimal numbers (numbers with floating point value) with single precision
        char c = text[i];
        bool alphanumeric = isalpha(text[i]);

        ///isupper() function in C programming checks whether the given character is upper case or not. isupper() function is defined in ctype
        if (alphanumeric && isupper(c))
        {
            value = c - 65;
            ci = toupper(key[value]);
        }
        else if (alphanumeric && islower(c))
        {
            value = c - 97;
            ci = tolower(key[value]);
        }
        else
        {
            ci = c;
        }
        ciphertext[i] = ci;
    }
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}