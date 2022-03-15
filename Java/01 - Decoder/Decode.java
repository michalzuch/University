class Decode extends DecoderInterface {

    // Strings for coded input and decoded output.
    String codedMessage = "";
    String decodedMessage = "";

    public void input(int bit) {
        codedMessage += bit;
    }

    public String output() {
        // Check if string to decode contains any 0, if not return ""
        if (!codedMessage.contains("0")) {
            return "";
        }
            // Check if string to decode contains any 1, if not return ""
        if (!codedMessage.contains("1")) {
            return "";
        }

        int i = 0; // variable for navigating through the String
        int x = 0; // variable for storing value of 1's that code X
        int countValue = 0; // variable for storing value of 1's next to each other
        int max = codedMessage.length(); // length of message to decode

        // Skip all the 0's that are at beginning
        while ((codedMessage.charAt(i) - '0') == 0) { i++; }
        // Count the value of 1's coding 0 (X0), if there is no 0 after 1 - return ""
        while ((codedMessage.charAt(i) - '0') == 1) {
            if (!codedMessage.substring(i, max).contains("0")) return "";
            i++;
            x++;
        }

        // At this point decoded string is at least equal to 0, because setting the X above decodes
        // first 0 of the coded signal
        decodedMessage = "0";

        //  Splitting iterator for two iterators
        // i = j + 1
        // i subtracted by 1 ensure correct logical operations in if (... || ...) statement
        int j = i;
        i++;

        // Loop that will go through each sign of coded string
        while (i < codedMessage.length()) {
            // Condition that checks if current (according to i) or previous character is 1
            if (((codedMessage.charAt(j)) != '0') || ((codedMessage.charAt(j + 1)) != '0')) {
                // Condition that counts amount of 1's next to each other
                // When current character is 1 - counter is incremented
                // When condition is false number of 1's is being decoded (into 0, 1, 2 or 3)
                // and added to decoded string
                if ((codedMessage.charAt(i)) == '1') {
                    countValue++;
                } else {
                    decodedMessage = decodedMessage + ((countValue / x) - 1);
                    countValue = 0;
                }
            }
            j++;
            i++;
        }
        return decodedMessage;
    }

    public void reset() {
        codedMessage = "";
        decodedMessage = "";
    }
}
