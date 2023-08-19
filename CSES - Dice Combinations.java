/**
 * CSES - Dice Combinations
 * Temáticas: Progrmación dinámica : Coin Change
 *  
 * Idea: De cuantas formas se puede expresar un valor N como suma de de monedas 
 * con valor 1,2,3,4,5,6 el valor debe ser modulado 10^9+7
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
	private final int MAX_N = 1000010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';

	private int[] movX = { 0, 0, 1, -1 };
	private int[] movY = { -1, 1, 0, 0 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000007;

	public void solve() throws Exception {
		long [] ways = new long[MAX_N];
		int [] coins = {1,2,3,4,5,6};
		
		ways[0]=1L;
		
		for(int i=0;i<MAX_N;i++) {
			for(int j=0;j<coins.length;j++) {
				if(i+coins[j]<MAX_N)
					ways[i+coins[j]]=(ways[i+coins[j]]+ways[i])%MOD;
			}
		}
		
		int n =nextInt();
		out.printf("%d\n", ways[n]);
	}

	

	



	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Inpu.txt"));
		// out = new PrintWriter(new FileWriter("Output.txt"));
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		eat("");
		solve();
		in.close();
		out.close();
	}

	private void eat(String str) {
		st = new StringTokenizer(str);
	}

	String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}

}