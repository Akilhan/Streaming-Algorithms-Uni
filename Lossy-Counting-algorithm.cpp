#include <iostream>
#include <unordered_map>
#include <cmath>

class LossyCounting {
private:
    int k; 
    int windowSize;
    int currentWindowCount;
    std::unordered_map<std::string, int> counters; 
public:
    LossyCounting(int k, int windowSize) : k(k), windowSize(windowSize), currentWindowCount(0) {}

    void process(const std::string& element) {
        ++currentWindowCount;

        if (counters.find(element) != counters.end()) {
           
            ++counters[element];
        } else {
          
            counters[element] = 1;
        }

       
        if (currentWindowCount % windowSize == 0) {
            pruneCounters();
        }
    }

    int estimateFrequency(const std::string& element) {
        if (counters.find(element) != counters.end()) {
            return counters[element];
        }
        return 0;
    }

private:
    void pruneCounters() {
        for (auto it = counters.begin(); it != counters.end();) {
            if (it->second <= currentWindowCount - k) {
                it = counters.erase(it);
            } else {
                ++it;
            }
        }
    }
};

int main() {
    LossyCounting lc(2, 5); 

    
    lc.process("apple");
    lc.process("banana");
    lc.process("apple");
    lc.process("cherry");
    lc.process("banana");
    lc.process("banana");

 
    std::cout << "Estimated frequency of 'apple': " << lc.estimateFrequency("apple") << std::endl;
    std::cout << "Estimated frequency of 'banana': " << lc.estimateFrequency("banana") << std::endl;
    std::cout << "Estimated frequency of 'cherry': " << lc.estimateFrequency("cherry") << std::endl;

    return 0;
}
