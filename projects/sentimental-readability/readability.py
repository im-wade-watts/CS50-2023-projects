count_letters = 0
count_words = 1
count_sentences = 0

message = input("Text: ")

for letter in message:
    if letter.isalpha():
        count_letters += 1

    elif letter.isspace():
        count_words += 1

    elif letter == "." or letter == "!" or letter == "?":
        count_sentences += 1

L = float(count_letters) / count_words * 100.0
S = float(count_sentences) / count_words * 100.0

index = round(0.0588 * L - 0.296 * S - 15.8)

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade", index)
