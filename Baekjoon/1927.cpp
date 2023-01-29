#include <iostream>
using namespace std;
int cnt;
int arr[100001];

void heap_min_insert(int a){
    int i;
    i = ++cnt;
    while(i!=1 && a < arr[i/2]){
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = a;
}

int heap_min_delete(){
    int item = arr[1];
    int temp = arr[cnt--];
    int parent = 1, child = 2;
    while(child <= cnt){
        if(arr[child] > arr[child+1])
            child++;
        if(arr[child] >= temp)
            break;
        arr[parent] = arr[child];
        parent = child;
        child *= 2;
    }
    arr[parent] = temp;

    return item;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a!=0){
            heap_min_insert(a);
        }
        else{
            if(cnt == 0)
                cout << 0 << "\n";
            else{
                cout << heap_min_delete() << "\n";
            }
        }
    }
}