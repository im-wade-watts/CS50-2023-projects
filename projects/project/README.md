# The tic tac toe ai
## Features
* Python Modules:
    * math
    * OS
    * random

I have used math used in the algorithm, OS to clear the terminal every time the board was updated, and random to choose the player's symbol randomly. The three modules are basic and should be pre-installed with Python.

## Explaining the project:
It is a Python program that plays tic-tac-toe with a minimax algorithm. The way Minimax work is by looking at every possible move and its respective final board state. Deciding at the end, with a static evaluation, what is the smartest move to make.

A static evaluation just means how good are the different positions at the end of the branches for the AI. This would return a positive value if the ai won, 0 if it ends up in a draw or negative if the other player won.

This program could be upgraded by a method called pruning that makes the selection quicker, but I did not have time to make.

### app.py
#### Functionality
To run the program you need to just run the app.py and the board is going to pop up itself.

If you are in Windows maybe you need to change the lines where os.system('clear') is put to os.system('cls') and the problem should be resolved.

#### Class TicTacToe
In this class you can find the different essential things to be able to play a game in tic tac toe such as, the creation of the board, the different conditions to see if the game is over, the randomizer of the symbols, the function to show the board in the terminal or the most important one, the start function discussed later one.

#### Class humanPlayer
In this class the main function prompts the user for a square and first it makes sure it is a number by the try except block then it looks if the number is between 1 and 9 and then looks if the squared given it is already filled by another one.

#### Class artificial_intelligence
The artificial intelligence class is a child of TicTacToe.In this class despite all the functions to see the possible moves and to make copies of the states of the board. The important function is the minimax. This recursive function, iterates till the game is over and then makes an static evaluation to know which move to make.

#### Function start in class TicTacToe
The function start is the one that is in charge of making all the other function run when it is time and to quit the program when it is finished.

### Demostration on youtube:
For the CS50 final project you have to make a video showing your project, [my youtube video](https://youtu.be/nVq5m4T9Pws).

### About CS50x
CS50 is a free course from Harvard Univeristy and taught by David J. Malan.

It's an introduction to Computer Science and teaches languages such as: C, HTML, CSS, JavaScript, Python, SQL, Flask.

Link to CS50x:  https://cs50.harvard.edu/x/2023/

It was an incredible journey, thank for all!
