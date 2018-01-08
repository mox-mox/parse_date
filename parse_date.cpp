#include <ctime>
#include <iomanip>
#include <string>
#include <sstream>

// TODO: Use std::get_time

// 1989-01-21T04:20:00
// 1989-01-21T04:20
// 1989-01-21T04
// 1989-01-21

//      01-21T04:20:00
//      01-21T04:20
//      01-21T04
//      01-21T

//         21T04:20:00
//         21T04:20
//         21T04
//         21T

//           T04:20:00
//           T04:20
//           T04
//           T



#include <iostream>


// [[[<yyyy>-]<mm>-]<dd>]T[<hh>[:<mm>[:<ss>]]]





std::time_t parse_time(const std::string& entry)
{
	std::tm t = {};
	std::istringstream ss("");
	if(const char* lang=getenv("LANG"); lang) ss.imbue(std::locale(lang));

	if(ss=std::istringstream(entry), ss >> std::get_time(&t, "%Y-%m-%d %H:%M:%S"); !ss.fail()) return mktime(&t);
	if(ss=std::istringstream(entry), ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S"); !ss.fail()) return mktime(&t);

	std::cout << "Parse failed\n";
	return mktime(&t);






//	ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
//	if (ss.fail()) {
//		std::cout << "Parse failed\n";
//	} else {
//		std::cout << std::put_time(&t, "%c") << '\n';
//	}
//
//	return mktime(&t);

















	//if( entry.empty())
	//{
	//	throw std::invalid_argument("Passed date string is empty.");
	//}
	//std::time_t now_time_t = std::time(nullptr);
	//std::tm time_tm = *localtime(&now_time_t);
	//time_tm.tm_isdst = -1;

	//std::stringstream entry_stream(entry);
	//std::string date;
	//std::string time;


	//// Parse date
	//if( !std::getline(entry_stream, date, 'T').eof() || date.find("-") != std::string::npos)
	//{
	//	if(date.find(":") != std::string::npos)
	//	{
	//		throw std::invalid_argument("Passed date mixed up date separator (-) and time separator(:) in the date part.");
	//	}

	//	uint16_t dates[3];
	//	int i = -1;
	//	std::stringstream date_stream(date);
	//	std::string temp;
	//	while( !date_stream.eof() && std::getline(date_stream, temp, '-') && ++i <= 3 )
	//	{
	//		dates[i] = std::stoi(temp, 0, 10);
	//	}
	//	i++;

	//	if(i-- > 0)
	//	{
	//		time_tm.tm_mday = dates[i];
	//	}

	//	if(i-- > 0)
	//	{
	//		time_tm.tm_mon = dates[i]-1;
	//	}

	//	if(i-- > 0)
	//	{
	//		time_tm.tm_year = dates[i]-1900;
	//	}
	//}
	//else
	//{
	//	time = date;
	//}



	//std::getline(entry_stream, time);

	//// Parse time
	//if( time.find("-") != std::string::npos )
	//{
	//	throw std::invalid_argument("Passed time mixed up date separator (-) and time separator(:) in the time part.");
	//}

	//uint16_t times[3];
	//int i = -1;
	//std::stringstream time_stream(time);
	//std::string temp;
	//while( !time_stream.eof() && std::getline(time_stream, temp, ':') && ++i <= 3 )
	//{
	//	times[i] = std::stoi(temp, 0, 10);
	//}
	//i++;

	//if( 0 < i )
	//{
	//	time_tm.tm_hour = times[0];
	//}

	//if( 1 < i )
	//{
	//	time_tm.tm_min = times[1];
	//}
	//else if( 0 < i)
	//{
	//	time_tm.tm_min = 0;
	//}


	//if( 2 < i )
	//{
	//	time_tm.tm_sec = times[2];
	//}
	//else if( 0 < i)
	//{
	//	time_tm.tm_sec = 0;
	//}

	//return std::mktime(&time_tm);
}
