if __name__ == "__main__":
    c = 's'
    while c != 'q':
        c = input('Enter a character: ')
        if c == 'a':
            print('You have entered the first letter of the alphabet.')
        elif c == 'o':
            print('\'o\' could refer to \"object\" or maybe \"output\".')
        elif c == 'c':
            print('CONTROL CHARACTER!')
        elif c != 'q':
            print('This is an unknown input: " << c << "\nTry \'a\', \'c\', \'o\' or \'q\' to quit.')