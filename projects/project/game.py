import math
import os
import random

class TicTacToe:
    def __init__(self):
        self.board = ['-' for _ in range(9)]
        if random.randint(0, 1) == 1:
            self.humanPLayer = 'X'
            self.ai = "O"
        else:
            self.humanPLayer = "O"
            self.ai = "X"

    def show_board(self):
        print("")
        for i in range(3):
            print(self.board[0+(i*3)]," | ",self.board[1+(i*3)]," | ",self.board[2+(i*3)])
            print("")

    def is_board_filled(self,state):
        return not "-" in state

    def is_player_win(self,state,player):
        if state[0]==state[1]==state[2] == player: return True
        if state[0]==state[4]==state[8] == player: return True
        if state[0]==state[3]==state[6] == player: return True
        if state[1]==state[4]==state[7] == player: return True
        if state[2]==state[5]==state[8] == player: return True
        if state[2]==state[4]==state[6] == player: return True
        if state[3]==state[4]==state[5] == player: return True
        if state[6]==state[7]==state[8] == player: return True

        return False

    def checkWinner(self):
        if self.is_player_win(self.board,self.humanPLayer):
            os.system('clear')
            print(f"Player {self.humanPLayer} wins the game!")
            return True

        if self.is_player_win(self.board,self.ai):
            os.system('clear')
            print(f"Player {self.ai} wins the game!")
            return True

        if self.is_board_filled(self.board):
            os.system('clear')
            print("Match Draw!")
            return True
        return False

    def start(self):
        bot = artificial_intelligence(self.ai)
        human = humanPLayer(self.humanPLayer)
        while True:
            os.system('clear')
            print(f"Player {self.humanPLayer} turn")
            self.show_board()

            square = human.human_move(self.board)
            self.board[square] = self.humanPLayer
            if self.checkWinner():
                break

            square = bot.machine_move(self.board)
            self.board[square] = self.ai
            if self.checkWinner():
                break

        print()
        self.show_board()

class humanPLayer:
    def __init__(self,letter):
        self.letter = letter

    def human_move(self,state):
        while True:
            try:
                square =  int(input("Enter the square to fix spot(1-9): "))
                if square > 9:
                    continue
            except:
                continue
            print()
            if state[square-1] == "-":
                break
        return square-1

class artificial_intelligence(TicTacToe):
    def __init__(self,letter):
        self.botPlayer = letter
        self.humanPlayer = "X" if letter == "O" else "O"

    def players(self,state):
        x = 0
        o = 0
        for i in range(9):
            if(state[i] == "X"):
                x += 1
            if(state[i] == "O"):
                o += 1

        if(self.humanPlayer == "X"):
            return "X" if x==o else "O"
        if(self.humanPlayer == "O"):
            return "O" if x==o else "X"

    def possible_actions(self,state):
        return [i for i, x in enumerate(state) if x == "-"]

    def result(self,state,action):
        newState = state.copy()
        player = self.players(state)
        newState[action] = player
        return newState

    def is_over(self,state):
        if(self.is_player_win(state,"X")):
            return True
        if(self.is_player_win(state,"O")):
            return True
        return False

    def minimax(self, state, player):
        max_player = self.humanPlayer
        other_player = 'O' if player == 'X' else 'X'

        if self.is_over(state):
            return {'position': None, 'score': 1 * (len(self.possible_actions(state)) + 1) if other_player == max_player else -1 * (
                        len(self.possible_actions(state)) + 1)}
        elif self.is_board_filled(state):
            return {'position': None, 'score': 0}

        if player == max_player:
            best = {'position': None, 'score': -math.inf}
        else:
            best = {'position': None, 'score': math.inf}
        for possible_move in self.possible_actions(state):
            newState = self.result(state,possible_move)
            sim_score = self.minimax(newState, other_player)

            sim_score['position'] = possible_move

            if player == max_player:
                if sim_score['score'] > best['score']:
                    best = sim_score
            else:
                if sim_score['score'] < best['score']:
                    best = sim_score
        return best

    def machine_move(self,state):
        square = self.minimax(state,self.botPlayer)['position']
        return square

tic_tac_toe = TicTacToe()
tic_tac_toe.start()
