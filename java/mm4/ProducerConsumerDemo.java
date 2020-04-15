/** 
 * Main for the Producer-Consumer example
 *
 * Tutorial example
 **/

import prodcon.*;

public class ProducerConsumerDemo {
    public static void main(String[] args) {
        Drop drop = new Drop();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Producer(drop))).start();
        (new Thread(new Consumer(drop))).start();
        (new Thread(new Consumer(drop))).start();
        (new Thread(new Consumer(drop))).start();
        (new Thread(new Consumer(drop))).start();
    }
}
