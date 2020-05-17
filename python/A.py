import sys


class ExtendedList(list):

    @property
    def reversed(self):
        return self[::-1]
    R = reversed

    @property
    def first(self):
        return self[0]

    @first.setter
    def first(self, value):
        self[0] = value
    F = first

    @property
    def last(self):
        return self[-1]

    @last.setter
    def last(self, value):
        self[-1] = value
    L = last

    @property
    def size(self):
        return len(self)

    @size.setter
    def size(self, value):
        if value > self.size:
            for i in range(value - self.size):
                self.append(None)
        else:
            for i in range(self.size - value):
                self.pop()
    S = size

exec(sys.stdin.read())
