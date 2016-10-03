#include <iostream>
#include <fstream>

using namespace std;

struct parameters {
  int cycles;
  int seed;
  char randtype;
};

void printParam(const struct parameters &params, ofstream &outputfile) {
  outputfile << "CYCLES: " << params.cycles << endl << "SEED: " << params.seed << endl << "RANDTYPE: " << (int)params.randtype << endl;
}

int main(int argc, char** argv) {
  ofstream outputfile ("outputfile.txt", ios_base::app);
  
  while ( __AFL_LOOP(100000) ) {
    string buffer;
    cin >> buffer;

    parameters params;
    params = *((parameters*)buffer.c_str());

    printParam(params, outputfile);
  }

  outputfile.close();
  
  return 0;
}
