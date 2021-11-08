import time
start_time = time.time()

import sys
import string

from extender import *


#----------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) == 3:
        inputFileName  = sys.argv[1]
        outputFileName = sys.argv[2]
    elif len(sys.argv) == 2:
        inputFileName  = sys.argv[1]
        outputFileName = "../Tests/output.txt"
    elif len(sys.argv) == 1:
        print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]")
        exit()

    # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
    ifile = open(inputFileName)
    str = ifile.read()
    ifile.close()

    # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
    strArray = str.replace("\n", " ").split(" ")

    print('Start')

    container = Container()
    figNum = ReadStrArray(container, strArray)

    ofile = open(outputFileName, 'w')
    container.Write(ofile)

    container.QuickSort(0, len(container.store) - 1)
    container.WriteSorted(ofile)
    
    ofile.close()

    print('Finish!')

print(round((time.time() - start_time) * 1000, 5), "ms")