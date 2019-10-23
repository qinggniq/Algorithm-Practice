
import csv
import json


def sortFileByNO(infile, outfile=""):
    hint_json = {'byOrder': {}, 'byProblem': {}}
    with open(infile, "r", encoding="utf-8") as f:
        csv_reader = csv.reader(f, delimiter="\t")
        res = []
        for row in csv_reader:
            if len(row) != 0:
                res.append(row)
        res.sort(key=lambda x: int(str(x[0][1:-1])))

        for hint in res:
            hint_json['byOrder'][hint[0][:-1]] = hint[2]
            if hint[1] not in hint_json['byProblem']:
                hint_json['byProblem'][hint[1]] = [hint[2]]
            else:
                hint_json['byProblem'][hint[1]].append(hint[2])
        with open(outfile, "w", encoding='utf-8') as f:
            f.write(json.dumps(hint_json, sort_keys=False,
                               indent=4, ensure_ascii=False))


if __name__ == '__main__':
    sortFileByNO("../resource/hints", "../resource/hints.json")
