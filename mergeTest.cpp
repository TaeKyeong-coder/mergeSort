#include <iostream>
using namespace std;

const int SIZE = 8;

void merge_sort(int num[],int low ,int high);

void merge(int num[],int low,int mid,int high);
void print(int num[]);      


int main(void)

{
	
	for(int i =0; i<8; i++) {
		int n2;
		cin>>n2;
		num[i] = n2;
	}

        cout << "정렬하기 전" <<endl;
        cout << num[8] << endl;
        merge_sort(num, 0, SIZE - 1);  
        cout << endl << "정렬한 후" << endl;
        cout << num[8];
        return 0;

}

void merge_sort(int num[], int low, int high)

{
        int mid;
        if(low < high){
                mid = (low + high)/2;
                merge_sort(num, low, mid);
                merge_sort(num, mid+1, high);
                merge(num, low, mid, high);

        }

}

 

void merge(int num[], int low, int mid, int high)
{
        int result[SIZE];
        int i, j, k;
        int m;

        i = low;   
        j = mid + 1;
        k = low;  

        while (i <= mid && j <= high) {  
            if (num[i] < num[j]){
                result[k] = num[i];
                i++;
                k++;
            }
            
            else{
                result[k] = num[j];
                j++;
                k++;
            }
        }

        if (i > mid){
            for (m = j; m <= high; m++){
                result[k] = num[m];    
                k++;
            }
        }

        else {
                for (m = i; m <= mid; m++){
                        result[k] = num[m];
                        k++;
                }
        }

        for (m = low; m <= high; m++)
                        num[m] = result[m];

  for (int p = 0 ; p < SIZE ; p++)
                cout << num[p] << " ";
        cout << endl;

}

void print(int num[])
{
    int i;
    
    for (i = 0 ; i < SIZE ; i++)
        cout << num[i] << " ";
    cout << endl;
}

