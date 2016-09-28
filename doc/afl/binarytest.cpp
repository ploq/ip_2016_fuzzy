#include <iostream>
#include <fstream>

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
  ifstream inputfile (argv[1], ios::in | ios::binary);

  if (!inputfile)
    {
      cout << "FEL" << endl;
      return 1;
    }
  
  parameters params;
  inputfile.read(buffer, 1000);
  params = *((parameters*)buffer);

  ofstream outputfile ("outputfile.txt", ios_base::app);
  //string str (buffer);
  outputfile << "CYCLES: " << params.cycles << endl << "SEED: " << params.seed << endl << "RANDTYPE: " << (int)params.randtype << endl;
  outputfile.close();

  cout << buffer << endl;

  inputfile.close();
  
  return 0;
}
