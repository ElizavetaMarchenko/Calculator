#include "read_plugin.h"
#include <Windows.h>
#include<string>
#include<map>

read_plugin::read_plugin() {
	WIN32_FIND_DATAA detection;
	HANDLE detect = FindFirstFileA((path + std::string("*.dll")).c_str(), &detection);
	if (detect == INVALID_HANDLE_VALUE) {
		throw std::exception();
	}
	else {
		do {
			std::string function_name(detection.cFileName);
			HMODULE hm = LoadLibraryA((path + function_name).c_str());
			if (!hm) throw std::exception();

			std::string function = function_name.substr(0, function_name.find(".dll"));

			auto func = (double(*)(double))GetProcAddress(hm, "universal_function");

			if (func) {
				plugins.insert(std::pair<std::string, double(*)(double)>(function, func));
			}
			else throw std::exception();
		} while (FindNextFileA(detect, &detection) != NULL);
	}
}
double read_plugin::process_expression(std::string str, double num) {
	return(plugins[str](num));
}

bool read_plugin::is_in_plugins(std::string str) {
	return(plugins.find(str) != plugins.end());
}