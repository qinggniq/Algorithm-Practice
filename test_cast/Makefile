PYTHON=/usr/bin/python3
UTILS_DIR=../utils
template : 
	touch __init__.py hints tags input.json output.json solution.py test_case_generator.py problem.md
	cp ../in ./

testcase:
	$(PYTHON) test_case_generator.py 

json:
	$(PYTHON) $(UTILS_DIR)/problem_setter.py < in

submit:
	tar czf problem.tar.gz problem.json test_case_generator.py

all: json testcase submit
