#include "yaml-cpp/yaml.h"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace std;

void initData();

struct Map{
	int id;
	std::string name;
	std::string dir;
};

void initData(){
	YAML::Emitter out;
	out << YAML::BeginMap;
	out << YAML::Key << "maplist";
	out << YAML::Value
		<< YAML::BeginSeq
			<< YAML::BeginMap
				<< YAML::Key << "id" << YAML::Value << 1
				<< YAML::Key << "name" << YAML::Value <<"map1"
				<< YAML::Key << "dir" << YAML::Value << "~/map/map1.yaml" 
			<< YAML::EndMap
			<< YAML::BeginMap
				<< YAML::Key << "id" << YAML::Value << 2
				<< YAML::Key << "name" << YAML::Value <<"map2"
				<< YAML::Key << "dir" << YAML::Value << "~/map/map2.yaml" 
			<< YAML::EndMap
		<< YAML::EndSeq;
	out << YAML::Key << "count";
	out << YAML::Value << 2;
	out << YAML::EndMap;
	
	YAML::Node node = YAML::Load(out.c_str());

	//把内容写入文件
	std::ofstream fout("test.yaml");	
	fout << node;
}

int main(){
	//初始化数据
	initData();

	//载入数据
	YAML::Node doc = YAML::LoadFile("test.yaml");
	
	std::cout << "CONTENT:"<< endl << YAML::Dump(doc) << endl;

	//test
	std::cout << endl << "---------------test start :" << endl;
	int count =  doc["count"].as<int>();
	std::cout<< "map_count :" << count <<endl;
	if(count > 0){
		std::cout<<"map_id:" << doc["maplist"][0]["id"].as<int>() << endl;
	}
	std::cout << "---------------test end" << endl;

	//delete one note
	if(doc["maplist"].IsSequence()){
		std::cout << "is sequence " << endl;
		doc["maplist"].remove(0);	
		doc["count"] = doc["maplist"].size();
	}

	std::ofstream fout("result.yaml");
	fout << doc;
	
	return 0;
}
