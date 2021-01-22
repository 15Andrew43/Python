from typing import Optional

from src.boardstate import BoardState

import random

from src.boardstate import EndGame

class Сoefficients:
    # ProtectionInitiative = 0.6 # >1 - защита, <1 - аттака
    ProtectionInitiative = 5

    number_of_bests_moves = 10

    delta_restriction = 1

    doubles = [540, 280, 150, 80]
    triples = [1000, 550, 230, 120]
    quadruples = [5000, 3000, 2000, 2000]
    fives = [500000, 500000, 500000, 500000]
    severals = [doubles, triples, quadruples, fives]


    def several_in_row(self, coord_arr, board, cnt_in_row):
        # # print(f'duoble = {double}')
        player = board.board[coord_arr[0][0], coord_arr[0][1]]
        enemy = player * (-1)
        delta_y, delta_x = coord_arr[0][0] - coord_arr[1][0], coord_arr[0][1] - coord_arr[1][1]
        y0, x0 = coord_arr[0][0] - delta_y, coord_arr[0][1] - delta_x
        y1, x1 = coord_arr[-1][0] + delta_y, coord_arr[-1][1] + delta_x
        if 0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14 and \
                board.board[y0, x0] == 0 and board.board[y1, x1] == 0:
            # # print('kek')
            return Сoefficients.severals[cnt_in_row - 2][0]
        elif (0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14) and \
                ((board.board[y0, x0] == enemy and board.board[y1, x1] == 0) or (
                        board.board[y0, x0] == 0 and board.board[y1, x1] == enemy)):
            # # print('pep')
            return Сoefficients.severals[cnt_in_row - 2][1]
        elif 0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14 and \
                board.board[y0, x0] == enemy and board.board[y1, x1] == enemy:
            # # print('lol')
            return Сoefficients.severals[cnt_in_row - 2][2]
        y0, x0 = coord_arr[0][0] + delta_y, coord_arr[0][1] + delta_x
        y1, x1 = coord_arr[-1][0] - delta_y, coord_arr[-1][1] - delta_x
        if 0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14 and \
                board.board[y0, x0] == 0 and board.board[y1, x1] == 0:
            # # print('a')
            return Сoefficients.severals[cnt_in_row - 2][0]
        elif (0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14) and \
                ((board.board[y0, x0] == enemy and board.board[y1, x1] == 0) or (
                        board.board[y0, x0] == 0 and board.board[y1, x1] == enemy)):
            # # print('b')
            return Сoefficients.severals[cnt_in_row - 2][1]
        elif 0 <= y0 <= 14 and 0 <= y1 <= 14 and 0 <= x0 <= 14 and 0 <= x1 <= 14 and \
                board.board[y0, x0] == enemy and board.board[y1, x1] == enemy:
            # # print('c')
            return Сoefficients.severals[cnt_in_row - 2][2]
        return Сoefficients.severals[cnt_in_row - 2][3]

    def duble_piece(self, double, board):
        # print(double)
        return self.several_in_row(double, board, 2)
    def triple_piece(self, triple, board):
        # print(triple)
        return self.several_in_row(triple, board, 3)
    def quadruple_piece(self, quadruple, board):
        # print(quadruple)
        return self.several_in_row(quadruple, board, 4)
    def fives_piece(self, fives, board):
        # print(fives)
        return self.several_in_row(fives, board, 5)

coefficients = Сoefficients()

def get_score(board, current_player, in_lines=False, in_coloms=False, in_diagRU_LD=False, in_diagLU_RD=False):
    score = 0
    if in_lines:
        for y in range(15):
            begin = False
            row = []
            size_row = 0
            for x in range(15):
                if board.board[y, x] == current_player and begin:
                    row.append((y, x))
                    size_row += 1
                elif board.board[y, x] == current_player:
                    begin = True
                    row.append((y, x))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    # # print(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if x == 14:
                    begin = False
                    # size_row = len(row)
                    # # print(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0

    elif in_coloms:
        for x in range(15):
            begin = False
            row = []
            size_row = 0
            for y in range(15):
                if board.board[y, x] == current_player and begin:
                    row.append((y, x))
                    size_row += 1
                elif board.board[y, x] == current_player:
                    begin = True
                    row.append((y, x))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if y == 14:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0

    elif in_diagRU_LD:
        for y in range(15):
            begin = False
            row = []
            size_row = 0
            for x in range(y + 1):
                if board.board[y-x, x] == current_player and begin:
                    row.append((y-x, x))
                    size_row += 1
                elif board.board[y-x, x] == current_player:
                    begin = True
                    row.append((y-x, x))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if x == y:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
        for x in range(1, 15):
            begin = False
            row = []
            size_row = 0
            for y in range(14, x - 1, -1):
                if board.board[y, x + 14 - y] == current_player and begin:
                    row.append((y, x + 14 - y))
                    size_row += 1
                elif board.board[y, x + 14 - y] == current_player:
                    begin = True
                    row.append((y, x + 14 - y))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if y == x:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0

    elif in_diagLU_RD:
        for x in range(14, -1, -1):
            begin = False
            row = []
            size_row  = 0
            for y in range(0, 15 - x):
                if board.board[y, y + x] == current_player and begin:
                    row.append((y, y + x))
                    size_row += 1
                elif board.board[y, y + x] == current_player:
                    begin = True
                    row.append((y, y + x))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if y == 14 - x:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
        for y in range(1, 15):
            begin = False
            row = []
            size_row = 0
            for x in range(0, 15 - y):
                if board.board[y + x, x] == current_player and begin:
                    row.append((y + x, x))
                    size_row += 1
                elif board.board[y + x, x] == current_player:
                    begin = True
                    row.append((y + x, x))
                    size_row += 1
                else:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
                if x == 14 - y:
                    begin = False
                    # size_row = len(row)
                    if size_row == 2:
                        score += coefficients.duble_piece(row, board)
                    elif size_row == 3:
                        score += coefficients.triple_piece(row, board)
                    elif size_row == 4:
                        score += coefficients.quadruple_piece(row, board)
                    elif size_row == 5:
                        score += coefficients.fives_piece(row, board)
                    row = []
                    size_row = 0
    return score

class PositionEvaluation:
    def __call__(self, board: BoardState, move, current_player) -> int:
        # # # #todo
        current_player_score = 0
        # # print('===========================================================================================')
        # print(move)
        # # print('===========================================================================================')
        current_player_score += get_score(board, current_player, in_lines=True)
        # # print(current_player_score, 'line\n----------------------------\n')
        current_player_score += get_score(board, current_player, in_coloms=True)
        # # print(current_player_score, 'colomn\n----------------------------\n')
        current_player_score += get_score(board, current_player, in_diagLU_RD=True)
        # # print(current_player_score, 'Lu-RD\n----------------------------\n')
        current_player_score += get_score(board, current_player, in_diagRU_LD=True)
        # # print(current_player_score, 'RU-LD\n----------------------------\n')

        # # print(f'bpard = {board.board[move[0], move[1]]}')
        # board.board[move[0], move[1]] = -current_player
        # # print(f'bpard = {board.board[move[0], move[1]]}')
        enemy_score = 0
        enemy_score += get_score(board, -current_player, in_lines=True)
        # # print(enemy_score, 'line\n----------------------------\n')
        enemy_score += get_score(board, -current_player, in_coloms=True)
        # print(enemy_score, 'colomn\n----------------------------\n')
        enemy_score += get_score(board, -current_player, in_diagLU_RD=True)
        # print(enemy_score, 'Lu-RD\n----------------------------\n')
        enemy_score += get_score(board, -current_player, in_diagRU_LD=True)
        # print(enemy_score, 'RU-LD\n----------------------------\n')

        # board.board[move[0], move[1]] = current_player

        formula = current_player_score - coefficients.ProtectionInitiative * enemy_score # todo ??????????

        return formula
        # return random.randint(0, 1000)


def Restriction(board):
    highY = -1
    lowY = 15
    leftX = 15
    rightX = -1
    rest_arr = []
    for y in range(15):
        for x in range(15):
            if board.board[y, x] in (1, -1):
                highY = y
                break
        if highY != -1:
            break
    for y in range(14, -1, -1):
        for x in range(15):
            if board.board[y, x] in (1, -1):
                lowY = y
                break
        if lowY != 15:
            break
    for y in range(15):
        for x in range(15):
            if board.board[y, x] in (1, -1) and x < leftX:
                leftX = x
                break
    for y in range(15):
        for x in range(14, -1, -1):
            if board.board[y, x] in (1, -1) and x > rightX:
                rightX = x
                break
    # # print(highY, leftX, lowY, rightX, "============================")
    return highY, leftX, lowY, rightX

def Restriction_first(board):
    highY, leftX, lowY, rightX = Restriction(board)
    highY += -Сoefficients.delta_restriction if highY > Сoefficients.delta_restriction else 0
    leftX += -Сoefficients.delta_restriction if leftX > Сoefficients.delta_restriction else 0
    lowY += Сoefficients.delta_restriction if lowY < 15 - Сoefficients.delta_restriction else 0
    rightX += Сoefficients.delta_restriction if rightX < 15 - Сoefficients.delta_restriction else 0

    HL = False
    LR = False
    if board.board[highY, leftX] == 0:
        HL = True
        board.board[highY, leftX] = 1
    if board.board[lowY, rightX] == 0:
        LR = True
        board.board[lowY, rightX] = 1

    highY, leftX, lowY, rightX = Restriction(board)

    if HL:
        board.board[highY, leftX] = 0
    if LR:
        board.board[lowY, rightX] = 0
    return highY, leftX, lowY, rightX


class AI:
    def __init__(self, position_evaluation: PositionEvaluation, search_depth: int):
        self.position_evaluation: PositionEvaluation = position_evaluation
        self.search_depth: int = search_depth
        self.delta_x = self.delta_y = 0
        # self.depth = 0

    def next_move(self, board: BoardState, move, current_depth=0) -> Optional[BoardState]:
        maximize = True if current_depth % 2 == 0 else False
        if maximize:
            player = board.current_player
            limit_score = -100000
        elif not maximize:
            player = board.current_player * (-1)
            limit_score = 100000

        if board == None:
            if maximize:
                return 1000000
            elif not maximize:
                return -1000000

        # new_board = board.copy()

        if current_depth == self.search_depth:
            # print(f'depth = {current_depth}')
            return self.position_evaluation(board, move, player)


        if current_depth == 0:
            highY, leftX, lowY, rightX = Restriction_first(board)
            # # print('rest_arr first = \n', rest_arr)
            # # print(f'delta_y = {delta_y}, delta_x = {delta_x}')
        else:
            highY, leftX, lowY, rightX = Restriction_first(board)
            # delta_y, delta_x, rest_arr = Restriction_first(new_board)
            # # print('rest_ arr = \n', rest_arr)
            # # print(f'delta_y = {delta_y}, delta_x = {delta_x}')




        moves = [(y, x) for y in range(highY, lowY+1) for x in range(leftX, rightX+1) if board.board[y, x] == 0]
        if len(moves) == 0:
            # if maximize:
            #     return 1000000
            # elif not maximize:
            return -1000000
        # print(current_depth)
        # print("moves", moves)

        evolution_tree = []

        for move in moves:
            try:
                # print('move', move)
                # # print(f'current depth = {current_depth}, self.depth = {self.search_depth}')
                new_board = board.do_move(move[1], move[0])
                # if type(new_board) == 'NoneType':
                #     # print(new_board)
                # if new_board == None:
                #     if maximize:
                #         return 10000
                #     elif not maximize:
                #         return -10000
                current_score = self.position_evaluation(new_board, move, player) # player = кто только что сделала ход move
                # print('move = ', move, 'score = ', current_score)
                if (maximize and current_score >= limit_score) or (not maximize and current_score <= limit_score): # todo : may be to fix coeficient
                # if (current_score >= limit_score):  # todo : may be to fix coeficient
                    limit_score = current_score
                    if current_depth == 0:
                        # # print('move = ', move, )
                        evolution_tree.append((self.next_move(new_board, move, current_depth + 1), move))
                    else:
                        # # print(f'type = {type(board.do_move(move[0], move[1]))}')
                        evolution_tree.append(self.next_move(new_board, move, current_depth + 1))
            except EndGame as EG:
                if current_depth == 0:
                    return self.position_evaluation(EG.board, move, player), move
                else:
                    return self.position_evaluation(EG.board, move, player)


        if maximize:
            # print(f'current depth = {current_depth}, evoltion = {max(evolution_tree)}')
            # print(f'max = {max(evolution_tree)}')
            board.board[move[0], move[1]] = 0
            return max(evolution_tree)
        elif not maximize:
            # print(f'current depth = {current_depth}, evoltion = {min(evolution_tree)}')
            # print(f'min = {min(evolution_tree)}')
            board.board[move[0], move[1]] = 0
            return min(evolution_tree)

if __name__ == '__main__':
    import numpy as np
    board = np.zeros(shape=(15, 15), dtype=np.int8)
    board = BoardState(board, 1)
    # todo line and colomn and LU-RD and RU-LD work ok got double!!!
    # board.board[3, 7] = 1
    # board.board[3, 13] = 1
    # board.board[2, 0] = -1
    # board.board[3, 1] = 1
    # board.board[4, 2] = 1
    # board.board[5, 3] = 1
    # board.board[6, 4] = -1
    # board.board[3, 4] = -1
    # board.board[3, 0] = -1
    # board.board[5, 5] = -1
    # board.board[3, 14]  =1
    # board.board[2, 13] = 1
    # # print(f'rand = {PositionEvaluation()(board, (3, 1) , 1)}')
    # # print('=========================================================================================================')
    # board.board[5, 5] = 1
    # board.board[6, 4] = 1
    # board.board[7, 3] = 1
    # board.board[8, 2] = -1
    # board.board[4, 4] = 1
    # board.board[5, 5] = 1
    # board.board[6, 6] = 1
    # board.board[7, 7] = 1
    # board.board[8, 8] = 1
    board.board[5, 5] = 1
    board.board[6, 6] = 1
    board.board[7, 7] = 1
    board.board[8, 8] = 1
    board.board[9, 9] = 1

    # print(f'rand = {PositionEvaluation()(board, (7, 7) , 1)}')