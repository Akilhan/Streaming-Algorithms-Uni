#include <iostream>
#include <unordered_map>
#include <list>

class SpaceSaving {
private:
    int k;
    std::unordered_map<std::string, int> counters;
    std::list<std::pair<std::string, int>> frequentElements; 

public:
    SpaceSaving(int k) : k(k) {}

    void process(const std::string& element) {
        if (counters.find(element) != counters.end()) {
            
            ++counters[element];
            updateElementPosition(element);
        } else if (counters.size() < k) {
            
            counters[element] = 1;
            frequentElements.push_front(std::make_pair(element, 1));
        } else {
            
            auto leastFrequent = frequentElements.back();
            counters.erase(leastFrequent.first);
            frequentElements.pop_back();
            counters[element] = leastFrequent.second + 1;
            frequentElements.push_front(std::make_pair(element, leastFrequent.second + 1));
        }
    }

    void printFrequentElements() const {
        std::cout << "Most frequent elements:" << std::endl;
        for (const auto& element : frequentElements) {
            std::cout << element.first << ": " << element.second << std::endl;
        }
    }

private:
    void updateElementPosition(const std::string& element) {
        for (auto it = frequentElements.begin(); it != frequentElements.end(); ++it) {
            if (it->first == element) {
                ++it->second;
                frequentElements.splice(frequentElements.begin(), frequentElements, it);
                break;
            }
        }
    }
};

int main() {
    SpaceSaving ss(3);
   
    ss.process("apple");
    ss.process("banana");
    ss.process("apple");
    ss.process("cherry");
    ss.process("banana");
    ss.process("banana");

    // Print the most frequent elements
    ss.printFrequentElements();

    return 0;
}
