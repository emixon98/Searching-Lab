#include <iostream>
#include <vector>
#include <random>
using namespace std;

static const int N = 100000;

//linear is straight forward, using & so I can return comparisons in main
//O(n) because it has to compare each element to the search, meaning it is at worst O(n), with n being the length of the array
int linear_Search(int arr[], int n, int search, double& comparisons){
    comparisons = 0;
    for (int i = 0; i < n; i++){
        comparisons++;
        if(arr[i] == search) return i;
    }
    return -1;
}

//int logbase2(n), worst case has to splice the array into halves as many times as possible to find last remaining element
//can show with calculator
int binary_Search(int arr[], int n, int search, int& comparisons){
    comparisons = 0;
    int low = 0, high = n-1; //setting initial indexes for search

    while (low <= high){
        int mid = low + (high - low) / 2; //consistent middle
        comparisons++;
        if (arr[mid] == search) return mid;

        //comparisons++; 
        //this is technically a comparison, so could increment here
        
        if(search < arr[mid])
            high = mid -1;
        else 
            low = mid +1;
    }
    return -1;
}

int rand_Search(const vector<int>& vec, int key, double& comparisons){

    int n = vec.size();
    int remaining = n;
    comparisons = 0;    
    
    vector<bool> visited(n, false);

    mt19937 gen;
    uniform_int_distribution<int> rand(0, n - 1);

    while (remaining > 0) {
        int i = rand(gen);

        if(!visited[i]){
            visited[i] = true;
            remaining--;
            comparisons++;
            if(vec[i] == key) return i;
        }
    }
    return -1;
}


int main() {
    int testArr[N];

    //binary needs sorted, so going to just match element to it's index
    for(int i=0; i < N; i++) testArr[i] = i;

    int testVal;
    cout << "Enter a whole number between 0 - 99999 to search for: ";
    cin >> testVal;

    double linearComparisons = 0;
    int binaryComparisons = 0;
    //call our functions now
    int linearIndex = linear_Search(testArr, N, testVal, linearComparisons);
    int binIndex = binary_Search(testArr, N, testVal, binaryComparisons);

    cout << "The test value was found at index = " << linearIndex << ", and took " << linearComparisons << 
    " comparisons using the linear search algorithm.\n" ;

    cout << "The test value was found at index = " << binIndex << ", and took " << binaryComparisons << 
    " comparisons using the binary search algorithm.\n" ;

//task 5 

    vector<int> randVec(N);
    for(int i = 0; i < N; i++) randVec[i] = i;

    int key;
    cout << "Enter key value to search for (0 - 99999): ";
    cin >> key;

    double randomComparisons = 0;
    int randIndex = rand_Search(randVec, key, randomComparisons);

    if (randIndex != -1) cout << "Index found at " << randIndex << endl;
    else cout << "Unsuccessful." << endl;

    cout << "Total comparisons using the random search algorithm " << randomComparisons << endl;

    return 0;
}