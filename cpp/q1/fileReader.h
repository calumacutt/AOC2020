#include <fstream>
#include <vector>

using namespace std;

class FileReader {
    public:
        void openFile(string fileName);
        vector<int> readAsInts();

    private:
        ifstream inFile;
};