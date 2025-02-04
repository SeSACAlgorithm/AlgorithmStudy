import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        HashMap<String, Double> standard = new HashMap<String, Double>();
        String[] grades = new String[]{"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F", "P"};
        double[] scores = {4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0, 0.0};

        for(int i = 0; i < grades.length; i++){
            standard.put(grades[i], scores[i]);
        }

        double total = 0.0;
        double total_score = 0.0;
        for(int i = 0; i < 20; i++) {
            String subject = sc.next();
            Double score = sc.nextDouble();
            String grade = sc.next();

            if(grade.equals("P")) continue;

            total = total + (score * standard.get(grade));
            total_score += score;
        }

        System.out.println(total / total_score);
    }
}
