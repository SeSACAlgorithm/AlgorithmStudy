#include <iostream>
#include <cmath>

// 요소를 추가하는 함수
int* addElement(int* arr, int& size, int element) {
    // 새로운 배열 할당
    int* newArr = new int[size + 1];
    
    // 기존 배열의 요소 복사
    for(int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    
    // 새로운 요소 추가
    newArr[size] = element;
    
    // 기존 배열 메모리 해제
    delete[] arr;
    
    // 배열 크기 증가
    ++size;
    
    return newArr;
}

int solution(int n) {
    int quotient = n;
    int size = 0;
    int* arr = new int[size];

    while (quotient >= 3) {
        arr = addElement(arr, size, quotient % 3);
        quotient /= 3;
    }
    arr = addElement(arr, size, quotient); // 마지막 몫을 추가

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i] * std::pow(3, size - 1 - i);
    }

    delete[] arr; // 동적 배열 메모리 해제
    
    return sum;
}

int main() {
    int n = 45;
    std::cout << "Converted value: " << solution(n) << std::endl;

    n = 125;
    std::cout << "Converted value: " << solution(n) << std::endl;

    return 0;
}
