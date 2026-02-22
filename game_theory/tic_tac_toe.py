import re
from copy import deepcopy


current_player = 'x'

arr = [['x','o','x'],['o','o','x'],['_','_','_']]

def print_board(arr: [[str]]):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == '_':
                p = i*3 + j + 1
                print(p, end="")  
            else:            
                print(arr[i][j], end="")
        print()

def print_board_no_nums(arr: [[str]]):
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            print(arr[i][j], end="")
        print()
    print()

def print_array_boards(arr: [[[str]]]):
    for i in range(len(arr)):
        print_board_no_nums(arr[i])
    print()


def make_move(arr: [[str]], player: str):
    while True:
        move = input(f"Ход {player} (1-9): ")

        match = re.match(r"^( |\t)*[0-9]( |\t)*$", move)
        if not match:
            print("Введи число от 1 до 9")
            continue

        move_num = int(move) - 1 
        
        i = move_num // 3
        j = move_num % 3
        
        if arr[i][j] != '_':
            print("Клетка занята")
            continue
            
        arr[i][j] = player
        print_board(arr)
        return True


def free_slot(arr: [[str]]) -> bool:
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == '_':
                return True
    return False


def winner(arr: [[str]]):
    for i in range(len(arr)):
        if arr[i][0] == arr[i][1] == arr[i][2] != '_':
            return arr[i][0]
        
    for i in range(len(arr[0])):
        if arr[0][i] == arr[1][i] == arr[2][i] != '_':
            return arr[0][i]
    
    if arr[0][0] == arr[1][1] == arr[2][2] != '_':
        return arr[0][0]
    
    if arr[0][2] == arr[1][1] == arr[2][0] != '_':
        return arr[0][2]
    
    return '_'


def switch_current_player(player):
    return 'o' if player == 'x' else 'x'


def all_turns(arr: [[str]], current_player: str) -> [[[str]]]:
    open_turns_arr = []
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == '_':
                arr[i][j] = current_player 
                open_turns_arr.append(deepcopy(arr))
                arr[i][j] = '_'
    return open_turns_arr


def turn_counter(arr: [[str]], current_player: str) -> int:
    if winner(arr) != '_':
        return 1

    if not free_slot(arr):
        return 1
    
    turns = all_turns(arr, current_player)
    turn_sum = 0

    print_array_boards(turns)

    for i in range(len(turns)):
        turn_sum += turn_counter(turns[i], switch_current_player(current_player))
    
    return turn_sum +1


print(turn_counter(arr, current_player))


# o - comp
# x - human

def minimax(arr: [[int]], current_player: str) -> ([[str]], int):
    player_win = winner(arr)

    if player_win == 'o':
        return (arr, 1)
    elif player_win == 'x':
        return (arr, -1)
    
    if not free_slot and player_win == '_':
        return (arr, 0)

    boards_list = all_turns(arr, current_player)

    turn_grades = [minimax(board, current_player) for board in boards_list]

    if current_player == 'x':
        return min(turn_grades, key=lambda x:x[1])
    else:
        return max(turn_grades, key=lambda x:x[1])

    
# сделать так чтобы комп ходил через minimax, и доску подменять на ту что он вернул
    

    

# -1 - если человек
# 0 - если ничья
# +1 - если компьютер


# сделать так чтобы можно было играть с собой

# ввожу ход за х и за о, и так до конца

# пронумеровать доску с 1 до 9

# пользователю выводить подсказки
# вместо нижнего подчеркивания выводить цифры, чтобы пользователь понимал куда нажимать(вводить число)



# потренироваться в регулярных выражениях


# 1. найти код deepcopy, разобраться как она работает

# 2. возможно функция написана на C, написать аналог на python

# 3. Если нет нигде, то попросить написать эту функцию AI и разобрать ее.


# Почитать про то как работает minimax - алгоритм поиска для наилучшего хода в играх типа шахмат и крестики нолики




# 1. Проверить нет ли ошибок в других функция при выполнение turn_counter - отладочная печать
# 2. Как можно рекурсией узнать максимальный элемент массива 
# 3. В рекурсии сосредотавичваемся на переходе от части к целому
