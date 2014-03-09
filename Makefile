CXXFLAGS=-O2 -std=c++0x -Wall -pedantic

BINARIES = reverse_list powerset binpower selection bineq fold dpSms dpHorse
BINARIES += matrix_fib max_prod lap cut_rod

all: $(BINARIES)

powerset: powerset.cc

reverse_list: reverse_list.cc

binpower: binpower.cc

selection: selection.cc

bineq: bineq.cc

fold: fold.cc

dpSms: dpSms.cc

dpHorse: dpHorse.cc

matrix_fib: matrix_fib.cc

max_prod: max_prod.cc

lap: lap.cc

cut_rod: cut_rod.cc

powerset_test: powerset
	echo '1 2 3' | ./powerset

reverse_list_test: reverse_list
	echo '1' | ./reverse_list
	echo '' | ./reverse_list
	echo '5 4 3 2 1' | ./reverse_list

binpower_test: binpower
	echo 0 0 | ./binpower
	echo 1 0 | ./binpower
	echo 3 1 | ./binpower
	echo 3 0 | ./binpower
	echo 3 4 | ./binpower
	echo 2 3 | ./binpower

selection_test: selection
	echo 5 4 3 5 2 1 4 | ./selection
	echo 1 2 1 | ./selection

cut_rod_test: cut_rod
	echo 1 1 1 | ./cut_rod
	echo 1 5 8 9 | ./cut_rod

.PHONY: powerset_test reverse_list_test binpower_test selection_test cut_rod_test
.PHONY: clean

clean:
	$(RM) $(BINARIES)
	$(RM) *.o