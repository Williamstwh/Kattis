MAKEFLAGS += -s

# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  # use the rest as arguments for "run"
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  # ...and turn them into do-nothing targets
  $(eval $(RUN_ARGS):;@:)
endif

# C++ compiler
CC := /usr/local/bin/g++-10

# C++ version
CPPVERSION := 11

# Folders to include
FOLDERS := kattis kickstart leetcode

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
	@for i in $(FOLDERS); do \
		for j in $$(find $$i -type f -name "*.cpp"); do \
			k=$$(echo $$j | sed -e "s/\//\-/g; s/\.cpp//"); \
			echo "add_executable($$k $$j)" >> CMakeLists.txt; \
		done \
	done
