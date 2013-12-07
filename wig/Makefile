BUILD_DIR=Debug

all: code check

clean:
	rm fwig; cd $(BUILD_DIR)/; make clean;

code:
	cd $(BUILD_DIR)/; make; ln -sf $(BUILD_DIR)/fwig ../fwig;

check: code unit pretty weed typecheck codegen_test

pretty: code
	cd tests/benchmarks/; python run.py;

weed: code bench_ng

typecheck: code
	cd tests/typecheck/; python run.py;

bench_ng: code
	cd tests/bench_ng/; python run.py;

codegen_test: code
	cd tests/codegen/; python run.py;

unit:
	@echo "I wrote my tests in python to test the entire program"
	@echo "instead of unit-testing individual functions..."
