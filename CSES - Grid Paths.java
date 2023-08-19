/**
 * CSES - Grid Paths
 * Temáticas: Programacion dinámica + Caminos en la grilla 
 *  
 * Idea: Dada una matriz con obstaculos buscar la cantidad de caminos diferentes 
 * que existen partiendo desde la celda (1,1) hasta la celda (n,m) con solo 
 * movimientos solo hacia a derecha o izquierda.
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
	private double ERROR = 1e-9;

	public void solve() throws Exception {
		int n =nextInt();
		char [][] board = new char [n+10][n+10];
		long [][] dp = new long [n+10][n+10];
		
		Arrays.fill(dp[0],0L);
		Arrays.fill(board[0],'*');
		
		for(int i=1;i<=n;i++) {
			String x = "*"+next();
			board[i]=x.toCharArray();
		}
		
		for(int i=0;i<=n;i++)
			dp[i][0] = 0L;
		
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==1 && j==1) {
					dp[1][1]= ( board[1][1]=='*' ?0L:1L);
				}else {
					dp[i][j] = ( board[i][j]=='*' ?0L: (dp[i][j-1]+dp[i-1][j]) % MOD );
				}
			}
		}
				
		out.printf("%d\n", dp[n][n]);
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