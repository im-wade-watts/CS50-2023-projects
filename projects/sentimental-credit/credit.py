def main():
    number = get_positive_number()
    if check_card(str(number)):
        if isAmex(number):
            quit
        elif isVisa(number):
            quit
        elif isMasterCard(number):
            quit

    print("INVALID")


def get_positive_number():
    while True:
        number = int(input("Number: "))
        if number > 1:
            return number


def check_card(number):
    n = len(number)
    if n <= 10 or number[:2] == "56":
        return False
    i = n - 1
    plainSum = 0
    productSum = 0

    while i > 0:
        firstDigit = int(number[i])
        secondDigit = int(number[i - 1])

        p = secondDigit * 2
        plainSum += firstDigit
        productSum += int(p % 10) + int(p / 10 % 10)

        i -= 2

    if n % 2:
        plainSum += int(number[0])

    if (productSum + plainSum) % 10 == 0:
        return True

    return False


def isAmex(card_number):
    if len(str(card_number)) == 15:
        if str(card_number)[:2] == "34" or str(card_number)[:2] == "37":
            print("AMEX")
            return True
    return False


def isVisa(card_number):
    if len(str(card_number)) == 13 or len(str(card_number)) == 16:
        if str(card_number)[0] == "4":
            print("VISA")
            return True
    return False


def isMasterCard(card_number):
    if len(str(card_number)) == 16:
        if (
            str(card_number)[:2] == "51"
            or str(card_number)[:2] == "52"
            or str(card_number)[:2] == "53"
            or str(card_number)[:2] == "54"
            or str(card_number)[:2] == "55"
        ):
            print("MASTERCARD")
            return True
    return False


main()
