/**
 * Producer.java implements the producer side in the Producer-Consumer
 * demo.
 * 
 * Tutorial demo
 **/
package prodcon;

import java.util.Random;

public class Producer implements Runnable {
    private Drop drop;

    public Producer(Drop drop) {
        this.drop = drop;
    }

    public void run() {
        String importantInfo[] = {
            "Bart Simpson",
            "is a brat",
            "Homer Simpson",
            "is a loser",
            "Marge Simpson",
            "has blue hair",
            "Lisa Simpson",
            "plays the sax",
            "Maggie Simpson",
            "is a baby"
        };
        Random random = new Random();

        for (int i = 0; i < importantInfo.length; i++) {
            drop.put(importantInfo[i]);
            try {
                Thread.sleep(random.nextInt(5000));
            } catch (InterruptedException e) {}
        }
        drop.put("DONE");
    }
}
