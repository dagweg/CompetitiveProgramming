/*
* Complete the 'countSwaps' function below.
*
* The function accepts INTEGER_ARRAY a as parameter.
*/

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void countSwaps(vector<int> a) {
    int tswap = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(a[j] > a[j+1]){
                tswap++;
                swap(a[j], a[j+1]);
            }
        }
    }
    cout << "Array is sorted in " << tswap << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n-1] << endl;
    
}
