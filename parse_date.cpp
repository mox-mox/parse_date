#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>


// 1989-01-21/04:20:00
// 1989-01-21/04:20
// 1989-01-21/04
// 1989-01-21

//      01-21/04:20:00
//      01-21/04:20
//      01-21/04
//      01-21/

//         21/04:20:00
//         21/04:20
//         21/04
//         21/

//           /04:20:00
//           /04:20
//           /04
//           /



#include <iostream>


// [[[<yyyy>-]<mm>-]<dd>]/[<hh>[:<mm>[:<ss>]]]





std::time_t parse_time(const std::string& entry)
{
	if( entry.empty())
	{
		throw std::invalid_argument("Passed date string is empty.");
	}
	std::time_t now_time_t = std::time(nullptr);
	std::tm time_tm = *localtime(&now_time_t);
	time_tm.tm_isdst = -1;

	std::stringstream entry_stream(entry);
	std::string date;
	std::string time;
	//std::string time="0:0:0";


	if( !std::getline(entry_stream, date, '/').eof())
	{
		//std::cout<<"Given date is: "<<date<<std::endl;
		if( date.empty())
		{
			std::cout<<"empty date entered"<<std::endl;
		}
		if( date.find(":") == std::string::npos )
		{
			uint16_t dates[3];
			int i = -1;
			std::stringstream date_stream(date);
			std::string temp;
			while( !date_stream.eof() && std::getline(date_stream, temp, '-') && ++i <= 3 )
			{
				//std::cout<<"i: "<<i<<": ";
				dates[i] = std::stoi(temp, 0, 10);
				std::cout<<dates[i]<<std::endl;
			}
			i++;

			std::cout<<"day: if("<<i<<"--): ";
			if(i-- > 0)
			{
				std::cout<<i<<std::endl;
				time_tm.tm_mday = dates[i];
			}

			std::cout<<"month: if("<<i<<"--): ";
			if(i-- > 0)
			{
				std::cout<<i<<std::endl;
				time_tm.tm_mon = dates[i]-1;
			}

			std::cout<<"year: if("<<i<<"--): ";
			if(i-- > 0)
			{
				std::cout<<i<<std::endl;
				time_tm.tm_year = dates[i]-1900;
			}
		}
		else
		{
			if( date.find("-") == std::string::npos )
			{
				time = date;
			}
			else
			{
				throw std::invalid_argument("Passed date mixed up date separator (-) and time separator(:) in the date part.");
			}
		}



		std::getline(entry_stream, time);
	}
	else
	{
		time = date;
	}

	// parse time
	{
		std::cout<<"Given time is: "<<time<<std::endl;
		if( time.empty())
		{
			std::cout<<"empty time entered"<<std::endl;
			//time="0:0:0";
		}
		if( time.find("-") != std::string::npos )
		{
			throw std::invalid_argument("Passed time mixed up date separator (-) and time separator(:) in the time part.");
		}

		uint16_t times[3];
		int i = -1;
		std::stringstream time_stream(time);
		std::string temp;
		while( !time_stream.eof() && std::getline(time_stream, temp, ':') && ++i <= 3 )
		{
			std::cout<<"i: "<<i<<": ";
			times[i] = std::stoi(temp, 0, 10);
			std::cout<<times[i]<<std::endl;
		}
		i++;

		if( 0 < i )
		{
			time_tm.tm_hour = times[0];
		}

		if( 1 < i )
		{
			time_tm.tm_min = times[1];
		}

		if( 2 < i )
		{
			time_tm.tm_sec = times[2];
		}
	}

	return std::mktime(&time_tm);
}
