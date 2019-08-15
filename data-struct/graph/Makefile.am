bin_PROGRAMS = graph
graph_SOURCES = test_prim.cc graph_link.hpp prim.hpp prim_heap.hpp

all-am: graph
	touch bin/graph.sh

graph: bin/graph.sh
	@echo "hello autotools"

clean-local:
	@rm config.status configure config.log
	@rm Makefile
	@rm -r auto4te.cache/
	@rm aclocal.m4
	@rm compile install-sh missing Makefile.in

