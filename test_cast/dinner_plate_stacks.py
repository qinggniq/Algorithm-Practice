
import random
from random import randrange
import json
import heapq

class DinnerPlatesGenerator:
    def __init__(self):
        random.seed(1997)
        self.max_int = 2**30
        self.small_rate = 0.6
        self.medium_rate = 0.3
        self.large_rate = 0.1
        self.small_range = (5, 30)
        self.medium_range = (30, 1000)
        self.large_range = (15000, 20000)
        self.input = []
        self.output = []
        self.operator_rate_when_worst_case = [[1, 0, 0], [0.33, 0.33, 0.33], [0.5, 0, 0.5]]
        self.operators = ['push', 'pop',  'popAtStack']
    
    def range_choice(self, end, start = 0):
        return randrange(start, end, 1)
    
    def _gen_call_sequence_random(self, max_operators, length):
        res = []
        for i in range(length):
            res.append(self.range_choice(max_operators))
        return res

    def _gen_call_sequence_worst(self, max_operators, length, idx = 0):
        res = []
        op_times = list(map(lambda x: int(x*length), self.operator_rate_when_worst_case[idx]))
        for i in range(len(self.operators)):
            for j in range(op_times[i]):
                res.append(i)
        return res
                

    def _gen_input_sequence_random(self, call_seq):
        res = []
        length = len(call_seq)
        for op in call_seq:
            if op <= 0:
                res.append(self.range_choice(length*2))
            elif op == 2:
                res.append(self.range_choice(length))
            else:
                res.append(None)
        return res

    def gen_one_case_random(self, length):
        res = {'cap': 0 ,'op':[], 'val':[]}
        max_operators = len(self.operators)
        res['cap'] = self.range_choice(length, 1)
        res['op'] = self._gen_call_sequence_random(max_operators, length)
        res['val'] = self._gen_input_sequence_random(res['op'])
        return res
    
    def gen_one_case_worst(self, length, idx = 0):
        res = {'cap': 0 ,'op':[], 'val':[]}
        max_operators = len(self.operators)
        res['cap'] = self.range_choice(length, 1)
        res['op'] = self._gen_call_sequence_worst(max_operators, length, idx)
        res['val'] = self._gen_input_sequence_random(res['op'])
        return res

    def gen_cases_random(self, cnt, len_range):
        res = []
        for i in range(cnt):
            res.append(self.gen_one_case_random(self.range_choice(len_range[1], len_range[0])))
        return res
    
    def gen_cases_worst(self, cnt, len_range):
        res = []
        for i in range(cnt):
            length = self.range_choice(len_range[1], len_range[0])
            res.append(self.gen_one_case_worst(length, i))
        return res
    
    def get_small_num(self, cnt):
        return max(int(self.small_rate * cnt), 5)
    
    def get_medium_num(self, cnt):
        return max(int(self.medium_rate * cnt), 5)
    
    def get_large_num(self, cnt):
        return min(int(self.large_rate * cnt), 5)
    
    def gen_different_cases(self, cnt):
        res = []
        res.extend(self.gen_cases_random(self.get_small_num(cnt), self.small_range))
        res.extend(self.gen_cases_random(self.get_medium_num(cnt), self.medium_range))
        res.extend(self.gen_cases_random(self.get_large_num(cnt), self.large_range))
        res.extend(self.gen_cases_worst(len(self.operator_rate_when_worst_case), self.large_range))
        return res

    def get_cases_res(self, cases):
        res = []
        for case in cases:
            dinner_plate = DinnerPlates(case['cap'])
            cur_res = []
            for i in range(len(case['op'])):
                if case['op'][i] <= 0:
                    dinner_plate.push(case['val'][i])
                    cur_res.append(None)
                elif case['op'][i] == 1:
                    cur_res.append(dinner_plate.pop())
                else:
                    cur_res.append(dinner_plate.popAtStack(case['val'][i]))
            res.append(cur_res)
        return res
    
    def write(self, input_file, output_file, cnt):
        input_cases = self.gen_different_cases(cnt)
        output_res = self.get_cases_res(input_cases)
        with open(input_file, 'w') as inf:
            #json.dump(input_cases, inf)
            for case in input_cases:
                for i in range(len(case['op'])):
                    case['op'][i] = self.operators[case['op'][i]]
                case['op'] = ['DinnerPlates'] + case['op']
                case['val'] = [case['cap']] + case['val']
                json.dump(case['op'], inf)
                inf.write('\n')
                json.dump(case['val'], inf)
                inf.write('\n')
        with open(output_file, 'w') as ouf:
            for res in output_res:
                res = [None] + res
                json.dump(res, ouf)
                ouf.write('\n')


    
#Solution of this problem
class DinnerPlates:
    def __init__(self, capacity):
        self.c = capacity
        self.q = []
        self.stacks = []

    def push(self, val):
        while self.q and self.q[0] < len(self.stacks) and len(self.stacks[self.q[0]]) == self.c:
            heapq.heappop(self.q)
        if not self.q:
            heapq.heappush(self.q, len(self.stacks))
        if self.q[0] == len(self.stacks):
            self.stacks.append([])
        self.stacks[self.q[0]].append(val)

    def pop(self):
        while self.stacks and not self.stacks[-1]:
            self.stacks.pop()
        return self.popAtStack(len(self.stacks) - 1)

    def popAtStack(self, index):
        if 0 <= index < len(self.stacks) and self.stacks[index]:
            heapq.heappush(self.q, index)
            return self.stacks[index].pop()
        return -1

if __name__ == "__main__":
    dpg = DinnerPlatesGenerator()
    dpg.write('1.in', '1.out', 25)
    #gen_small_cases(2)