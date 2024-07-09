import java.util.HashMap;
import java.util.Map;
 
class LeastResponseLoadBalancer {
    private Map<String, Long> serverResponseTimes;
 
    public LeastResponseLoadBalancer() {
        this.serverResponseTimes = new HashMap<>();
    }
 
    public void addServer(String serverName) {
        // Add a server to the load balancer with 0 initial response time
        serverResponseTimes.put(serverName, 0L);
    }
 
    public String getServerWithLeastResponseTime() {
        // Find the server with the least accumulated response time
        long minResponseTime = Long.MAX_VALUE;
        String selectedServer = null;
 
        for (Map.Entry<String, Long> entry : serverResponseTimes.entrySet()) {
            if (entry.getValue() < minResponseTime) {
                minResponseTime = entry.getValue();
                selectedServer = entry.getKey();
            }
        }
 
        // Increment the response time for the selected server
        if (selectedServer != null) {
            serverResponseTimes.put(selectedServer, minResponseTime + 1);
        }
 
        return selectedServer;
    }
}
 
public class LeastResponseLoadBalancerExample {
    public static void main(String[] args) {
        // Create a Least Response load balancer
        LeastResponseLoadBalancer loadBalancer = new LeastResponseLoadBalancer();
 
        // Add servers to the load balancer
        loadBalancer.addServer("Server1");
        loadBalancer.addServer("Server2");
        loadBalancer.addServer("Server3");
 
        // Simulate requests and print the server to which each request is routed
        for (int i = 0; i < 10; i++) {
            String selectedServer = loadBalancer.getServerWithLeastResponseTime();
            System.out.println("Request " + (i + 1) + ": Routed to " + selectedServer);
        }
    }
}
