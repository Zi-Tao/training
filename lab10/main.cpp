#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class myString {
   private:
    string m_str;

   public:
    myString(string s) {
        m_str = s;
    }
};

class ReadClass {
   public:
    void showClass() {
        // ifstream file("main.cpp");  // 開啟程式碼檔案
        ifstream file(__FILE__);
        string line;
        int i = 0;
        vector<string> className;
        int count = 0;
        // int lastCount = 0; // 儲存最後一次的 count 數值
        while (getline(file, line)) {                                   // 逐行讀取程式碼
            size_t classPos = line.find("class ");                      // 尋找 class 關鍵字
            if (classPos != string::npos) {                             // 如果找到了 class 關鍵字
                size_t classNameStart = classPos + 6;                   // class 名稱起始位置
                size_t classNameEnd = line.find(" {", classNameStart);  // class 名稱結束位置
                if (classNameEnd != string::npos) {
                    // className = line.substr(classNameStart, classNameEnd - classNameStart); // 提取 class 名稱
                    className.push_back(line.substr(classNameStart, classNameEnd - classNameStart));
                    count++;
                }
            }
        }
        cout << count << " class in " << __FILE__ << endl;
        for (int i = 0; i < count; i++) {
            cout << "class " << className[i] << endl;
        }
        file.close();  // 關閉檔案
    }
};

int main() {
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
