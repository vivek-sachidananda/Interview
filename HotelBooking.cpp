
/**
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.
Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

**/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    unordered_map<int, int> aHashCount;
    size_t aArriveSize = arrive.size();
    size_t aDepartSize = depart.size();
    
    if (aArriveSize != aDepartSize)
        return false;
    
    for (size_t i = 0; i < aArriveSize; ++i)
    {
        for (size_t aDays = arrive[i]; aDays <= depart[i]; ++aDays)
        {
            ++aHashCount[aDays];
         
            if (aHashCount[aDays] > K)
                return false;
        }
        
        --aHashCount[depart[i]];
    }
    
    return true;
}


// Fastest

/*bool comp(pair<int, int> j, pair<int, int> i){
    cout<<"i="<<i.first<<" "<<i.second<<"j="<<j.first<<" "<<j.second<<endl;
    if(i.first > j.first){
        return true;
    }
    else if(i.first == j.first){
        if(i.second > j.second){
            return true;
        }
    }
    return false;
}*/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
     
    int arr = 0;
    int dep = 0;
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    while(arr < arrive.size()){
        K--;
        arr++;
        if(K == 0){
            if(arrive[arr] >= depart[dep]){
                K++;
                dep++;
            }    
        }
        if(K < 0){
            return false;
        }
    }
        
    return true;
}
