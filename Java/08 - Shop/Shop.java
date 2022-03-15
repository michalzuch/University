import java.util.HashMap;
import java.util.Map;

public class Shop implements ShopInterface {

    Map<String, Integer> assortment = new HashMap<>();
    Map<String, Object> blockedThreads = new HashMap<>();

    @Override
    public synchronized void delivery(Map<String, Integer> goods) {
        for (String name : goods.keySet()) {
            int deliveredAmount;
            deliveredAmount = goods.get(name);
            if (assortment.containsKey(name))
                deliveredAmount += assortment.get(name);
            assortment.put(name, deliveredAmount);
            if (blockedThreads.containsKey(name))
                synchronized (blockedThreads.get(name)) {
                    blockedThreads.get(name).notifyAll();
                }
        }
    }

    @Override
    public boolean purchase(String productName, int quantity) {
        int availableAmount;
        blockedThreads.computeIfAbsent(productName, k -> new Object());
        assortment.putIfAbsent(productName, 0);
        synchronized (blockedThreads.get(productName)) {
            try {
                availableAmount = assortment.get(productName);
                if (availableAmount < quantity) blockedThreads.get(productName).wait();
                else {
                    availableAmount -= quantity;
                    assortment.put(productName, availableAmount);
                    return true;
                }
            } catch (InterruptedException ignored) {}

            availableAmount = assortment.get(productName);
            if (quantity <= availableAmount) {
                availableAmount -= quantity;
                assortment.put(productName, availableAmount);
                return true;
            }
        }
        return false;
    }

    @Override
    public Map<String, Integer> stock() {
        return assortment;
    }
}
