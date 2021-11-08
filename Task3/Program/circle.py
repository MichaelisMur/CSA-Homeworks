from colour import *
import math

#----------------------------------------------
class Circle:
    def __init__(self, n):
        self.colour = ""
        self.ox = 0
        self.oy = 0
        self.r = 0

        self.n = n

    def ReadStrArray(self, strArray, i):
        # должно быть как минимум 4 непрочитанных значения в массиве
        if i >= len(strArray) - 3:
            return 0
        self.r = int(strArray[i])
        self.ox = int(strArray[i+1])
        self.oy = int(strArray[i+2])
        self.colour = getColour(int(strArray[i+3]))
        i += 4
        return i

    def Write(self, ostream):
        ostream.write("Figure {}: It is a {} Circle: r = {}, O.x = {}, O.y = {}".format(
            self.n, self.colour, self.r, self.ox, self.oy))
        pass

    def WriteSorted(self, ostream):
        ostream.write("Figure {}: It is a {} Circle. Area: {}".format(
            self.n, self.colour, self.Area()))
        pass

    def Area(self):
        return math.pi * self.r * self.r
        pass
