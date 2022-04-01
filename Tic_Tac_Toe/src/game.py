from tkinter import *
import random


def create_board(parent):
    for i in range(3):
        for j in range(3):
            board[i].append(Button(parent, text='', width=10, height=5, relief=RAISED, bd=5))
            board[i][j].grid(row=i, column=j)
            board[i][j].config(command=lambda arg=board[i][j], row=i, col=j: activate(arg, row, col))


def activate(btn, r, c):
    print(f'{btn._name} was clicked row: {r} column: {c}')
    if board[r][c]['text'] == "":
        btn.config(text=player)
        next_turn()


def next_turn():
    global player

    if check_for_winner() is False:
        if player == players[0]:
            player = players[1]
            turn_label.config(text=f'{player} turn')
        else:
            player = players[0]
            turn_label.config(text=f'{player} turn')
    elif check_for_winner() is True:
        turn_label.config(text=f'Game over {player} wins')
        reset_btn.pack(side='top', pady=10)
    else:
        turn_label.config(text=f'Game over its a tie!')
        reset_btn.pack(side='top', pady=10)


def check_for_winner():
    for row in range(3):
        if board[row][0]['text'] == board[row][1]['text'] == board[row][2]['text'] != "":
            board[row][0].config(bg='#0f0')
            board[row][1].config(bg='#0f0')
            board[row][2].config(bg='#0f0')
            return True

    for col in range(3):
        if board[0][col]['text'] == board[1][col]['text'] == board[2][col]['text'] != "":
            board[0][col].config(bg='#0f0')
            board[1][col].config(bg='#0f0')
            board[2][col].config(bg='#0f0')
            return True

    if board[0][0]['text'] == board[1][1]['text'] == board[2][2]['text'] != "":
        board[0][0].config(bg='#0f0')
        board[1][1].config(bg='#0f0')
        board[2][2].config(bg='#0f0')
        return True
    elif board[0][2]['text'] == board[1][1]['text'] == board[2][0]['text'] != "":
        board[0][2].config(bg='#0f0')
        board[1][1].config(bg='#0f0')
        board[2][0].config(bg='#0f0')
        return True

    return empty_spaces()


def empty_spaces():
    for row in board:
        for col in row:
            if col['text'] == '':
                return False
    for row in range(3):
        for col in range(3):
            board[row][col].config(bg='yellow')
    return 'TIE'


def new_game():
    global player
    player = random.choice(players)

    for row in range(3):
        for col in range(3):
            board[row][col].config(text="", bg='#F0F0F0')

    turn_label.config(text=f'{player} turn')
    reset_btn.pack_forget()


window = Tk()
window.title('Tic Tac Toe')
window.resizable(False, False)
window.eval('tk::PlaceWindow . center')

players = ['X', 'O']
player = random.choice(players)
board = [[], [], []]

top_layer = Frame(window)
top_layer.pack()

turn_label = Label(top_layer, text=f"{player} turn", font=('consolas', 40))
turn_label.pack(side='left')

reset_btn = Button(window, text='Reset', font=('consolas', 20), command=new_game)

bottom_layer = Frame(window)
bottom_layer.pack(side='bottom', pady=10)

create_board(bottom_layer)

window.mainloop()
