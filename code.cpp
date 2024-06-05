


void dictionary::heapsort() {
    heap max_heap;
    
    // Insert all words into the heap
    for (const auto& word : words) {
        max_heap.insert(word);
    }
    
    // Build the max heap
    max_heap.buildMaxHeap();
    
    // Extract the maximum element from the heap and place it in the array
    for (int i = words.size() - 1; i >= 0; i--) {
        words[i] = max_heap.extractMax();
    }
}

