import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.toMap;

public class Compression implements CompressionInterface {

    List<String> words = new LinkedList<>();
    List<String> compressedWords = new LinkedList<>();
    Map<String, String> header = new HashMap<>();

    int lengthBeforeCompression = 0;
    int lastTaken = 0;

    @Override
    public void addWord(String word) {
        words.add(word);
        lengthBeforeCompression += word.length();
    }

    @Override
    public void compress() {
        Map<String, Integer> countedWords = analyzerRepeatedSequences(words);
        Map<String, Integer> sortedWords = countedWords
                .entrySet()
                .stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .collect(toMap(Map.Entry::getKey, Map.Entry::getValue, (e1, e2) -> e2, LinkedHashMap::new));
        List<String> localWords = new LinkedList<>(words);
        Map<String, String> localHeader = new HashMap<>();
        int optimal = 0;
        for (String word : words) {
            optimal += word.length();
        }

        boolean foundOptimalCompression = false;
        int i = 0;

        List<String> keys = new LinkedList<>(sortedWords.keySet());

        while (!foundOptimalCompression && i != sortedWords.size()) {
            List<String> normal = new LinkedList<>();
            List<String> compressed = new LinkedList<>();
            for (int j = 0; j <= i; j++) {
                normal.add(keys.get(j));
            }
            for (int j = 0; j <= i; j++) {
                if (i == 0)
                    compressed.add(Integer.toBinaryString(j));
                else if (Integer.toBinaryString(i).length() - Integer.toBinaryString(j).length() == 0) {
                    compressed.add("0" + Integer.toBinaryString(j));
                } else {
                    String temp = Integer.toBinaryString(j);
                    while (true) {
                        if (Integer.toBinaryString(i).length() - temp.length() >= 0) {
                            temp = "0" + temp;
                        } else {
                            break;
                        }
                    }
                    compressed.add(temp);
                }
            }
            int binaryLength = i + 1;
            for (int k = 0; k < normal.size(); k++) {
                localHeader.put(normal.get(k), compressed.get(k));
            }

            int compressedLength = 0;
            for (String key : localHeader.keySet()) {
                compressedLength += key.length();
                compressedLength += binaryLength;
            }
            for (int k = 0; k < words.size(); k++) {
                if (localHeader.containsKey(words.get(k))) {
                    localWords.set(k, localHeader.get(words.get(k)));
                } else {
                    localWords.set(k, "1" + words.get(k));
                }
                compressedLength += localWords.get(k).length();
            }

            if (compressedLength < optimal) {
                optimal = compressedLength;
                compressedWords = new LinkedList<>(localWords);
                header = new HashMap<>(localHeader);
            } else if (compressedLength > optimal) {
                foundOptimalCompression = true;
            }
            i++;
        }
    }

    @Override
    public Map<String, String> getHeader() {
        Map<String, String> correctOrderHeader =
                header.entrySet()
                        .stream()
                        .collect(Collectors.toMap(Map.Entry::getValue, Map.Entry::getKey));
        return correctOrderHeader;
    }

    @Override
    public String getWord() {
        String returnString = compressedWords.get(lastTaken);
        lastTaken++;
        return returnString;
    }

    private Map<String, Integer> analyzerRepeatedSequences(List<String> words) {
        Map<String, Integer> analyze = new HashMap<>();
        for (String word : words) {
            analyze.put(word, 0);
        }
        for (String sequence : analyze.keySet()) {
            int counter = 0;
            for (String word : words) {
                if (Objects.equals(word, sequence)) {
                    counter++;
                }
            }
            if (counter > 1) {
                analyze.put(sequence, counter);
            }
        }

        List<String> keys = new LinkedList<>(analyze.keySet());
        for (String key : keys)
            if (analyze.get(key) == 0)
                analyze.remove(key);
        return analyze;
    }
}