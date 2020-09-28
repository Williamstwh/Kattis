MAKEFLAGS += -s

# If the first argument is "run"...
ifneq (,$(filter $(firstword $(MAKECMDGOALS)),run))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

# C++ compiler
CC := /usr/local/bin/g++-10

# C++ version
CPPVERSION := 11

# Sources to include
SOURCES := kattis kickstart leetcode

.PHONY: run cmake

run:
	@$(CC) $(RUN_ARGS)/*.cpp -o $(RUN_ARGS)/main.out;
	@for i in $(RUN_ARGS)/*.in; do \
  		echo; \
		echo ===============================; \
		echo $$i; \
		echo ===============================; \
		$(RUN_ARGS)/main.out < $$i; \
	done
	@rm -rf $(RUN_ARGS)/main.out;

cmake:
	@echo 'cmake_minimum_required(VERSION 3.16)' > CMakeLists.txt
	@echo 'project(cppcp)' >> CMakeLists.txt
	@echo >> CMakeLists.txt
	@echo 'set(CMAKE_CXX_STANDARD $(CPPVERSION))' >> CMakeLists.txt
	@echo 'set(CMAKE_CXX_COMPILER $(CC))' >> CMakeLists.txt
	@echo >> CMakeLists.txt
	@echo 'set(GCC_COVERAGE_COMPILE_FLAGS "-DREAD_STDIN_FROM_FILE")' >> CMakeLists.txt
	@echo 'add_definitions($${GCC_COVERAGE_COMPILE_FLAGS})' >> CMakeLists.txt
	@echo >> CMakeLists.txt
	@for source in $(SOURCES); do \
		for file in $$(find $$source -type f -name "*.cpp"); do \
			folder=$$(echo $$file | rev | cut -d '/' -f 2- | rev); \
			executable="$$(echo $$file | sed -e "s/\//\-/g; s/\.cpp//").out"; \
			echo "add_executable($$executable $$file)" >> CMakeLists.txt; \
			echo "set_target_properties($$executable PROPERTIES RUNTIME_OUTPUT_DIRECTORY "'$${PROJECT_SOURCE_DIR}'"/$$folder)" >> CMakeLists.txt; \
		done \
	done
