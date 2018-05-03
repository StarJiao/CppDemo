#include "yaml-cpp/yaml.h"
#include <iostream>

using namespace std;

int main()
{
	   YAML::Emitter out;
	   out << "Hello, World!";

	   std::cout << "Here's the output YAML:\n" << out.c_str() << endl;// prints "Hello, World!"
	   return 0;
}
