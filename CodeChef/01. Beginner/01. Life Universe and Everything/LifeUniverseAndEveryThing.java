package life.universe.and.everything;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class LifeUniverseAndEveryThing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int value;
        try {
            do {
                value = sc.nextInt();

                if (value != 42) System.out.println(value);
            } while (value != 42);
        } catch (NoSuchElementException e) {
            // nothing to handle here...  
        }
    }
    
}
