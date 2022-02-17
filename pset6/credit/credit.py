# Run a program to determine if the credit card number provided is valid according to the Luhn algorithm.
def main():
    card_number = get_card()
    checksum = calc_checksun(card_number)
    check_card_type(card_number, checksum)


def get_card():
    # The "while true" loop in python runs without any conditions until the break statement executes inside the loop. To run a statement if a python while loop fails, the programmer can implement a python "while" with else loop. Python does not support the "do while" loop
    while True:
        card_number = input("Number: ")
        # Python isnumeric() method checks whether all the characters of the string are numeric characters or not. It returns True if all the characters are true, otherwise returns False.
        if card_number.isnumeric():
            # 'Break' in Python is a loop control statement. ... If you are using it in nested loops, it will terminate the innermost loop where you have used it, and the control of the program will flow to the outer loop. In other words, it breaks the sequence of the loop, and the control goes to the first statement outside the loop
            break
    # The return keyword in Python exits a function and tells Python to run the rest of the main program. A return keyword can send a value back to the main program. While values may have been defined in a function, you can send them back to your main program and read them throughout your code
    return card_number


def calc_checksun(card_number):
    even_sum = 0
    odd_sum = 0
    # The reversed() method returns the reversed iterator of the given sequence. It is the same as the iter() method but in reverse order. ... If the given object is not a sequence, then override __reversed__() method in the class to be used with the reversed() function.
    card_number = reversed([int(digit) for digit in card_number])
    # The Python enumerate() function adds a counter to an iterable object. ... The built-in enumerate() function allows you to loop over a list of items while keeping track of the index value in a separate variable.
    for i, digit in enumerate(card_number):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                odd_sum += int(odd_digit / 10) + odd_digit % 10
            else:
                odd_sum += odd_digit
        else:
            even_sum += digit
    checksum = even_sum + odd_sum
    return checksum


def check_card_type(card_number, checksum):
    start_number = int(card_number[0:2])
    # The len() Python method returns the length of a list, string, dictionary, or any other iterable data format in Python. ... The Python len() method is a built-in function that can be used to calculate the length of any iterable object.
    card_lenght = len(card_number)
    checksum_last_digit = checksum % 10

    if checksum_last_digit == 0:
        # There are three Boolean operators in Python: and , or , and not . With them, you can test conditions and decide which execution path your programs will take. In this tutorial, you'll learn about the Python or operator and how to use it.
        if start_number in [34, 37] and card_lenght == 15:
            print("AMEX")
        elif (int(card_number[0]) == 4) and card_lenght in [13, 16]:
            print("VISA")
        elif (start_number in range(51, 56)) and card_lenght == 16:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
