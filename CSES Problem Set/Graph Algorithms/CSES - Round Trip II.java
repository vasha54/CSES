/**
* CSES - Round Trip II
* Tematica : Teoria de Grafos : Detención de ciclos en grafo  dirigido
* Idea: Dado un grafo  dirigido detectar si existe o no ciclo.
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
	
	int nnodes,u,v,mpaths;
	ArrayList<ArrayList<Integer> > adj;
	char [] color;
	int [] parent;
	int cycle_start, cycle_end;
 
	public boolean dfs(int v) {
	   color[v] = 1;
	   for (int u : adj.get(v)) {
	      if (color[u] == 0) {
	         parent[u] = v;
	         if (dfs(u)) return true;
	      } else if (color[u] == 1) {
	         cycle_end = v; cycle_start = u;
	         return true;
	      }
	   }
	   color[v] = 2;
	   return false;
	}
 
	void findCycle() {
	   color = new char[nnodes+5];
	   parent = new int [nnodes+5];
	   Arrays.fill(color, (char)0);
	   Arrays.fill(parent, -1);
	   cycle_start = -1;
		
	   for (int v = 1; v <= nnodes; v++) {
	      if (color[v] == 0 && dfs(v)) break;
	   }
		
	   if (cycle_start == -1) { out.printf("IMPOSSIBLE\n");} 
	   else {
	      List <Integer> cycle = new ArrayList<Integer>();
	      cycle.add(cycle_start);
	      for (int v = cycle_end; v != cycle_start; v = parent[v])
	      cycle.add(v); cycle.add(cycle_start);
	      Collections.reverse(cycle); 
	      out.printf("%d\n", cycle.size());
	      for (int v : cycle) out.printf("%d ", v);
	      out.println();
	   }
	}
	
	
 
	public void solve() throws Exception {
		nnodes = nextInt();
		mpaths = nextInt();
		adj = new ArrayList<ArrayList<Integer> >();
		
		for(int i=0;i<nnodes+5;i++) {
			ArrayList<Integer> p = new ArrayList<Integer>();
			adj.add(p);
		}
		
		for(int i=0;i<mpaths;i++) {
			u =nextInt();
			v =nextInt();
			adj.get(u).add(v);
		}
		
		findCycle();
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
