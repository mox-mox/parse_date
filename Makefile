all: parse_date


parse_date: main.cpp parse_date.cpp
	g++ main.cpp parse_date.cpp -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -std=c++17 -o parse_date

run: parse_date
	./parse_date

clean:
	rm -f parse_date
