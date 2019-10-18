PYTHON=/usr/local/bin/python3
gen_template : 
	touch __init__.py hints tags input.json output.json solution.py test_case_generator.py problem.md
	cp ../in ./

gen_data:
	$(PYTHON) test_case_generator.py 

gen_json:
	$(PYTHON) ../util/problem_setter.py < in