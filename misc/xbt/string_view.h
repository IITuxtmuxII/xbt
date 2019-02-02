#pragma once

#include <boost/convert.hpp>
#include <boost/convert/strtol.hpp>
#include <boost/utility/string_view.hpp>
#include <string>

namespace std 
{
	using string_view = boost::string_view;
}

inline std::string& operator+=(std::string& a, std::string_view b)
{
	return a.append(b.data(), b.size());
}

inline std::string& operator<<(std::string& a, std::string_view b)
{
	return a += b;
}

template<class T>
inline std::enable_if_t<std::is_integral<T>::value, std::string&> operator<<(std::string& a, T b)
{
	return a += std::to_string(b);
}

inline float to_float(std::string_view v)
{
	return boost::convert<float>(v, boost::cnv::strtol(), 0.0f);
}

inline long long to_int(std::string_view v)
{
	return boost::convert<long long>(v, boost::cnv::strtol(), 0);
}