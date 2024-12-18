#include <fstream>

using namespace std;

int main() {
    std::string text = "eyJiYXNlNjRfdmFsdWUiOiJabWx5YlRJZ2MyVmpjbVYwSUd0bGVRPT0ifQo=";
    ofstream outfile("myfile.dat", ofstream::binary | ios::out);
    //outfile << text;
    outfile.write( text.c_str(), text.size());
    //outfile.write(&text,sizeof (string));//can take type
    //outfile.write(&text,sizeof (text));//can take variable name
    outfile.close();
}
