from random import randrange
import json
def gen_cases_to_file(in_file, out_file, cnt):
    cases = gen_all_cases(cnt)
    with open(in_file, 'wb') as inf:
        for case in cases:
            json.dump(case['input']['arr'], inf)
            inf.write('\n')
            json.dump(case['input']['tar'], inf)
            inf.write('\n')
    with open(out_file, 'wb') as outf:
        for  case in cases:
            json.dump(case['output'], outf)
            outf.write('\n')
    
    

def gen_all_cases(cnt):
    res = []
    res.extend(gen_small_cases(int(cnt*0.9)))
    res.extend(gen_large_cases(int(cnt*0.1)))
    return res


def gen_large_cases(cnt):
    res = []
    length = 1000
    for i in range(cnt):
        res.append(gen_one_case(length - randrange(0, length/2, 1)))
    return res


def gen_small_cases(cnt):
    res = []
    length = 20
    for i in range(cnt):
        res.append(gen_one_case(length - randrange(0, length-3, 1)))
    return res

def gen_one_case(length):
    input = {'arr':[], 'tar':0}
    output = []
    #begin = randrange(-length*10, length*10, 1)
    for i in range(length):
        input['arr'].append(randrange(-length*10, length*10, 1))
    input['tar'], output = pick_one_sol(input['arr'])
    return {'input':input, 'output':output}
        

def pick_one_sol(arr):
    suitable = False
    tar = 0
    first = 0
    second = 0
    print(arr)
    while not suitable:
        first, second = pick_pair(len(arr))
        #print(first, second)
        tar = arr[first] + arr[second]
        suitable = True
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                if (arr[i] + arr[j] == tar) and (i != first or j != second):
                    suitable = False
                    break
    return [tar, [first, second]]
        

def pick_pair(len):
    while True:
        a, b = randrange(0, len, 1), randrange(0, len, 1)
        if a != b:
            a, b = min(a, b), max(a, b)
            return [a, b]


if __name__ == "__main__":
    gen_cases_to_file('1.in', '1.out', 100)
    #gen_small_cases(2)