
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    //왼손 위치, 오른손 위치 (x,y)좌표로
    pair<int,int> leftPos, rightPos;

    //숫자 판 정의 1번은 (0,0), 2번은 (0,1) ... 등등
    //숫자 판의 1은, numPad의 0 번째, 숫자 판의 2는, numPad의 1번째 임을 꼭 확인!
    pair<int,int> numPad[13] = {
            {0,0},{0,1}, {0,2},
            {1,0},{1,1}, {1,2},
            {2,0},{2,1}, {2,2},
            {3,0},{3,1}, {3,2}
    };

    //왼손, 오른손 초기 위치 설정
    leftPos = {3,0}; // *
    rightPos = {3,2}; // #


    //입력 받은 숫자 하나씩 검토
    for(int i=0;i<numbers.size();i++) {
        //1, 4, 7 이면 왼손으로 누르고 왼손 포지션 변경
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            leftPos = numPad[numbers[i]-1];
        } //3, 6, 9 이면 오른손으로 누르고 오른손 포지션 변경
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            rightPos = numPad[numbers[i]-1];
        }
        else if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
            //0 번은 예외적으로 11로
            if(numbers[i] == 0) {
                numbers[i] = 11;
            }
            //거리 계산시 x좌표의 차이의 절대값 + y좌표의 차이의 절대값
            int leftDistance =abs(numPad[numbers[i]-1].first - leftPos.first) + abs(numPad[numbers[i]-1].second - leftPos.second);
            int rightDistance = abs(numPad[numbers[i]-1].first - rightPos.first) + abs(numPad[numbers[i]-1].second - rightPos.second);

            //왼손이 가까우면
            if(leftDistance < rightDistance) {
                answer += "L";
                leftPos = numPad[numbers[i]-1];
            }//오른손이 가까우면
            else if(leftDistance > rightDistance) {
                answer += "R";
                rightPos = numPad[numbers[i]-1];
            }//거리가 같으면 왼손 잡이인지, 오른손 잡이인지 판별
            else {
                if(hand =="right") {
                    answer += "R";
                    rightPos = numPad[numbers[i]-1];
                } else {
                    answer += "L";
                    leftPos = numPad[numbers[i]-1];
                }
            }
        }
    }

    return answer;
}
