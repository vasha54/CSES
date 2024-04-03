
/*
* CSES - Digit queries
* Tematica: Add-Hoc
* Idea Basica: Construyo un arreglo que me diga hasta el último número con i digitos cuantos 
* digitos he utilizado desde el 1 hasta ese numero que es el mayor con i digitos. Luego haciendo
* una busqueda buscaré cuantos digitos tiene el numero donde esta el k que me estan pidiendo esto
* lo puedo hacer utilizando el arreglo que precalcule inicialmente luego sabiendo la sabiendo la cantidad
* de digitos utilizados hasta llegar al primer numero de i digitos se lo puedo restar a k. De esta forma 
* el valor que quede en k lo puedo dividir y obbenter el modulo de la división con los i digitos y de esta
* forma conocer en que numero de i digitos cae el valor inicial de k. 
*/
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;


public class Main {
    
    private BufferedReader in;
    private PrintWriter out;
    private StringTokenizer st;
    private final int MAX_N = 1000001;
    private final int MAX_TREE = (MAX_N << 2);
    
    private int [] movX = { 0, 0, 1, -1};
    private int [] movY = {-1, 1, 0,  0};
    private long [] cards ={1,10,100,1000,10000};
    private long MOD =1000000009;

	public long powbinary(long a, long b){
		if (b==0L) return 1L;
		else if (b==1L) return a;
		else{
			long res=powbinary(a,b/2);
			res*=res;
			if( b%2==1 ) res*=a;
			return res;
		}
	}

    public void solve() throws Exception {
		long [] ps = new long [19];
		ps[0]=0L;
		for(int x=1;x<=18;x++){
			ps[x]=x*9*powbinary(10,x-1)+ps[x-1];
		}
		
		long cases = nextLong();
		
		for(long j=1;j<=cases;j++){
			long k = nextLong();
			long digits = 0;
			for(int y=0;;y++){
				if(ps[y]>=k){
					digits = y;
					k-=ps[y-1];
					break;
				}
			}
			long num = k/digits;
			long mod = k%digits;
			if(mod == 0) mod=digits;
			else num++;
			long res= powbinary(10,digits-1)+num-1;
			String answer = String.valueOf(res);
			int pos=(int)mod-1;
			out.printf("%c\n",answer.charAt(pos));
		}
    }
    
    Main() throws Exception {
       /*Esta entrada  se debe activar cuando se hace una ejercicio de lectura hasta fin de fichero 
       copiar la entrada en un fichero "Input.txt" y comentar el otro in . A la hor de enviar comentar
       este y descomentar el otro
       */
       //in = new BufferedReader(new FileReader("Input.txt"));
       //out = new PrintWriter(new FileWriter("Output.txt"));
       in = new BufferedReader(new InputStreamReader(System.in));
	   out = new PrintWriter(System.out);
       eat("");
       solve();
       in.close();
       out.close();
    }
    private void eat(String str) { st = new StringTokenizer(str);}


    String next() throws Exception {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) return null;
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws Exception {return Integer.parseInt(next());}

    long nextLong() throws Exception {return Long.parseLong(next());}

    double nextDouble() throws Exception {return Double.parseDouble(next());}

    public static void main(String[] args) throws Exception {new Main();}
}
