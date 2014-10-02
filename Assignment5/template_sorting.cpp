#import <vector>
#import <iostream>
#import <set>
using namespace std;

template <typename T>
    void Swap(T & one, T & two) {
        T tmp = one;
        one = two;
        two = tmp;
    }

template <typename T>
    int OperatorCmp(T one, T two) {
        if (one == two) return 0;
        else{
            if (one < two) return -1;
            else return 1;
        }
    }

template <typename T>
    void Sort(vector<T> & vec, int (cmp)(T, T) = OperatorCmp) {
        for (int i = 0; i < vec.size() - 1; i++){
            int minIndex =  i;
            for(int j = i+1; j < vec.size(); j++){
                if (vec.at(j) < vec.at(minIndex)){
                    minIndex = j;
                }
            }
            Swap(vec.at(i), vec.at(minIndex));
        }
    }

int CmpSet(set<int> a, set<int> b) {
    int sumA;
    int sumB;
    for (set<int>::iterator it=a.begin(); it!=a.end(); ++it){
        sumA += *it;
    }
    for (set<int>::iterator it=b.begin(); it!=b.end(); ++it){
        sumB += *it;
    }
    if (sumA < sumB) return 1;
    else if (sumA > sumB) return -1;
    return 0;
}


int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(4);
    vec.push_back(-3);

    Sort(vec);
    for(int k = 0; k < vec.size(); k++){
        cout << vec.at(k) << endl;
    }

    vector<set<int> > setIntegers;
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    setIntegers.push_back(mySet);
    mySet.clear();
    mySet.insert(2);
    mySet.insert(8);
    setIntegers.push_back(mySet);
    mySet.clear();
    mySet.insert(4);
    mySet.insert(2);
    setIntegers.push_back(mySet);
    mySet.clear();
    mySet.insert(1);
    mySet.insert(1);
    mySet.insert(1);
    setIntegers.push_back(mySet);
    mySet.clear();

    Sort(setIntegers, CmpSet);
    for(int k = 0; k < setIntegers.size(); k++){
        for (set<int>::iterator it=setIntegers.at(k).begin(); it!=setIntegers.at(k).end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}

