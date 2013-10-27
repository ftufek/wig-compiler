all: code check

clean:
	rm fwig; cd Release/; make clean;

code:
	cd Release/; make; ln -sf Release/fwig ../fwig;

check: weed pretty unit

pretty: code
	cd tests/benchmarks/; python run.py;

weed: code
	cd tests/weeder/; python run.py;

unit:
	@echo "I wrote my tests in python to test the entire program"
	@echo "instead of unit-testing individual functions..."
