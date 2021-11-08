def getColour(n):
    if n < 0 or n > 6:
        return "???"
    return {
        0: 'red',
        1: 'orange',
        2: 'yellow',
        3: 'green',
        4: 'blue',
        5: 'darkblue',
        6: 'purple'
    }[n]