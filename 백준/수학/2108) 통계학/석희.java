import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/* 문제 분석.
 *  중앙값을 찾기 위해 정렬이 필요
 *  최빈값 찾기 위해 몇번 나왔는지 확인 필요 (Hash Map 사용? -> value 기준으로 정렬)
 *
 */

/* 출력.
 *  산술평균 : sum / N (첫째 자리에서 반올림)
 *  중앙값
 *  최빈값 : N개의 수들 중 가장 많이 나타나는 값 (여러 개라면 두번째로 작은 값)
 *  범위 : 최댓값 - 최솟값
 */

//  public class Main {
public class 석희 {

    static int N;       // 1~ 500,000
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        HashMap<Integer, Integer> numberCount = new HashMap<Integer, Integer>();
        int[] numbers = new int[N];

        double sum = 0;
        int maxCount = 0;
        int maxNum = -4001;
        int minNum = 4001;
        for(int i = 0; i < N; i++)
        {
            int num = Integer.parseInt(bf.readLine());
            if(numberCount.containsKey(num)) numberCount.put(num, numberCount.get(num) + 1);
            else numberCount.put(num, 1);

            sum += num;
            maxNum = Math.max(maxNum, num);
            minNum = Math.min(minNum, num);

            maxCount = Math.max(maxCount, numberCount.get(num));

            numbers[i] = num;
        }

        // 산술 평균
        System.out.println(Math.round(sum / N));

        // 중앙값
        Arrays.sort(numbers);
        System.out.println(numbers[N / 2]);

        // 최빈값
        ArrayList<Integer> maxNums = new ArrayList<>();
        for(Map.Entry<Integer, Integer> newMap : numberCount.entrySet()) {
            if(newMap.getValue() == maxCount) maxNums.add(newMap.getKey());
        }

        Collections.sort(maxNums);
        if(maxNums.size() > 1) System.out.println(maxNums.get(1));
        else System.out.println(maxNums.get(0));

        // 범위
        System.out.println(maxNum - minNum);
    }
}
