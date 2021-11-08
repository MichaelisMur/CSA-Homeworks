from extender import *

def ReadStrArray(container, strArray):
    print('Filling the container...\n\n')
    arrayLen = len(strArray)
    i = 0   # Индекс, задающий текущую строку в массиве
    figInd = 0  # Индекс для подсчета фигур
    figNum = 0
    while i < arrayLen:
        str = strArray[i]
        key = int(str)   # преобразование в целое
        if key == 1: # признак окружности
            i += 1
            shape = Circle(figInd)
            i = shape.ReadStrArray(strArray, i) # чтение окружности с возвратом позиции за ней
        elif key == 2: # признак прямоугольника
            i += 1
            shape = Rectangle(figInd)
            i = shape.ReadStrArray(strArray, i) # чтение прямоугольника с возвратом позиции за ним
        elif key == 3: # признак треугольника
            i += 1
            shape = Triangle(figInd)
            i = shape.ReadStrArray(strArray, i) # чтение треугольника с возвратом позиции за ним
        else:
            # что-то пошло не так. Должен быть известный признак
            # Возврат количества прочитанных фигур
            return figNum
        # Количество пробелами фигур увеличивается на 1
        if i == 0:
            return figNum
        figNum += 1
        figInd += 1
        container.store.append(shape)
    print('Container was successfully filled')
    return figNum
