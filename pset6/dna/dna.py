# Write a program that identifies a person based on their DNA:
# Import in python is similar to #include header_file in C/C++. Python modules can get access to code from another module by importing the file/function using import. The import statement is the most common way of invoking the import machinery, but it is not the only way. import module_name.
import csv
import re
from sys import argv, exit


if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# n Python you need to give access to a file by opening it. You can do it by using the open() function. Open returns a file object, which has methods and attributes for getting information about and manipulating the opened file
with open(argv[1], newline="") as csvfile:
    # reader() is used to read the file, which returns an iterable reader object. The reader object is then iterated using a for loop to print the contents of each row.
    database_reader = csv.reader(csvfile, delimiter=",", quotechar="|")
    # Python enumerate() is a built-in Python function. The enumerate() function allows you to loop over an iterable object and keep track of how many iterations have occurred. Enumerate is particularly useful if you have an array of values that you want to run through entirely
    for i, row in enumerate(database_reader):
        if i == 0:
            with open(argv[2], "r") as txtfile:
                line = next(txtfile)
                longest_strs = []
                for i in range(1, len(row)):
                    pattern = row[i]
                    matches = (
                        match[0] for match in re.finditer(fr"(?:{pattern})+", line)
                    )
                    try:
                        longest = int(len(max(matches, key=len)) / len(pattern))
                        # The append() method in python adds a single item to the existing list. It doesn't return a new list of items but will modify the original list by adding the item to the end of the list. After executing the method append on the list the size of the list increases by one. Syntax. list_name.append(item)
                        longest_strs.append(longest)
                    except ValueError:
                        longest_strs.append(0)
        else:
            list_database_strs = list(map(int, row[1:]))
            if list_database_strs == longest_strs:
                print(row[0])
                # 'Break' in Python is a loop control statement. ... If you are using it in nested loops, it will terminate the innermost loop where you have used it, and the control of the program will flow to the outer loop. In other words, it breaks the sequence of the loop, and the control goes to the first statement outside the loop
                break
    else:
        print("No match")
