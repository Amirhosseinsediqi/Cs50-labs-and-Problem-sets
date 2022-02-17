///An int variable contains only whole numbers
//Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type.
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int readability_index(int letters, int words, int sentences);
///int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program. 0 is the standard for the “successful execution of the program”

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = readability_index(letters, words, sentences);
    ///The if keyword in the C programming language is used to make decisions in your code based upon simple comparisons. It's the same concept humans use in making decisions based on the question “what if?” The evaluation is a comparison, a mathematical operation, the result of a function or some other condition.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}


int count_letters(string text)
{
    int letters = 0;
    ///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
    for (int i = 0, n = strlen(text); i < n; i++)
        if (isalpha(text[i]))
        {
            letters ++;
        }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    ///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        ///The if keyword in the C programming language is used to make decisions in your code based upon simple comparisons. It's the same concept humans use in making decisions based on the question “what if?” The evaluation is a comparison, a mathematical operation, the result of a function or some other condition.
        if (text[i] == '-' && isalpha(text[i - 1])) {}

        else if (text[i] == 39 && isalpha(text[i - 1])) {}

        else if (!isalpha(text[i]) && isalpha(text[i - 1]))
        {
            words ++;
        }

    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    ///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int character = text[i];
        ///The if keyword in the C programming language is used to make decisions in your code based upon simple comparisons. It's the same concept humans use in making decisions based on the question “what if?” The evaluation is a comparison, a mathematical operation, the result of a function or some other condition.
        if (character == 46 || character == 33 || character == 63)
        {
            sentences ++;
        }
    }
    ///The return type of method is int , so the method can not return null
    return sentences;
}

int readability_index(int letters, int words, int sentences)
{
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    ///The return type of method is int , so the method can not return null
    return index;
}