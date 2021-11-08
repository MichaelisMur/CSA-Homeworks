from colour import *
import math

#----------------------------------------------
class Rectangle:
    def __init__(self, n):
        self.colour = ""
        self.ax = 0
        self.ay = 0
        self.bx = 0
        self.by = 0

        self.n = n

    def ReadStrArray(self, strArray, i):
        # должно быть как минимум 5 непрочитанных значения в массиве
        if i >= len(strArray) - 4:
            return 0
        self.ax = int(strArray[i])
        self.ay = int(strArray[i+1])
        self.bx = int(strArray[i+2])
        self.by = int(strArray[i+3])
        self.colour = getColour(int(strArray[i+4]))
        i += 5
        return i

    def Write(self, ostream):
        ostream.write("Figure {}: It is a {} Rectangle: a.x = {}, a.y = {}, b.x = {}, b.y = {}".format(
            self.n, self.colour, self.ax, self.ay, self.bx, self.by))
        pass

    def WriteSorted(self, ostream):
        ostream.write("Figure {}: It is a {} Rectangle. Area: {}".format(
            self.n, self.colour, self.Area()))
        pass

    def Area(self):
        return (self.bx - self.ax) * (self.ay - self.by)
        pass
