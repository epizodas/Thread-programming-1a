#include <string>
#include <sstream>

class Object {
public:
    std::string name;
    int value;
    double score;

    Object(const std::string& n, int v, double s)
        : name(n), value(v), score(s) {}

    std::string to_string() const {
        std::ostringstream oss;
        oss << "Object(name: " << name << ", value: " << value << ", score: " << score << ")";
        return oss.str();
    }
};