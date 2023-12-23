while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    if height > 0 and height < 9:
        break

for i in range(height):
    spaces = height - (i + 1)
    points = i + 1
    print(" " * spaces + "#" * points, end="  ")
    print("#" * points)
