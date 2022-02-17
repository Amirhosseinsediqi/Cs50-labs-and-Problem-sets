# Write a program that prints a binary pyramid of a certain height.
# In Python, defining the function works as follows. def is the keyword for defining a function. The function name is followed by parameter(s) in (). The colon : signals the start of the function body, which is marked by indentation. Inside the function body, the return statement determines the value to be returned
def main():

    height = get_height()
    draw(height, height)


def draw(height, h):
    if height == 0:
        # The return keyword in Python exits a function and tells Python to run the rest of the main program. A return keyword can send a value back to the main program. While values may have been defined in a function, you can send them back to your main program and read them throughout your code.
        return
    draw(height - 1, h)
    print(" " * (h - height), end='')
    print("#" * height, end='')
    print("  ", end='')
    print("#" * height)


def get_height():
    # The "while true" loop in python runs without any conditions until the break statement executes inside the loop. To run a statement if a python while loop fails, the programmer can implement a python "while" with else loop. Python does not support the "do while" loop
    while True:
        #  The Python try… except statement catches an exception. It is used to test code for an error which is written in the “try” statement. If an error is encountered, the contents of the “except” block are run.
        try:
            height = int(input("Height: "))
            if (height > 0 and height < 9):
                break
        # except statement catches an exception. It is used to test code for an error which is written in the “try” statement. If an error is encountered, the contents of the “except” block are run
        except ValueError:
            None

    return height


main()