#include <vector>
#include <iostream>

using namespace std;

int Cal2X(int x) {
    int sum = 1; // 2^0부터 시작
    for (int i = 0; i < x; i++) {
        sum *= 2;
    }
    return sum;
}

void Convert10To2(int Num, int arr[], int &size) {
    size = 0; // 크기 초기화
    while (Num > 0) {
        arr[size] = Num % 2;
        Num /= 2;
        size++;
    }
}

int Convert2To10(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i] * Cal2X(size - i - 1);
    }
    return sum; // 계산된 값을 반환
}

int CalLen(int Num) {
    int i = 0;
    while (Num > 0) {
        Num /= 2;
        i++;
    }
    return i; // 비트 수 반환
}

void reverse(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int getcount(int arr[],int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]==1)
            count++;
    }
    return count;
}
int solution(int n) {
            int size = CalLen(n);
            int *arr = new int[size]; // 동적 배열 할당
            Convert10To2(n, arr, size);
            reverse(arr, size);

    
    int targetcount=getcount(arr,size);
    while(1)
    {        
          n++;
        Convert10To2(n, arr, size);
            reverse(arr, size);

        
            if(targetcount==getcount(arr,size))
            {
                break;    
            }
        
          
        
    }
    
    int answer = Convert2To10(arr, size);
    delete[] arr;
     // 동적 메모리 해제
    return answer;
}


