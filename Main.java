public class Main {
	public static void main(String[] args) {
		Vector list = new Vector();
		list.display();
		list.pb(1);
		list.display();
		list.pb(2);
		list.display();
		list.pb(3);
		list.display();
		list.pb(4);
		list.display();

	}
}
class Vector {
	int[] arr;
	int p;
	Vector(){
		arr = new int[1];
		p=0;
	}
	public void pb(int data) {
		if(arr.length>p){
			arr[p]=data;
			++p;
		}
		else {
			int[] newarr = new int[p*2];
			for (int i = 0; i < arr.length; i++)
				newarr[i]=arr[i];
			arr = newarr;
			arr[p]=data; ++p;
		}
	}
	
	public void display() {
		if(p!=0){
			for (int i=0;i<p;++i) {
				System.out.print(arr[i]); System.out.print(" ");
			}
			System.out.println("");
		}
	}
}
