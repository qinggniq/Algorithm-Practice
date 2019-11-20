import argparse
import copy
import json

import jsonschema


def check_normal_testcases(question_obj):
    per_testcase_len: int = len(question_obj["input_schema"]["properties"])
    # Using default split algorithm to allow 'bad' inputs
    testcase_in_splitted = list(
        map(json.loads, question_obj["testcase_in"].splitlines())
    )
    testcase_out_list = list(
        map(json.loads, question_obj["testcase_out"].splitlines()))

    if per_testcase_len == 0:
        raise Exception("No-input functions are not supported currently.")

    if len(testcase_in_splitted) % per_testcase_len != 0:
        raise Exception(
            f"The input lines count {len(testcase_in_splitted)} "
            f"should be a multiply of {per_testcase_len}. Please check."
        )

    if len(testcase_in_splitted) != per_testcase_len * len(testcase_out_list):
        raise Exception("testcase_in and testcase_out has different size.")

    testcase_in_list = [
        dict(
            zip(
                question_obj["input_schema"]["properties"].keys(),
                testcase_in_splitted[i: i + per_testcase_len],
            )
        )
        for i in range(0, len(testcase_in_splitted), per_testcase_len)
    ]

    for i in range(len(testcase_in_list)):
        try:
            jsonschema.validate(
                instance=testcase_in_list[i], schema=question_obj["input_schema"]
            )
        except Exception as e:
            raise Exception(f"Error in validating testcase No.{i + 1}: {e}")

        try:
            jsonschema.validate(
                instance=testcase_out_list[i], schema=question_obj["output_schema"]
            )
        except Exception as e:
            raise Exception(f"Error in validating testcase No.{i + 1}: {e}")


def check_design_testcases(question_obj):
    input_schema_map = question_obj['input_schema']['properties']
    output_schema_map = question_obj['output_schema']
    testcase_in_splitted = list(
        map(json.loads, question_obj["testcase_in"].splitlines())
    )
    testcase_out_list = list(
        map(json.loads, question_obj["testcase_out"].splitlines())
    )

    if len(testcase_in_splitted) % 2 != 0:
        raise Exception(
            'wrong testcase_in format, the number of lines in testcase_in should be even')

    testcase_num = len(testcase_out_list)
    if len(testcase_in_splitted) // 2 != testcase_num:
        raise Exception("the testcase input and output number don't match")

    for i in range(testcase_num):
        method_calls = testcase_in_splitted[2 * i]
        inputs = testcase_in_splitted[2 * i + 1]
        outputs = testcase_out_list[i]
        call_num = len(method_calls)

        if call_num != len(inputs) or call_num != len(outputs):
            raise Exception(f"wrong input output format in testcase {i + 1}")
        # print(inputs)
        for j in range(call_num):
            cur_input = dict(
                zip(
                    input_schema_map[method_calls[j]]['properties'].keys(),
                    inputs[j],
                )
            )
            try:
                jsonschema.validate(
                    cur_input, input_schema_map[method_calls[j]])
            except Exception as e:
                raise Exception(
                    f"Error in validating testcase input No.{i + 1}, method name: {method_calls[j]}. Detail: {e}")

            try:
                jsonschema.validate(
                    outputs[j], output_schema_map[method_calls[j]])
            except Exception as e:
                raise Exception(
                    f"Error in validating testcase output No.{i + 1}, method name: {method_calls[j]}. Detail: {e}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", help="file name of your json file")
    parser.add_argument(
        '-b',
        '--book',
        required=False,
        default=False,
        action="store_true",
        help='apply this if it is a book schema',
    )
    parser.add_argument(
        '-s',
        '--same',
        required=False,
        default=False,
        action="store_true",
        help="apply this if there is an existing question id that is the same as current one.",
    )

    args = parser.parse_args()

    solution_schema = {
        "type": "object",
        "properties": {
            "lang": {
                "type": "string",
                "enum": ["c", "cpp", "java", "python", "python3"],
            },
            "code": {"type": "string"},
        },
        "additionalProperties": False,
        "required": ["lang", "code"],
    }

    # schema for problems which will be in our main problemset.
    main_schema = {
        "type": "object",
        "properties": {
            "title": {"type": "string", "minLength": 1, "maxLength": 255},
            "title_cn": {"type": "string", "minLength": 1, "maxLength": 255},
            "description": {"type": "string"},
            "description_cn": {"type": "string"},
            "difficulty": {"type": "integer", "minimum": 1, "maximum": 3},
            "hints": {"type": "array", "items": {"type": "string"}},
            "tags": {"type": "array", "items": {"type": "string"}},
        },
        "required": [
            "title_cn",
            "description_cn",
            "difficulty",
        ],
        "additionalProperties": False,
    }

    if not args.same:
        main_schema['required'].extend([
            "input_schema",
            "output_schema",
            "solutions",
            "testcase_in",
            "testcase_out",
        ])
        main_schema['properties'].update({
            "input_schema": {"type": "object"},
            "output_schema": {"type": "object"},
            "solutions": {"type": "array", "items": solution_schema, "minItems": 1},
            "testcase_in": {"type": "string"},
            "testcase_out": {"type": "string"},
        })

    # schema for problems which will be in book category.
    # question_no is the question No. in the book (e.g. 2.3),
    # and will display in LCCN as display_id
    book_additional_properties = {
        "question_no": {"type": "string", "minLength": 1, "maxLength": 255},
        "book_name": {"type": "string", "enum": ["LCCI", "LCOF"]},
    }

    book_schema = copy.deepcopy(main_schema)
    book_schema["properties"].update(book_additional_properties)
    book_schema["required"].extend(
        ["title", "question_no", "book_name", "hints", "tags"])

    with open(args.filename, "r") as f:
        question_obj = json.load(f)

    target_schema = book_schema if args.book else main_schema

    jsonschema.validate(question_obj, target_schema)

    if not args.same:
        if not question_obj['input_schema'].get('systemdesign'):
            print(question_obj['input_schema'].get('systemdesign'))
            check_normal_testcases(question_obj)
        else:
            check_design_testcases(question_obj)

    print("All checks passed!")


if __name__ == '__main__':
    main()
