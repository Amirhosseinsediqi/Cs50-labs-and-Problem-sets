///stdio. h is a header file which has the necessary information to include the input/output related functions in our program. Example printf, scanf etc. If we want to use printf or scanf function in our program, we should include the stdio. h header file in our source code.
#include <stdio.h>
#include <cs50.h>

///In computer programming, when void is used as a function return type, it indicates that the function does not return a value. When void appears in a pointer declaration, it specifies that the pointer is universal
void draw(int height, int initial_height);

///int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program. 0 is the standard for the “successful execution of the program
int main(void)
{
    int h;
    //Prompt user for height and keep doing it until a number between 1-8 is inserted
    do
    {
        h = get_int("What's is the height for the pyramid?(1-8) \n");
    }
    while (h < 1 || h > 8);

    draw(h, h);
}

void draw(int height, int initial_height)
{
    if (height == 0)
    {
        return;
    }
    draw(height - 1, initial_height);

    for (int i = 0; i < initial_height - height; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}