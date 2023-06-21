# Streaming-Algorithms-Uni
## Okiljon Dadakhonov 2110172
Streaming algorithms implementation in cpp
- [ ] Count-Min Sketch algorithm:
- In this code, I defined a CountMinSketch class that encapsulates the Count-Min Sketch data structure. The increment function is used to increment the frequency of an element, and the estimateFrequency function      estimates the frequency of an element based on the counters in the sketch.To run this code, you'll need to have a C++ compiler installed on your system. Simply copy the code into a .cpp file, compile it, and run the resulting executable.
----
- [ ]  Space Saving algorithm
- In this code, I defined a SpaceSaving class that maintains a set of counters and a list of frequent elements. The process function processes elements in the data stream and updates the counters accordingly. If a new element exceeds the capacity of the counters, the least frequent element is replaced. The printFrequentElements function prints the most frequent elements along with their frequencies.

----
- [ ] Lossy Counting algorithm
- In this code, I defined a LossyCounting class that maintains a set of counters for elements in the data stream. The process function processes elements and updates the counters. When the sliding window reaches its predefined size, the pruneCounters function removes elements from the counters that are unlikely to exceed the maximum error threshold. The estimateFrequency function provides an estimate of the frequency of an element based on the counters.
