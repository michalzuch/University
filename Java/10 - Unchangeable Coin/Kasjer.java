import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Supplier;

public class Kasjer implements KasjerInterface {

    List<Pieniadz> cashRegister = new LinkedList<>();
    RozmieniaczInterface exchanger;

    @Override
    public List<Pieniadz> rozlicz(int cena, List<Pieniadz> pieniadze) {
        List<Pieniadz> money = new LinkedList<>(pieniadze);
        List<Pieniadz> rest = new LinkedList<>();
        int price = cena;

        int changableMoneyAmount = 0;
        int nonChangableMoneyAmount = 0;

        for (Pieniadz coin : money) {
            if (coin.czyMozeBycRozmieniony()) {
                changableMoneyAmount += coin.wartosc();
            } else {
                nonChangableMoneyAmount += coin.wartosc();
            }
        }

        // Received correct amount of money
        if (price == nonChangableMoneyAmount + changableMoneyAmount) {
            cashRegister.addAll(money);
            money.clear();
            return rest;
        } else
            // Rest can be given in changable coins only
            if (Math.abs(price - nonChangableMoneyAmount) <= changableMoneyAmount) {
                for (Pieniadz coin : money) {
                    if (!coin.czyMozeBycRozmieniony()) {
                        cashRegister.add(coin);
                        money.remove(coin);
                    }
                }
                int amountToReturn = (changableMoneyAmount + nonChangableMoneyAmount) - price;
                int returnedAmount = 0;
                cashRegister.addAll(money);
                money.clear();
                do {
                    cashRegister = exchangeForOnes(cashRegister);
                } while (containsOtherThanOne(cashRegister));

                for (Iterator<Pieniadz> iterator = cashRegister.iterator(); iterator.hasNext(); ) {
                    Pieniadz temp = iterator.next();
                    if (temp.czyMozeBycRozmieniony()) {
                        rest.add(temp);
                        iterator.remove();
                        returnedAmount++;
                    }
                    if (returnedAmount == amountToReturn) {
                        break;
                    }
                }
                return rest;
            } else {
                int value = 111110;
                for (Pieniadz coin : money) {
                    if (!coin.czyMozeBycRozmieniony()) {
                        if (coin.wartosc() < value) {
                            value = coin.wartosc();
                        }
                    }
                }
                for (Iterator<Pieniadz> iterator = money.iterator(); iterator.hasNext(); ) {
                    Pieniadz temp = iterator.next();
                    if (temp.wartosc() == value) {
                        rest.add(temp);
                        iterator.remove();
                        break;
                    }
                }
                cashRegister.addAll(money);
                do {
                    cashRegister = exchangeForOnes(cashRegister);
                } while (containsOtherThanOne(cashRegister));

                int amountToReturn = value - price;
                int returnedAmount = 0;

                for (Iterator<Pieniadz> iterator = cashRegister.iterator(); iterator.hasNext(); ) {
                    Pieniadz temp = iterator.next();
                    if (temp.czyMozeBycRozmieniony()) {
                        rest.add(temp);
                        iterator.remove();
                        returnedAmount++;
                    }
                    if (returnedAmount == amountToReturn) {
                        break;
                    }
                }
                return rest;
            }
    }

    @Override
    public List<Pieniadz> stanKasy() {
        return cashRegister;
    }

    @Override
    public void dostępDoRozmieniacza(RozmieniaczInterface rozmieniacz) {
        exchanger = rozmieniacz;
    }

    @Override
    public void dostępDoPoczątkowegoStanuKasy(Supplier<Pieniadz> dostawca) {
        Pieniadz coin = dostawca.get();
        while (coin != null) {
            cashRegister.add(coin);
            coin = dostawca.get();
        }
    }

    private List<Pieniadz> exchangeForOnes(List<Pieniadz> cashRegister) {
        List<Pieniadz> localCashRegister = new LinkedList<>(cashRegister);
        for (int i = 0; i < localCashRegister.size(); i++) {
            if (localCashRegister.get(i).czyMozeBycRozmieniony()) {
                if (localCashRegister.get(i).wartosc() != 1) {
                    List<Pieniadz> temp = exchanger.rozmien(localCashRegister.get(i));
                    localCashRegister.remove(localCashRegister.get(i));
                    localCashRegister.addAll(temp);
                }
            }
        }
        return localCashRegister;
    }

    private boolean containsOtherThanOne(List<Pieniadz> cashRegister) {
        for (Pieniadz coin : cashRegister) {
            if (coin.czyMozeBycRozmieniony())
                if (coin.wartosc() != 1)
                    return true;
        }
        return false;
    }
}
