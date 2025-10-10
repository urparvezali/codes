package cds3;
import java.util.Scanner;

public class javafile {
	public static void main(String[] args) {
		for (int i = 0; i < 5; i++) { // i=1
			for (int j = 5-i; j > 0; j--) { // j=5-1=4
				System.out.print(" ");
			}
			for (int j = 0; j < i+1; j++) {
				System.out.print("* ");
			}
			System.out.println("");
		}
		Scanner sc = new Scanner(System.in);
		int fuchka = sc.nextInt();
		System.out.println(fuchka);
		sc.close();
	}
}
