BUILD_DIR=build

all: code check

clean:
	rm fwig; cd $(BUILD_DIR)/; make clean;

code:
	@echo "Compiling..."
	@cd $(BUILD_DIR)/; make > /dev/null; ln -sf $(BUILD_DIR)/fwig ../fwig;

check: code pretty weed typecheck codegen_test

pretty: code
	@cd tests/parsing/; python run.py;

weed: code error_detection

typecheck: code
	@cd tests/typecheck/; python run.py;

error_detection: code
	@cd tests/error_detection/; python run.py;

codegen_test: code
	@cd tests/codegen/; python run.py;

unit:
	@echo "I wrote my tests in python to test the entire program"
	@echo "instead of unit-testing individual functions..."
