///The #include directive tells the C preprocessor to include the contents of the file specified in the input stream to the compiler and then continue with the rest of the original file. ... A header file may contain any valid C program fragment.
#include <stdio.h>
#include <stdlib.h>

//////int main – 'int main' means that our function needs to return some integer at the end of the execution and we do so by returning 0 at the end of the program. 0 is the standard for the “successful execution of the program”
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    FILE *card = fopen(argv[1], "r");
    unsigned char *buffer = malloc(512);
    if (buffer == NULL)
    {
        return 1;
    }
    char *filename = malloc(3 * sizeof(int));
    int photoCount = 0;

    while (fread(buffer, sizeof(unsigned char), 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (photoCount == 1)
            {
                sprintf(filename, "%03i.jpg", photoCount);
                FILE *imageFile = fopen(filename, "w");
                fwrite(buffer, 1, 512, imageFile);
                fclose(imageFile);
            }
            else
            {
                ///. X, where x is a number means "print at least X" digits, so %. 3i means print at least 3 digits. If the number is less than 100, it is left padded with zeros. From a doc on printf.20 Feb 2009
                ///sprintf stands for "string print". In C programming language, it is a file handling function that is used to send formatted output to the string. Instead of printing on console, sprintf() function stores the output on char buffer that is specified in sprintf.
                sprintf(filename, "%03i.jpg", photoCount);
                ///The fopen() function opens the file whose pathname is the string pointed to by filename, and associates a stream with it. The argument mode points to a string beginning with one of the following sequences: r or rb. Open file for reading. ... Append; open or create file for writing at end-of-file.
                FILE *imageFile = fopen(filename, "w");
                fwrite(buffer, 1, 512, imageFile);
                fclose(imageFile);
            }
            photoCount++;
        }
        ///The if-else statement in C is used to perform the operations based on some specific condition. The operations specified in if block are executed if and only if the given condition is true.
        else if (photoCount != 0)
        {
            FILE *imageFile = fopen(filename, "a");
            ///The C library function size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) writes data from the array pointed to, by ptr to the given stream.
            fwrite(buffer, 1, 512, imageFile);
            ///In the C Programming Language, the fclose function closes a stream pointed to by stream. The fclose function flushes any unwritten data in the stream's buffer
            fclose(imageFile);
        }

    }
    ///The free() function in C library allows you to release or deallocate the memory blocks which are previously allocated by calloc(), malloc() or realloc() functions. It frees up the memory blocks and returns the memory to heap
    free(buffer);
    printf("contagem = %i\n", photoCount);
}
