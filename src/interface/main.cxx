#include <iostream>
#include <json-analyzer.hxx>
#include <json-file.hxx>
#include <filesystem>

namespace fs = std::filesystem;
using Path = fs::path;
using namespace JT;


int main() {
    Path json_file_path = "D:\\J-Tool\\test\\pseudo-data\\json-file-test-data.json";

    JsonFile json_file(json_file_path);
    json_file.read();

    JsonAnalyzer analyzer(json_file.toBuffer());

    std::cout << "\n\n";
    analyzer.analyze();
    std::cout << "\n\n";
    return 0;
}
