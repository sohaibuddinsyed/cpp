#include <iostream>
#include <optional>
#include <fstream>
#include <sstream>
using namespace std;

/*
In C++, std::stringstream is a class template in the <sstream> header that allows you to treat 
strings as streams, allowing you to perform input and output operations as if they were being 
performed on a stream (like std::cin or std::cout).

std::stringstream buffer;: This line declares an object named buffer of type std::stringstream. 
It creates an empty stringstream object, ready to be used as an input or output stream.
fs.rdbuf(): Here, fs is presumably an object of type std::fstream, std::ifstream, or similar. 
fs.rdbuf() returns a pointer to the underlying std::streambuf object associated with the file 
stream fs. The std::streambuf represents the buffer associated with the stream.
buffer << fs.rdbuf();: This line uses the insertion operator << to insert the content of the file 
stream's buffer (fs.rdbuf()) into the buffer stringstream. The insertion operator << is overloaded 
for std::stringstream to allow insertion of various data types and stream manipulators.
After executing these lines, the buffer stringstream will contain a copy of the contents of the file 
stream fs. This can be useful for various tasks, such as reading data from a file into a string, 
parsing input from a string, or manipulating text data in memory.
*/

optional<string> read_file_as_str(const string &path) {
    ifstream fs(path);
    if(fs) {
        stringstream buffer;
        buffer << fs.rdbuf();
        string op = buffer.str();
        fs.close();
        return op;
    }
    return {};
}
int main() {
    optional<string> file =  read_file_as_str("hello.txt");
    if(file) {
        cout << file.value() << endl;
    }

    optional<string> file2 = read_file_as_str("hello2.txt");
    // Use a default value instead
    string data = file2.value_or("None");
    cout << data << endl;
    return 0;
}