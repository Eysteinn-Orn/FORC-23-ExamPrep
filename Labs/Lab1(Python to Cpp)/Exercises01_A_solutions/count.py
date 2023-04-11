if __name__ == "__main__":
    limit = 1
    while limit != 0:
        limit = int(input('How high should I count? '))
        for i in range(1, limit + 1):
            print('now the number is ' + str(i))