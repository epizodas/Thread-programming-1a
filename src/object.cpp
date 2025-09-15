#include <string>
#include <sstream>

class Object {
public:
    Object() : name(""), quantity(0), price(0.0) {} 
    Object(const std::string& n, int q, double p) : name(n), quantity(q), price(p) {}

    std::string to_string() const {
        std::ostringstream oss;
        oss << "name: " << name << ", quantity: " << quantity << ", price: " << price << ")";
        return oss.str();
    }
private:
    std::string name;
    int quantity;
    double price;
};