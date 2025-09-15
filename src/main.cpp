#include <iostream>
#include <fstream>
#include "../include/json.hpp"
#include <vector>
#include "data_monitor.cpp"

using namespace std;
using json = nlohmann::json;

int main(){
    std::ifstream file("data/data1.json");
    json data = json::parse(file);
    std::vector<Object> objects;
    for (const auto& item : data) {
        std::string name = item["name"];
        int quantity = item["quantity"];
        double price = item["price"];
        objects.emplace_back(name, quantity, price);
    }
    cout << "Loaded " << objects.size() << " objects." << endl;
    cout << objects.at(objects.size()-1).to_string() << endl;

    DataMonitor dm;
    for (const auto& o : objects){
        if(!dm.isFull()){
            dm.addItem(o);
        }
        else{
            for(int i = 0; i < 9; i++)
                cout << "removed ->" << dm.removeItem().to_string() << endl;
            dm.addItem(o);
            }
            dm.display();
        }
    return 0;
}
