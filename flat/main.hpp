#ifndef MAIN_HPP
#define MAIN_HPP

#include "testingenvironment.hpp"
#include "portenvironment.hpp"
#include "app_main.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

enum {
    RANDOM_GENERATOR = 0,
    STATIC_GENERATOR = 1,
};

map<string, map<string, vector<vector<int>>>> namespaces;

static void readConfig() {
    ifstream config;
    config.open("flat/config.txt");

    if (!config.is_open() || config.fail()) {
	return;
    }

    stringstream ss;
    string line;

    while(std::getline(config, line))
    {
	ss << line;
    }

    string ns, var;
    int min_cycles, max_cycles, val;

    while(!ss.bad() && !ss.eof()) {
	ss >> ns;
	ss >> var;
	ss >> min_cycles;
	ss >> max_cycles;
	ss >> val;

	vector<int> vec = {min_cycles, max_cycles, val};
	namespaces[ns][var].push_back(vec);
    }
    /*
      for (auto it : namespaces) {
      std::cout << it.first << " contains: " << std::endl;
      for (auto iter : it.second) {
      std::cout << iter.first << " =>";
      for (auto vec : iter.second) {
      std::cout << " {";
      for (auto i : vec) {
      std::cout << " " << i; 
      } 
      std::cout << "}";
      }
      std::cout << std::endl;
      }
      std::cout << std::endl;
      }*/
    
    
    config.close();
}

static const map<string, map<string, vector<vector<int>>>> &getConfig() {
    return namespaces;
}

#endif // MAIN_HPP
