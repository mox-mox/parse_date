all: parse_date


parse_date: test.cpp ../parse_date.cpp
	g++ test.cpp ../parse_date.cpp -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c++17 -I.. -o parse_date

run: parse_date
	./parse_date

clean:
	rm -f parse_date
