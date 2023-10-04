#ifndef DLL_READER
#define DLL_READER

#include<string>
#include<map>

class read_plugin {
public:
	read_plugin();
	double process_expression(std::string str, double num);
	bool is_in_plugins(std::string str);
private:
	std::string path = "D:\\5 семестр матмех\\наука программирования\\Calculator_lab1\\plugins\\";
	std::map<std::string, double(*)(double)> plugins;

};

#endif 