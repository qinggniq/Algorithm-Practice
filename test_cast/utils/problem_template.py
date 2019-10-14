import json


class ProblemTemplate():
    def __init__(self):
        self.title = "Problem"
        self.title_cn = u"题目"
        self.description_cn = u"html"
        self.difficulty = 1  # 1 for easy 2 for medium 3 for hard
        self.input_schema = {}
        self.output_schema = {}
        self.solution = []
        self.testcase_in = ""
        self.testcase_out = ""
        self.hints = []
        self.tags = ""
        self.question_no = ""
        self.book_name = ""

    def set_title(self, title: str):
        self.title = title

    def set_title_cn(self, title_cn: str):
        self.title_cn = title_cn

    def set_description_cn(self, description_cn: str):
        self.description_cn = description_cn

    def set_difficulty(self, difficulty: str):
        self.difficulty = difficulty

    def set_input_schema(self, input_schema: str):
        self.input_schema = input_schema

    def set_output_schema(self, output_schema: str):
        self.output_schema = output_schema

    def set_solution(self, solution: str):
        self.solution = solution

    def set_testcase_in(self, testcase_in: str):
        self.testcase_in = testcase_in

    def set_testcase_out(self, testcase_out: str):
        self.testcase_out = testcase_out

    def set_hints(self, hints: list):
        self.hints = hints

    def set_tags(self, tags: list):
        self.tags = tags

    def set_question_no(self, question_no):
        self.question_no = question_no

    def set_book_name(self, book_name):
        self.book_name = book_name

    def to_json(self):
        return json.dumps(self, default=lambda o: o.__dict__, sort_keys=True, indent=4)
