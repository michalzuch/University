class ParallelSearcher implements ParallelSearcherInterface {

    Thread[] threads;
    double counter = 0;
    HidingPlaceSupplier hidingPlace;
    Object lock;

    @Override
    public void set(HidingPlaceSupplierSupplier supplier) {
        hidingPlace = supplier.get(counter);
        while (hidingPlace != null) {
            int amount = hidingPlace.threads();
            threads = new Thread[amount];
            for (int i = 0; i < amount; i++) {
                lock = this;
                threads[i] = new Thread(){
                    HidingPlaceSupplier.HidingPlace localHidingPlace = hidingPlace.get();
                    Object localLock = lock;

                    @Override
                    public void run() {
                        while (localHidingPlace != null) {
                            synchronized (localHidingPlace) {
                                if (localHidingPlace.isPresent()) {
                                    synchronized (localLock) {
                                        counter += localHidingPlace.openAndGetValue();
                                    }
                                }
                                localHidingPlace = hidingPlace.get();
                            }
                        }
                    }
                };
                threads[i].start();
            }
            for (int i = 0; i < amount; i++) {
                try {
                    threads[i].join();
                } catch (InterruptedException ignored) {
                }
            }
            hidingPlace = supplier.get(counter);
            counter = 0;
        }
    }
}
