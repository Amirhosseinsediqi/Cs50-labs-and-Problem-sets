# Import in python is similar to #include header_file in C/C++. Python modules can get access to code from another module by importing the file/function using import. The import statement is the most common way of invoking the import machinery, but it is not the only way. import module_name
import string
import re
from cs50 import get_string


def main():

    text = get_string("Text: ")

    # Description. Python list method len() returns the number of elements in the list.
    # findall() module is used to search for “all” occurrences that match a given pattern. In contrast, search() module will only return the first occurrence that matches the specified pattern. findall() will iterate over all the lines of the file and will return all non-overlapping matches of pattern in a single step
    letters = len(re.findall('[a-zA-Z]', text))
    # The Python split() method divides a string into a list. Values in the resultant list are separated based on a separator character. The separator is a whitespace by default. ... The split() method allows you to break up a string into a list of substrings, based on the separator you specify.
    words = len(text.split())
    sentences = len(re.findall(r'[.!?]+', text))

    index = readability_index(letters, words, sentences)

    print_grade(index)


def readability_index(letters, words, sentences):

    words_per_100 = words / 100
    l = letters / words_per_100
    s = sentences / words_per_100

    # Definition and Usage. The round() function returns a floating point number that is a rounded version of the specified number, with the specified number of decimals. The default number of decimals is 0, meaning that the function will return the nearest integer
    index = round(0.0588 * l - 0.296 * s - 15.8)

    # The return keyword in Python exits a function and tells Python to run the rest of the main program. A return keyword can send a value back to the main program. While values may have been defined in a function, you can send them back to your main program and read them throughout your code
    return index


def print_grade(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


main()

