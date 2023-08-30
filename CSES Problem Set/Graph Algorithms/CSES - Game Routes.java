/**
 * CSES - Game Routes
 * Temáticas: Teoria de grafos + Orden Topologico + Programación dinámica
 *  
 * Idea: Para solucionar basta con darse cuenta que la cantidad de formas de llegar
 * al nodo j es la sumatoria de las formas de llegar a los nodos que tienen una 
 * arista hacia el nodo j. Por eso antes de calcular la cantidad de formas de llegar
 * al nodo j debemos calcular los que tiene una arista hacia dicho nodo j. Para lograr
 * esto haremos un ordenamiento topologíco el cual siempre es posible por las 
 * condiciones del problema. Cuando estemos procesando al nodo j en el ordennamiento
 * topologico implica ya han sido procesado sus nodos antecesores por decirlo de
 * alguna manera por tanto conocemos la cantidad de forma de llegar a estos lo
 * que nos va permitir calcular la cantidad de formas hasta el nodo j. Para el 
 * nodo 1 la cantidad de forma de llegar es 1. Lo otro es modulando las sumas 
 * por el valor 10^9+7
 */

import java.io.*;
import java.math.*;
import java.util.*;
import java.util.*;
import java.lang.*;
import java.util.regex.*;
import java.util.stream.Stream;

public class Main {

	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;
	private final int MAX_N = 500010;
	private final int MAX_TREE = (MAX_N << 2);
	private final char SYMBOL = '@';
	private final double EPS = 1e-9;

	private int[] movX = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
	private int[] movY = { -1, 1, 0, 0, 1, -1, 1, -1, -2, 2, 2, -2 };
	private long[] cards = { 1, 10, 100, 1000, 10000 };
	private long MOD = 1000000007L;

	private void solve() throws Exception {
		int nnodes =nextInt(),npaths=nextInt(),A,B;
		
		int [] degree = new int[nnodes+1];
		long [] dp = new long[nnodes+1];
		List<Integer> [] edgesBack = new List[nnodes+1];;
		List<Integer> [] graph =new List[nnodes+1];
		
		for(int i=0;i<=nnodes;i++) {
			degree[i]=0;
			dp[i]=0L;
			edgesBack[i] = new ArrayList<Integer>();
			graph[i] = new ArrayList<Integer>();
		}
		
		for(int i=0;i<npaths;i++) {
			A=nextInt();
			B=nextInt();
			degree[B]++;
			graph[A].add(B);
			edgesBack[B].add(A);
		}
		
		dp[1]=1L;
		
		Queue<Integer> topSort =new ArrayDeque<Integer>();
		
		for (int i = 1; i <= nnodes; i++) { 
			if (degree[i] == 0) topSort.add(i);
		}
		
		while (topSort.isEmpty()==false) {
			int node = topSort.remove();
			for (int next : graph[node]) {
				degree[next]--;
				if (degree[next] == 0) topSort.add(next);
			}
			for (int prev : edgesBack[node]) {
				dp[node]=(dp[node]+dp[prev])%MOD;
			}
		}
		out.printf("%d\n", dp[nnodes]);
		
	}

	

	Main() throws Exception {
		/*
		 * Esta entrada se debe activar cuando se hace una ejercicio de lectura hasta
		 * fin de fichero copiar la entrada en un fichero "Input.txt" y comentar el otro
		 * in . A la hor de enviar comentar este y descomentar el otro
		 */
		// in = new BufferedReader(new FileReader("Input.txt"));
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

	private String next() throws Exception {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null)
				return null;
			eat(line);
		}
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) throws Exception {
		new Main();
	}
	
	

}