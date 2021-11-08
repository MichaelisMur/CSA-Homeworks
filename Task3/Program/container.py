import rectangle
import triangle

#----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    def Write(self, ostream):
        ostream.write("Container contains {} elements.\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream)
            ostream.write("\n")
        pass

    def WriteSorted(self, ostream):
        ostream.write("\nSorted figures:\n")
        for shape in self.store:
            shape.WriteSorted(ostream)
            ostream.write("\n")
        pass

    def Swap(self, i, j):
        temp = self.store[i]
        self.store[i] = self.store[j]
        self.store[j] = temp

    def QuickSort(self, low, high):
        if low >= high:
            return
        indexToSwap = low - 1
        for i in range(low, high):
            if self.store[i].Area() < self.store[high].Area():
                self.Swap(i, indexToSwap + 1)
                indexToSwap += 1
        self.Swap(high, indexToSwap + 1)
        indexToSwap += 1
        self.QuickSort(low, indexToSwap - 1)
        self.QuickSort(indexToSwap + 1, high)
        # for shape in self.store:
        #     shape.Write(ostream)
        #     ostream.write("\n")
        # pass