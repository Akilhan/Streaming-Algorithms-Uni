#include <iostream>
#include <vector>
#include <cstring>

class CountMinSketch {
private:
    int d;
    int w; // Number of counters per hash function
    std::vector<std::vector<int>> sketch; 

public:
    CountMinSketch(int d, int w) : d(d), w(w) {
        sketch.resize(d, std::vector<int>(w, 0));
    }

    void increment(const std::string& element) {
        for (int i = 0; i < d; ++i) {
            int hashValue = hash(element, i);
            sketch[i][hashValue] += 1;
        }
    }

    int estimateFrequency(const std::string& element) {
        int minCount = INT_MAX;
        for (int i = 0; i < d; ++i) {
            int hashValue = hash(element, i);
            minCount = std::min(minCount, sketch[i][hashValue]);
        }
        return minCount;
    }

private:
    int hash(const std::string& element, int index) {
        unsigned long long hashValue = 5381;
        const char* str = element.c_str();
        while (*str) {
            hashValue = ((hashValue << 5) + hashValue) + *str;
            ++str;
        }
        return (hashValue + index) % w;
    }
};

int main() {
    CountMinSketch sketch(4, 8); 

    
    sketch.increment("apple");
    sketch.increment("banana");
    sketch.increment("apple");
    sketch.increment("cherry");
    sketch.increment("banana");

   
    std::cout << "Estimated frequency of 'apple': " << sketch.estimateFrequency("apple") << std::endl;
    std::cout << "Estimated frequency of 'banana': " << sketch.estimateFrequency("banana") << std::endl;
    std::cout << "Estimated frequency of 'cherry': " << sketch.estimateFrequency("cherry") << std::endl;

    return 0;
}
