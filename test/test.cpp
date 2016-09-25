#include <iostream>
#include <iomanip>
#include <chrono>
#include "parse_date.hpp"

int main()
{
	std::cout<<"Please enter the date:"<<std::endl;
	std::string entry;
	std::cin>>entry;
	std::time_t my_time = parse_time(entry);


	std::chrono::system_clock::time_point chrono_time = std::chrono::system_clock::from_time_t(my_time);

	std::cout<<std::chrono::duration_cast < std::chrono::seconds > (chrono_time.time_since_epoch()).count()<<std::endl;

	std::time_t t = std::chrono::system_clock::to_time_t(chrono_time);
	std::cout<<"["<<std::put_time(std::localtime(&t), "%F/%T")<<"] "<<std::endl;
}
