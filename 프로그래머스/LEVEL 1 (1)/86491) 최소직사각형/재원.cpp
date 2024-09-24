#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.

//마치 진짜 명함을  정리할때 처럼 실행 1. 명함을 비슷한모양으로 정리 2. 그 중에 가장 큰값 구하기 
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int max_width = 0;
    int max_height = 0;

    for (int i = 0; i < sizes_rows; i++) {
        int width = sizes[i][0];
        int height = sizes[i][1];

        // 명함의 가로와 세로 중 더 큰 값을 가로로, 작은 값을 세로로 정렬합니다.
        if (width < height) {
            int temp = width;
            width = height;
            height = temp;
        }

        // 가장 큰 가로와 세로를 구합니다.
        if (width > max_width) {
            max_width = width;
        }
        if (height > max_height) {
            max_height = height;
        }
    }

    // 결과적으로 가장 큰 가로와 세로 크기를 곱한 값을 반환합니다.
    return max_width * max_height;
}
