/**
 * Ds
 */
public class Ds {

	int[] arr;
	int p;
	Ds(){
		arr = new int[1];
		p=0;
	}
	public void add(int data) {
		if(arr.length>p+1){
			arr[p]=data;
			++p;
		}
		else {
			int[] newarr = new int[p*2];
			System.arraycopy(arr, 0, newarr, 0, arr.length);
			arr = newarr;
		}
	}
	public void display() {
		for (int i : arr) {
			System.out.print(i); System.out.println(" ");
		}
		System.out.println("");
	}
}
