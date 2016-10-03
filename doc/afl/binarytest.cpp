#include <iostream>
#include <sstream>

using namespace std;

struct parameters {
  int cycles;
  int seed;
  char randtype;
};

int main(int argc, char** argv) {
  if (argc != 2)
    {
      cout << "FEL PARAMETRAR!" << endl;
      return 1;
    }

  char buffer[1000];
  stringstream ss;
  
  ss << argv[1];
  ss >> buffer;
  //ifstream inputfile (argv[1], ios::in | ios::binary);

  parameters params;
  params = *((parameters*)buffer);
  ofstream outputfile ("outputfile.txt", ios_base::app);
  
  while ( __AFL_LOOP(10) ) {
    outputfile << "CYCLES: " << params.cycles << endl << "SEED: " << params.seed << endl << "RANDTYPE: " << (int)params.randtype << endl;
  }
  outputfile.close();
  cout << buffer << endl;
  
  return 0;
}
