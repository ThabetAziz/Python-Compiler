#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <iostream>
#include <sstream>

int getNumberTabs(const std::string line) {
    int countTab = 0;
    while (countTab < line.size() and line[countTab] == '\t') {
        countTab++;
    }
    return countTab;
}

std::vector<std::string> readFileToVector(const std::string& filename)
{
    std::ifstream source;
    source.exceptions(std::ifstream::failbit);
    try {
        source.open(filename);
    }
    catch (const std::exception& e) {
        std::cerr << "can't open file '" << filename << "': [Errno 2] No such file or directory";
        //throw ("can't open file '" + filename + "': [Errno 2] No such file or directory");
    }
    std::vector<std::string> lines;
    std::string line;
    while (!source.eof())
    {
        std::getline(source, line);
        lines.push_back(line);
    }
    source.close();
    return lines;
}

void displayVector(const std::vector<std::string> v)
{
    for (int i(0); i != v.size(); ++i) {
        std::cout << "\nNumber of Tabs : " << getNumberTabs(v[i]);
        std::cout << "\n" << v[i];
    }
}

int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cerr << "No arguments provided. Please specify your runnable" << "\n";
    }
    else {
        std::string filename(argv[1]);
        std::vector<std::string> vectorFileContent = readFileToVector(filename);
        displayVector(vectorFileContent);
    }

    return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
