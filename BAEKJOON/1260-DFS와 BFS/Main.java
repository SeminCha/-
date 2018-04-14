import java.util.*;

public class Main {

	static boolean[]visited;
	static int[][] graph;
	static int n,m,v;
	
	public static void dfs(int v) {
		visited[v] = true;
		System.out.print(v+" ");
		for(int i=1;i<=n;i++) {
			if(graph[v][i]==1&&!visited[i]) {
				dfs(i);
			}
		}
	}

	public static void bfs(int v) {
		visited[v] = true;
		System.out.print(v+" ");
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.offer(v);

		while(!queue.isEmpty()) {
			int temp = queue.poll();
			for(int i=1;i<=n;i++) {
				if(graph[temp][i]==1&&!visited[i]) {
					visited[i] = true;
					queue.offer(i);
					System.out.print(i+" ");
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		visited = new boolean[1001];
		graph = new int[1001][1001];
		n = sc.nextInt();
		m = sc.nextInt();
		v = sc.nextInt();

		for(int i=1;i<=m;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			graph[a][b] = graph[b][a] = 1;
		}

		dfs(v);
		System.out.println();
		visited = new boolean[1001];
		bfs(v);
	}
}
