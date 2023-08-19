/**
 * CSES Minimizing Coins
 * Temáticas: Programacion Dinamica + Coin Change
 *  
 * Idea:
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
		int ncoins = nextInt(), x = nextInt();
		int[] coins = new int[ncoins];
		for (int i = 0; i < ncoins; i++)
			coins[i] = nextInt();
 
		out.printf("%d\n", minimunCoins(coins, x));
	}
 
	private int minimunCoins(int[] coins, int x) {
		int[] values = new int[x + 10];
		Arrays.fill(values, Integer.MAX_VALUE);
		values[0] = 0;
		for (int i = 1; i <= x; i++) {
			for (int c : coins) {
				if (i - c >= 0 && values[i - c]!=Integer.MAX_VALUE) {
					values[i] = Math.min(values[i], values[i - c] + 1);
				}
			}
		}
		
		return values[x]==Integer.MAX_VALUE ? -1 : values[x];
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
