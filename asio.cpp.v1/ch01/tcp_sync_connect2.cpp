#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif

#include <system_error>
#include <iostream>
#include "asio.hpp"

using namespace asio;

int main()
{
	io_context service;
	ip::tcp::endpoint ep( ip::address::from_string("127.0.0.1"), 2001);

	ip::tcp::socket sock(service);
	try {
		sock.connect(ep);
	} catch(std::system_error e) {
		std::cout << e.code() << std::endl;
	}

	return 0;
}

