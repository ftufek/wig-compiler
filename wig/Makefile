BUILD_DIR=Debug

all: code check

clean:
	rm fwig; cd $(BUILD_DIR)/; make clean;

code:
	cd $(BUILD_DIR)/; make; ln -sf $(BUILD_DIR)/fwig ../fwig;

check: unit pretty weed typecheck

pretty: code
	cd tests/benchmarks/; python run.py;

weed: bench_ng

typecheck:
	cd tests/typecheck/; python run.py;

bench_ng: code
	cd tests/bench_ng/; python run.py;

unit:
	@echo "I wrote my tests in python to test the entire program"
	@echo "instead of unit-testing individual functions..."
