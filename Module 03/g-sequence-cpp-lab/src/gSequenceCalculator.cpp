#include <iostream>
#include <vector>

int naiveGSequence(int n) {
    if (n == 0) {
        return 0;
    }

    return n - naiveGSequence(naiveGSequence(n - 1));

}

int optimizedGSequence(int n, std::vector<int>& hist) {
    if (n <= 0) {
        return 0;
    }

    if (n >= hist.size()) {
    hist.resize(n + 1, -1);
    }

    if (hist[n] != -1) {
        return hist[n];
    }
    
    return hist[n] = n - optimizedGSequence(optimizedGSequence(n-1, hist), hist); 
 
}
