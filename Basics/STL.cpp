#include<bits/stdc++.h>
using namespace std;
void pairs(){
    pair<int,int> p={2,3};
    cout<<p.first<<p.second;
    pair<int,pair<int,int>> q ={4,{5,6}};
    cout<<q.first<<q.second.second;
    pair<int,int> arr[] ={{3,4},{6,7},{7,8}};
    cout<<arr[1].second;
}
void vectors(){
    vector<int> v;      //now this creates an empty array
    v.push_back(1);     //this pushes an element 1 into array v
    v.emplace_back(2);      //this also does the same work as push_back but it is much more faster
    vector<pair<int,int>> vec ;
    vec.push_back({1,2});
    vec.emplace_back(1,2);      //There is a diffrence in the arrangement no curly braces required
    vector<int> v1(5,100);      //creates an instance samthg like this {100,100,100,100,100}
    vector<int> v2(5);      //Creates like{0,0,0,0,0}       or some garbage value is stored inside this....even though i have specified the size it should take values as it is dynamic and increase size upon input
    vector<int> v3(v1);     //This creates a copy of v1 into v3
    vector<int>::iterator it = v.begin();       //Here v.begin() poiints to the first elements memory address location
    it++;       //this wqill point to the next element of array
    cout<<*(it);        //the *(it) will gave the value stored in the memory address loaction 
    //Similarly there is v.end() this points to the element next to the last element of the array and the iteration goes like it-- basically ir iterates from the last element to the first element
    //Now to print the elements inthe vector
    for (auto it = v.begin(); it != v.end(); it++){     //here auto is equal to vector<int>::iterator....it basically detects that what kind of sata is being stored and automatically assigns the datatype
        cout << *it << " ";
    }
    //another way is using foreach to print vector element
    for(auto it : v){
        cout<<it;
    }
    //{10,12,19,13,12}
    v.erase(v.begin()+1,v.begin()+3);       //Prints{10,13,12}      [start,end)
    v.insert(v.begin(),300);        //inserts 300 in first position
    v.insert(v.begin()+1,2,400);        //inserts 400,400 at the 2nd position of vector
    //pop_back() - it deletes the last element and returns it to the calling function.
    v1.pop_back();
    //clear() - deletes all the elements from the vector.
    v1.clear();
    // empty() - to check if the vector is empty or not.
    v1.empty();
    // size() - returns the size of the vector
    v1.size();
}
void explainlist(){
    //similar to vector but provides alternative of inserting values which reduces time complexity
    list<int> ls;
    ls.push_front(5);       //inserts 5 at index 0
    ls.emplace_front(5);        
}
void explainstack(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.emplace(5);      //similar to push...here the elements are stored in lifo...it is stored in {5,4,3,2,1}
    cout<<st.top();     //returns 5 as it was the last element which enetered the stack
    st.pop();       // the stack will look like {4,3,2,1}
    cout<<st.size();        //obvio
    cout<<st.empty();       //obvio
}
void explainqueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(4);       //it's obvious now it forms {1,2,4}
    q.back() += 5;      //The 5 is added to last element which is 4 resulting in 9
    cout<< q.back();        //prints 9
    cout<< q.front();       //prints 1 
    q.pop();        //removes the first elment which is 1..resulting in {2,9}
}
void explainpq(){
    priority_queue<int> pq;     //the maximum value stays at the top...AKA Maximum heap
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.emplace(5);      //it is stored in {5,3,2,1}
    pq.top();       //returns 5
    pq.pop();       //removes 5 resulting in {3,2,1}
    //Minimum heap ...here the element with least value stays at the top
    priority_queue<int,vector<int>,greater<int>> pq;        //syntax for storing minimum heap
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.emplace(5);      //it is stored in {1,2,3,5}
    pq.top();       //returns 1
}
void explainset(){
    set<int> st;            //stores data in sorted and unique way
    st.insert(1);
    st.insert(2);
    st.insert(2);       //won't store it as it already exists (unique)
    st.insert(4);
    st.emplace(3);     // {1,2,3,4}     stores everything in sorted way
    auto it = st.find(3);       //this iterator will return memory adress of 3
    auto it = st.find(6);       //now this does not exist in set....so it always returns st.end()       
    st.erase(2);        //erases 2 from set
    st.count(2); //returns true
}
int main(){
  pairs();
   return 0;
}