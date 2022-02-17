# In Python, defining the function works as follows. def is the keyword for defining a function. The function name is followed by parameter(s) in (). The colon : signals the start of the function body, which is marked by indentation. Inside the function body, the return statement determines the value to be returned.

def main():
    owed = get_owed()
    coins = calc_coins(owed)
    print(f"{coins}")


def get_owed():
    # The "while true" loop in python runs without any conditions until the break statement executes inside the loop. To run a statement if a python while loop fails, the programmer can implement a python "while" with else loop. Python does not support the "do while" loop
    while True:
        # The Python try… except statement catches an exception. It is used to test code for an error which is written in the “try” statement. If an error is encountered, the contents of the “except” block are run
        try:
            owed = float(input("Cash owed: "))
            if owed > 0:
                # Break' in Python is a loop control statement. ... If you are using it in nested loops, it will terminate the innermost loop where you have used it, and the control of the program will flow to the outer loop. In other words, it breaks the sequence of the loop, and the control goes to the first statement outside the loop
                break
        # except statement catches an exception. It is used to test code for an error which is written in the “try” statement. If an error is encountered, the contents of the “except” block are run.
        except ValueError:
            # None is used to define a null value. It is not the same as an empty string, False, or a zero. It is a data type of the class NoneType object. Assigning a value of None to a variable is one way to reset it to its original, empty state.
            None

    return owed


def calc_coins(owed):
    cents = round(owed * 100)
    coins = 0

    while cents > 0:
        if cents >= 25:
            cents -= 25
        elif cents >= 10:
            cents -= 10
        elif cents >= 5:
            cents -= 5
        else:
            cents -= 1
        coins += 1
    return coins


main()