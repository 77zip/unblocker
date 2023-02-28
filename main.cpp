#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

std::vector<char> toSearch{'D','O','S'};
std::vector<char> newData{'D','A','S'};

int main(int argc, char* argv[]) {
    std::string filename = argv[1];
    if (std::ifstream ifs{ filename, std::ios::binary }; ifs) {
        std::vector<char> data(std::istreambuf_iterator<char>(ifs), {});
        ifs.close();
        auto position = std::search(data.begin(), data.end(), toSearch.begin(), toSearch.end());
        if (position != data.end()) {
            std::copy(newData.begin(), newData.end(), position);
            if (std::ofstream ofs{ filename.substr(0, filename.size()-4) + "-patched.exe", std::ios::binary }; ofs) {
                std::copy(data.begin(), data.end(), std::ostreambuf_iterator<char>(ofs));
            }
        }
    }
    return 0;
}
