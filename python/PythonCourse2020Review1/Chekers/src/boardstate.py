import numpy as np
from typing import Optional, List


class EndGame(Exception):
    pass


class BoardState:
    def __init__(self, board: np.ndarray, current_player: int = 1):
        self.board: np.ndarray = board
        self.current_player: int = current_player

    def inverted(self) -> 'BoardState':
        return BoardState(board=self.board[::-1, ::-1] * -1, current_player=self.current_player * -1)

    def copy(self) -> 'BoardState':
        return BoardState(self.board.copy(), self.current_player)

    def do_move(self, from_x, from_y, to_x, to_y) -> Optional['BoardState']:
        """
        :return: new BoardState or None for invalid move
        """
        # если бить нужно несколько шашек то бьется только одна
        if ((to_x + to_y) % 2 != 1 or abs(from_x - to_x) != abs(from_y - to_y) or
                self.current_player * self.board[from_y, from_x] <= 0):
            return None
        # todo more validation here
        must_byte, all_possible_moves = self._must_byte()
        print(f'from_y = {from_y}, from_x = {from_x}, must_byte = {must_byte}')
        print('\n\n')
        if must_byte and (to_y, to_x) not in all_possible_moves[(from_y, from_x)]:
            return None  # invalid move
        # todo

        result = self.copy()
        if must_byte:
            if abs(result.current_player) == 1:
                result.board[(from_y + to_y) // 2, (from_x + to_x) // 2] = 0
            elif abs(result.current_player) == 2:
                # todo
                pass
        elif (to_y, to_x) not in result.get_possible_moves(from_y, from_x):
            return None
        result.board[to_y, to_x] = result.board[from_y, from_x]
        result.board[from_y, from_x] = 0
        result.current_player *= (-1)

        if result.is_game_finished:
            winner = result.get_winner
            if winner == 1:
                print(f'white player won!!!')
            elif winner == -1:
                print(f'black player won!!!')
            else:
                print('No one won!!!')

            raise EndGame()

        return result

    def _must_byte(self):
        """
        :param y: y-я координата начала
        :param x: х-я координата начала
        :return: (булевское значение обязяан ли бить current player,
                массив обязательных ходов = в которых шашки есть другую)
        """
        all_possible_moves = {}
        for y in range(8):
            for x in range(8):
                # print(f'y = {y}, x = {x}, self.board[y, x] = {self.board[y, x]}, self.current_player = {self.current_player}')
                if self.board[y, x] * self.current_player > 0:
                    if abs(self.board[y, x]) == 1:
                        all_possible_moves[(y, x)] = []
                        for dx, dy in [(-1, -1), (1, 1), (1, -1), (-1, 1)]:  # нужно бить?
                            # print(f'y = {y}, x = {x}')
                            if (0 <= x + 2 * dx < 8 and 0 <= y + 2 * dy < 8 and
                                    self.board[y + dy, x + dx] * self.current_player < 0 and
                                    self.board[y + 2 * dy, x + 2 * dx] == 0):
                                print('---------------------------------------------------')
                                all_possible_moves[(y, x)].append((y + 2 * dy, x + 2 * dx))
                    elif abs(self.board[y, x]) == 2:
                        pass # todo

        print(all_possible_moves)
        return any(bool(all_possible_moves[key]) for key in all_possible_moves), all_possible_moves

    def get_possible_moves(self, y, x) -> List['BoardState']:
        """
        :param y:
        :param x:
        :return: ( должен бить?, массив возможных ходов из (у, х) )
        """
        current_possible_moves = []
        if self.board[y, x] * self.current_player > 0:
            if abs(self.board[y, x]) == 1:
                # must_byte, current_possible_moves = self._must_byte(y, x)
                # if not must_byte:  # если не нужно бить:
                for dx, dy in ([(-1, -1), (1, -1)] if self.current_player == 1 else [(1, 1), (-1, 1)]):
                    if (0 <= x + dx < 8 and 0 <= y + dy < 8 and
                        self.board[y + dy, x + dx] == 0):
                        current_possible_moves.append((y + dy, x + dx))
            elif abs(self.board[y, x]) == 2:
                # todo
                pass


        return current_possible_moves

    @property
    def is_game_finished(self) -> bool:
        must_byte, all_possible_moves = self._must_byte()
        if must_byte:
            return False
        for y in range(8):
            for x in range(8):
                if self.current_player * self.board[y, x] > 0:
                    possible_moves = self.get_possible_moves(y, x)
                    # print(f'player =', 'white' if self.current_player == 1 else 'black')
                    # print(f'kek, y = {y}, x = {x}')
                    if len(possible_moves) > 0:
                        return False
        return True

    @property
    def get_winner(self) -> Optional[int]:
        new_board_state = self.copy()
        new_board_state.current_player *= (-1)
        if new_board_state.is_game_finished:
            return None  # ничья
        else:
            return new_board_state.current_player



    @staticmethod
    def initial_state() -> 'BoardState':
        board = np.zeros(shape=(8, 8), dtype=np.int8)

        # board[7, 0] = -1  # шашка первого игрока
        # board[2, 1] = 1  # дамка первого игрока
        # board[0, 1] = -1  # шашка противника

        for y in range(0, 3):
            for x in range(8):
                if (x + y) % 2 == 1:
                    board[y, x] = -1
        for y in range(5, 8):
            for x in range(8):
                if (x + y) % 2 == 1:
                    board[y, x] = 1

        return BoardState(board, 1)
