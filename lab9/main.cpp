#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class ReplaceMyString {
   public:
    ReplaceMyString() {}

    void replaceString(string a, string b) {
        ifstream inputFile(__FILE__);
        ofstream outputFile("rmain.cpp");
        if (inputFile.is_open() && outputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                size_t pos = line.find(a);
                while (pos != string::npos) {
                    line.replace(pos, a.length(), b);
                    pos = line.find(a, pos + b.length());
                }
                outputFile << line << endl;
            }
            inputFile.close();
            outputFile.close();
            cout << "成功\n";
        } else {
            cout << "無法開啟檔案\n";
        }
    }
};

int main() {
    ReplaceMyString my;
    my.replaceString("IU", "IU is best");
    return 0;
}
