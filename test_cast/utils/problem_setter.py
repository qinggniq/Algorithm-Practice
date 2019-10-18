import json
import markdown2
import os
from problem_metadata import ProblemMetaData
from problem_template import ProblemTemplate
from io_helper import IOHelper
from console import Console

problem_metadata = ProblemMetaData()


class Parser:
    @staticmethod
    def markdown2html(text: str) -> str:
        return markdown2.markdown(text)

    @staticmethod
    def json2dict(text: str) -> dict:
        return json.loads(text)


class ProblemSetter():
    def __init__(self):
        self.problem_template = ProblemTemplate()
        self.io_helper = IOHelper()
        self.console = Console()
        self.problem_metadata = problem_metadata

    def __fill_title(self):
        self.console.showAny("title : ")
        title = self.io_helper.readStr()
        self.problem_template.set_title(title)

    def __fill_title_cn(self):
        self.console.showAny(u"标题 : ")
        title_cnt = self.io_helper.readStr()
        self.problem_template.set_title_cn(title_cnt)

    def __fill_description_cn(self):
        self.console.showAny(u"题目描述文件名 : ")
        file = self.io_helper.readStr()
        raw_content = ""
        description_cn = ""
        with open(file, "r") as f:
            raw_content = f.read()
            # TODO add mote file type support
            if file.split(".")[-1] in ["html", "htm", ".html", ".htm"]:
                description_cn = raw_content
            else:
                description_cn = Parser.markdown2html(raw_content)
        self.problem_template.set_description_cn(description_cn)

    def __fill_difficulty(self):
        self.console.showAny(u"题目难度 : ")
        difficulty = self.io_helper.readInt()
        self.problem_template.set_difficulty(difficulty)

    def __fill_input_schema(self):
        self.console.showAny(u"输入格式文件名 : ")
        file = self.io_helper.readStr()
        raw_content = ""
        input_schema = {}
        with open(file, "r") as f:
            raw_content = f.read()
            assert file.split(".")[-1] in ["json"]
            input_schema = Parser.json2dict(raw_content)
        self.problem_template.set_input_schema(input_schema)

    def __fill_output_schema(self):
        self.console.showAny(u"输出格式文件名 : ")
        file = self.io_helper.readStr()
        raw_content = ""
        output_schema = {}
        with open(file, "r") as f:
            raw_content = f.read()
            assert file.split(".")[-1] in ["json"]
            output_schema = Parser.json2dict(raw_content)
        self.problem_template.set_output_schema(output_schema)

    def __fill_solution(self):
        self.console.showAny(u"题目答案文件名 : ")
        file = self.io_helper.readStr()
        solution = {}
        with open(file, "r") as f:
            solution['code'] = f.read()
            suffix = file.split(".")[-1].lower()
            assert suffix in ["py", "java",
                              "cc", "rust", "golang"]
            if suffix == 'py':
                solution['lang'] = 'python3'
            elif suffix == 'java':
                solution['lang'] = 'java'
            elif suffix in ['cc', 'cpp']:
                solution['lang'] = 'C++'
            elif suffix == 'rst':
                solution['lang'] = 'rust'
        self.problem_template.set_solution([solution])

    def __fill_testcase_in(self):
        self.console.showAny(u"输入数据文件名 : ")
        file = self.io_helper.readStr()
        testcase_in = ""
        with open(file, "r") as f:
            testcase_in = f.read()
        self.problem_template.set_testcase_in(testcase_in)

    def __fill_testcase_out(self):
        self.console.showAny(u"输出数据文件名 : ")
        file = self.io_helper.readStr()
        testcase_out = ""
        with open(file, "r") as f:
            testcase_out = f.read()
        self.problem_template.set_testcase_out(testcase_out)

    def __fill_hints(self):
        self.console.showAny(u"提示文件名 : ")
        file = self.io_helper.readStr()
        hints = []
        with open(file, "r") as f:
            raw_content = f.read()
            # TODO parse json to vector type
            hints = raw_content.split("\n")  # Parser.json2dict(raw_content)
        res = [x for x in hints if len(x) != 0]
        self.problem_template.set_hints(res)

    def __fill_tags(self):
        self.console.showAny(u"标签文件名 : ")
        file = self.io_helper.readStr()
        tags = []
        with open(file, "r") as f:
            raw_content = f.read()
            # TODO parse json to vector type
            tags = raw_content.split("\n")  # Parser.json2dict(raw_content)
        self.problem_template.set_tags(tags)

    def __fill_question_no(self):
        self.console.showAny(u"题号 : ")
        question_no = self.io_helper.readStr()
        self.problem_template.set_question_no(question_no)

    def __fill_book_name(self):
        self.console.showAny(u"书名 : ")
        book_name = self.io_helper.readStr()
        self.problem_template.set_book_name(book_name)

    def fill_problem_template(self):
        self.__fill_title()
        self.__fill_title_cn()
        self.__fill_description_cn()
        self.__fill_difficulty()
        self.__fill_input_schema()
        self.__fill_output_schema()
        self.__fill_solution()
        self.__fill_testcase_in()
        self.__fill_testcase_out()
        self.__fill_hints()
        self.__fill_tags()
        self.__fill_question_no()
        self.__fill_book_name()

    def save_problem_file(self, file: str):
        with open(file, 'w', encoding='utf-8') as f:
            f.write(self.problem_template.to_json())
            # f.write()


if __name__ == '__main__':
    ps = ProblemSetter()
    ps.fill_problem_template()
    ps.save_problem_file('problem.json')
