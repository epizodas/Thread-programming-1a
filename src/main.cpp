#include <iostream>
#include <fstream>
#include "json.hpp"
#include "object.cpp"
#include <vector>

using namespace std;
using json = nlohmann::json;

int main(){
    std::ifstream file("data/data1.json");
    json data = json::parse(file);
    std::vector<Object> objects;
    for (const auto& item : data) {
        std::string name = item["name"];
        int value = item["value"];
        double score = item["score"];
        objects.emplace_back(name, value, score);
    }
    cout << "Loaded " << objects.size() << " objects." << endl;
    cout << objects.at(0).to_string() << endl;
    return 0;
}
