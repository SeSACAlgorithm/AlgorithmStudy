int solution(int n) {
    int answer = 0;

    // k는 시작 숫자
    for (int k = 1; k < n; k++) {
        int sum = 0;
        for (int j = 0; sum < n; j++) {
            sum += (k + j); // k부터 시작하여 j만큼 더함
            if (sum == n) {
                answer++;
                break; // n을 찾으면 더 이상 더할 필요 없음
            }
        }
    }

    // n 자체도 1로 표현될 수 있으므로 추가
    return answer + 1; // 1부터 n까지의 합도 포함
}
