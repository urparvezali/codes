import java.util.*;
import java.lang.*;
import java.io.*;

public class D_Mathematical_Problem {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner scanner = new Scanner(System.in);
        
        int TT = scanner.nextInt();
        
        Map<String, Integer> frequencyMap = new HashMap<>();
        
        for (int i = 1; i <= 99999; i++) {
            String s = String.valueOf(i * i);
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            
            if (chars[0] == '0') continue;
            
            String sortedString = new String(chars);
            frequencyMap.put(sortedString, frequencyMap.getOrDefault(sortedString, 0) + 1);
        }
        
        for (int T = 1; T <= TT; T++) {
            solution(scanner, frequencyMap);
        }
        
        scanner.close();
    }
    
    public static void solution(Scanner scanner, Map<String, Integer> frequencyMap) {
        int n = scanner.nextInt();
        
        for (Map.Entry<String, Integer> entry : frequencyMap.entrySet()) {
            String key = entry.getKey();
            int value = entry.getValue();
            
            if (value >= n) {
                char[] chars = key.toCharArray();
                do {
                    String permutedString = new String(chars);
                    int num = Integer.parseInt(permutedString);
                    if (Math.sqrt(num) == Math.ceil(Math.sqrt(num))) {
                        System.out.println(permutedString);
                        n--;
                        if (n == 0) return;
                    }
                } while (nextPermutation(chars));
            }
        }
    }
    
    public static boolean nextPermutation(char[] chars) {
        int i = chars.length - 2;
        while (i >= 0 && chars[i] >= chars[i + 1]) {
            i--;
        }
        
        if (i < 0) return false;
        
        int j = chars.length - 1;
        while (chars[j] <= chars[i]) {
            j--;
        }
        
        swap(chars, i, j);
        
        reverse(chars, i + 1);
        
        return true;
    }
    
    public static void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
    
    public static void reverse(char[] chars, int start) {
        int i = start, j = chars.length - 1;
        while (i < j) {
            swap(chars, i, j);
            i++;
            j--;
        }
    }
}
