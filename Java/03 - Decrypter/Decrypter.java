import java.util.HashMap;
import java.util.Map;

class Decrypter implements DecrypterInterface {

    // String that holds passed encrypted document
    private String message;
    // Map that holds the key for coding message
    private Map<Character, Character> code;
    // Map that holds the key for decoding message
    private Map<Character, Character> decode;

    public void setInputText(String encryptedDocument) {
        if (encryptedDocument == null) {
            message = "";
        } else {
            // Remove any additional (1) spaces before message, (2) new lines,
            // (3) tabulators and (4) redundant spaces
            message = encryptedDocument.trim().replaceAll("\n", " ")
                    .replaceAll("\t", ""). replaceAll(" +", " ");
        }

        // Extract the key from coded message
        findCodingKey();
    }

    public Map<Character, Character> getCode() {
        // If message key couldn't be found return empty map
        if (code == null)
            code = new HashMap<>();

        return code;
    }

    public Map<Character, Character> getDecode() {
        // If message key couldn't be found return empty map
        if (decode == null)
            decode = new HashMap<>();

        return decode;
    }

    private void findCodingKey() {
        // Initialize maps
        code = new HashMap<>();
        decode = new HashMap<>();

        // Sample that needs to be coded in messages, that can be decoded
        final String sample = "Wydział Fizyki, Astronomii i Informatyki Stosowanej";

        // Message must be at least same length as sample to be decoded
        // Sample that needs to be coded in messages, that can be decoded
        if (message.length() >= sample.length()) {

            // Arrays with strings: sample and message split by words
            String[] messageSplit = message.split(" ");
            String[] sampleSplit = sample.split(" ");

            if (messageSplit.length >= sampleSplit.length) {
                // Boolean that checks if matching sequence of words has been found
                boolean found = false;
                int messageIndex = 0;

                while (!found) {
                    // Check if there are enough words for sequence to occur
                    if (messageIndex >= messageSplit.length - 5)
                        break;

                    // Check if length of words match the length of words in sample
                    // If yes - wanted sequence may occur
                    if (checkLengthOfWords(sampleSplit, messageSplit, messageIndex)) {
                        // Check if letters, that occur multiple times in words from sample (like 'a')
                        // Are on the same positions (indexes) in coded message
                        if (checkLettersPosition(messageSplit, messageIndex)) {
                            // Check if amount of repeated letters is same as in sample - letters might be on
                            // good indexes, but also somewhere redundantly
                            if (checkAmountOfLetters(sampleSplit, messageSplit, messageIndex)) {
                                generateMapValuesForCode(code, sampleSplit, messageSplit, messageIndex);
                                generateMapValuesForDecode(decode, sampleSplit, messageSplit, messageIndex);
                                found = true;
                            } else {
                                messageIndex++;
                            }
                        } else {
                            messageIndex++;
                        }
                    } else {
                        messageIndex++;
                    }
                }
            }
        }
    }

    /**
     * Check if sequence of words with correct length matching the sample has occurred - if all are
     * true - sequence occurred.
     * @param sample sample cut by words
     * @param message coded message cut by words
     * @param index index pointing at potential first word of sequence
     * @return true if length of each word matches the length from sample
     */
    private boolean checkLengthOfWords(String[] sample, String[] message, int index) {

        // Wydział
        boolean condition0 = (sample[0].length() == message[index].length());
        // Fizyki,
        boolean condition1 = (sample[1].length() == message[index + 1].length());
        // Astronomii
        boolean condition2 = (sample[2].length() == message[index + 2].length());
        // i
        boolean condition3 = (sample[3].length() == message[index + 3].length());
        // Informatyki
        boolean condition4 = (sample[4].length() == message[index + 4].length());
        // Stosowanej
        boolean condition5 = (sample[5].length() == message[index + 5].length());

        return condition0 && condition1 && condition2 && condition3 && condition4 && condition5;
    }

    /**
     * Check if repeated letters in words from sequence matches the layout from sample.
     * @param message coded message cut by words
     * @param index index pointing at potential first word of sequence
     * @return true if layout is the same
     */
    private boolean checkLettersPosition(String[] message, int index) {

        boolean conditionA = (message[index].charAt(5) == message[index + 4].charAt(6));

        boolean conditionI = (message[index].charAt(4) == message[index + 1].charAt(1)) &&
                (message[index].charAt(4) == message[index + 1].charAt(5)) &&
                (message[index].charAt(4) == message[index + 2].charAt(8)) &&
                (message[index].charAt(4) == message[index + 2].charAt(9)) &&
                (message[index].charAt(4) == message[index + 3].charAt(0)) &&
                (message[index].charAt(4) == message[index + 4].charAt(10));

        boolean conditionK = (message[index + 1].charAt(4) == message[index + 4].charAt(9));

        boolean conditionM = (message[index + 2].charAt(7) == message[index + 4].charAt(5));

        boolean conditionN = (message[index + 2].charAt(5) == message[index + 4].charAt(1)) &&
                (message[index + 2].charAt(5) == message[index + 5].charAt(7));

        boolean conditionO = (message[index + 2].charAt(4) == message[index + 2].charAt(6)) &&
                (message[index + 2].charAt(4) == message[index + 4].charAt(3)) &&
                (message[index + 2].charAt(4) == message[index + 5].charAt(2)) &&
                (message[index + 2].charAt(4) == message[index + 5].charAt(4));

        boolean conditionR = (message[index + 2].charAt(3) == message[index + 4].charAt(4));

        boolean conditionS = (message[index + 2].charAt(1) == message[index + 5].charAt(3));

        boolean conditionT = (message[index + 2].charAt(2) == message[index + 4].charAt(7)) &&
                (message[index + 2].charAt(2) == message[index + 5].charAt(1));

        boolean conditionY = (message[index].charAt(1) == message[index + 1].charAt(3)) &&
                (message[index].charAt(1) == message[index + 4].charAt(8));

        boolean conditionZ = (message[index].charAt(3) == message[index + 1].charAt(2));

        // Aditional condition - comma can not be the last character in any word except "Fizyki,"
        boolean conditionComma = (message[index].charAt(6) != ',') && (message[index + 2].charAt(9) != ',') &&
                (message[index + 3].charAt(0) != ',') && (message[index + 4].charAt(10) != ',') &&
                (message[index + 5].charAt(9) != ',');

        return conditionA && conditionI && conditionK && conditionM && conditionN && conditionO
                && conditionR && conditionS && conditionT && conditionY && conditionZ && conditionComma;
    }

    /**
     * Check if repeated letters don't occur too many times.
     * @param letter letter that will be compared
     * @param word word, which letters will be counted
     * @return amount of letters
     */
    private int letterCounter(char letter, String word) {
        int counter = 0;
        for (int i = 0; i < word.length(); i++)
            if (word.charAt(i) == letter)
                counter++;

        return counter;
    }

    /**
     * Check if amount of repeated letters is correct for each repeated letter.
     * @param message coded message cut by words
     * @param word word that will be checked
     * @param sample sample cut by words
     * @param index index pointing at potential first word of sequence
     * @return true if there are no redundant letters
     */
    private boolean checkAmountOfLettersInWord(String[] message, String word, String sample, int index) {
        boolean conditionA = letterCounter(message[index].charAt(5), word) == letterCounter('a', sample);
        boolean conditionI = letterCounter(message[index].charAt(4), word) == letterCounter('i', sample);
        boolean conditionK = letterCounter(message[index + 1].charAt(4), word) == letterCounter('k', sample);
        boolean conditionM = letterCounter(message[index + 2].charAt(7), word) == letterCounter('m', sample);
        boolean conditionN = letterCounter(message[index + 2].charAt(5), word) == letterCounter('n', sample);
        boolean conditionO = letterCounter(message[index + 2].charAt(4), word) == letterCounter('o', sample);
        boolean conditionR = letterCounter(message[index + 2].charAt(3), word) == letterCounter('r', sample);
        boolean conditionS = letterCounter(message[index + 2].charAt(1), word) == letterCounter('s', sample);
        boolean conditionT = letterCounter(message[index + 2].charAt(2), word) == letterCounter('t', sample);
        boolean conditionY = letterCounter(message[index].charAt(1), word) == letterCounter('y', sample);
        boolean conditionZ = letterCounter(message[index].charAt(3), word) == letterCounter('z', sample);

        return conditionA && conditionI && conditionK && conditionM && conditionN && conditionO
                && conditionR && conditionS && conditionT && conditionY && conditionZ;
    }

    /**
     * Check if amount of repeated letters is correct for each repeated letter in each word from sequence.
     * @param sample sample cut by words
     * @param message coded message cut by words
     * @param index index pointing at potential first word of sequence
     * @return true if there are no redundant letters in any word
     */
    private boolean checkAmountOfLetters(String[] sample, String[] message, int index) {
        boolean condition0 = checkAmountOfLettersInWord(message, message[index], sample[0], index);
        boolean condition1 = checkAmountOfLettersInWord(message, message[index + 1], sample[1], index);
        boolean condition2 = checkAmountOfLettersInWord(message, message[index + 2], sample[2], index);
        boolean condition3 = checkAmountOfLettersInWord(message, message[index + 3], sample[3], index);
        boolean condition4 = checkAmountOfLettersInWord(message, message[index + 4], sample[4], index);
        boolean condition5 = checkAmountOfLettersInWord(message, message[index + 5], sample[5], index);

        return condition0 && condition1 && condition2 && condition3 && condition4 && condition5;
    }

    /**
     * Generate map with values to code the message.
     * @param output map which will hold keys and values
     * @param sample sample cut by words
     * @param message coded message cut by words
     * @param index index pointing at potential first word of sequence
     */
    private void generateMapValuesForCode(Map<Character, Character> output , String[] sample, String[] message, int index) {
        for (String s : sample) {
            for (int n = 0; n < s.length(); n++) {
                output.put(s.charAt(n), message[index].charAt(n));
            }
            index++;
        }
        output.remove(',');
    }

    /**
     * Generate map with values to decode the message.
     * @param output map which will hold keys and values
     * @param sample sample cut by words
     * @param message coded message cut by words
     * @param index index pointing at potential first word of sequence
     */
    private void generateMapValuesForDecode(Map<Character, Character> output , String[] sample, String[] message, int index) {
        for (String s : sample) {
            for (int n = 0; n < s.length(); n++) {
                output.put(message[index].charAt(n), s.charAt(n));
            }
            index++;
        }
    }
}