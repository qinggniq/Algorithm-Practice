from random import randrange


def get_arr(length):
    res = []
    for i in range(length):
        res.append(randrange(0, INT_MAX, 1)
    return res


def cal(arr):
    arr.sort()
    res = 0
    for i in range(len(arr)/2):
        res += (arr[i] * arr[-(1 + i)])
    for i in range(0, len(arr), 2):
        res -= (arr[i] * arr[i+1])
    return res

if __name__ == '__main__':
    for i in range(10):
        print(cal(get_arr(50)))
    
