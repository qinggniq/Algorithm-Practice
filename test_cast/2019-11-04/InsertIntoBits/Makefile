PYTHON=/usr/bin/python3
UTILS_DIR=../utils
DATE=$(shell date +%Y-%m-%d)
PROBLEM=problem

template : 
	touch __init__.py hints tags input.json output.json solution.py test_case_generator.py problem.md
	cp ../../in ./

testcase:
	$(PYTHON) test_case_generator.py 

json:
	$(PYTHON) $(UTILS_DIR)/problem_setter.py < in

submit:
	tar czf problem.tar.gz problem.json test_case_generator.py

new:
	if test -d ${DATE}; then \
		echo ${DATE} already exists ...; \
	else \
		mkdir -p ${DATE}; \
		cp -r utils ${DATE};\
		cp -r resource ${DATE};\
	fi
	@for f in $(shell cat $(PROBLEM)); do mkdir $(DATE)/$${f}; cp ./Makefile $(DATE)/$${f}; cp ./in $(DATE)/$${f}; make template ;done
	

	
all: json testcase submit
