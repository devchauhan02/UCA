#include<bits/stdc++.h>
using namespace std;


bool isPossible(vector<int> &population, int n, int mid, int m){
    int ans = 0;
    for(int i = 0; i < n ; i++){
        ans += ceil(double(population[i])/mid);
    }
    return ans <= m;
}


int minimizeMaxLoad(vector<int> &population, int n, int m){
    int low = 1;
    int high = *max_element(population.begin(),population.end());
    int result = 0;
    while(low <= high){
        int mid = (low + high) / 2;
        if(isPossible(population,n,mid,m)){
            result = mid;
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }
    return result;
}

int main() {
    int n = 3;
    vector<int> population = {100, 50, 200};
    int m = 4;

    int result = minimizeMaxLoad(population, n, m);
    cout <<  result << endl;
    
    return 0;
}
