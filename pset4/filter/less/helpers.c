///The #include directive tells the C preprocessor to include the contents of the file specified in the input stream to the compiler and then continue with the rest of the original file. ... A header file may contain any valid C program fragment.
#include <math.h>
#include "helpers.h"

///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
int cap255(int color);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    ///Updated January 07, 2019. Int, short for "integer," is a fundamental variable type built into the compiler and used to define numeric variables holding whole numbers. Other data types include float and double. C, C++, C# and many other programming languages recognize int as a data type
    int originalRed, originalGreen, originalBlue;
    ///Float is a shortened term for "floating point." By definition, it's a fundamental data type built into the compiler that's used to define numeric values with floating decimal points. C, C++, C# and many other programming languages recognize float as a data type. Other common data types include int and double
    float averageColors;
    ///Advertisements. A for loop is a repetition control structure that allows you to efficiently write a loop that needs to execute a specific number of times
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            ///The round( ) function in the C programming language provides the integer value that is nearest to the float, the double or long double type argument passed to it. If the decimal number is between “1 and. 5′′, it gives an integer number less than the argument.
            averageColors = round((originalRed +
                                   originalGreen +
                                   originalBlue) /
                                  3.0);

            image[i][j].rgbtRed = averageColors;
            image[i][j].rgbtGreen = averageColors;
            image[i][j].rgbtBlue = averageColors;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sephiaRed, sephiaGreen, sephiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sephiaRed = round(.393 * originalRed +
                              .769 * originalGreen +
                              .189 * originalBlue);

            sephiaGreen = round(.349 * originalRed +
                                .686 * originalGreen +
                                .168 * originalBlue);

            sephiaBlue = round(.272 * originalRed +
                               .534 * originalGreen +
                               .131 * originalBlue);

            sephiaRed = cap255(sephiaRed);
            sephiaGreen = cap255(sephiaGreen);
            sephiaBlue = cap255(sephiaBlue);

            image[i][j].rgbtRed = sephiaRed;
            image[i][j].rgbtGreen = sephiaGreen;
            image[i][j].rgbtBlue = sephiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_row[j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp_row[width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = temp_row[width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = temp_row[width - 1 - j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp_image[h][w] = image[h][w];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        ///The continue statement in C programming works somewhat like the break statement. Instead of forcing termination, it forces the next iteration of the loop to take place, skipping any code in between. For the for loop, continue statement causes the conditional test and increment portions of the loop to execute.

                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    sumRed += temp_image[i + k][j + l].rgbtRed;
                    sumGreen += temp_image[i + k][j + l].rgbtGreen;
                    sumBlue += temp_image[i + k][j + l].rgbtBlue;
                    count++;
                }
            }

            image[i][j].rgbtRed = (int)round(sumRed / count);
            image[i][j].rgbtGreen = (int)round(sumGreen / count);
            image[i][j].rgbtBlue = (int)round(sumBlue / count);
        }
    }
}

int cap255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        //////The return statement terminates the execution of a function and returns control to the calling function. Execution resumes in the calling function at the point immediately following the call. ... The return statement is used when a function is ready to return a value to its caller
        return color;
    }
}
