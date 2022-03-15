import java.util.ArrayList;
import java.util.List;

class Loops implements GeneralLoops {

    // List of lower limits
    private List<Integer> lowerLimits;
    // List of upper limits
    private List<Integer> upperLimits;
    // List of results
    private List<List<Integer>> results = new ArrayList<>();
    // List that holds particular item from results list
    private List<Integer> currentIndex = new ArrayList<>();
    // Counter of nest level (how deep for loops are)
    private int nestLevel = 0;

    public void setLowerLimits(List<Integer> limits) { lowerLimits = new ArrayList<>(limits); }

    public void setUpperLimits(List<Integer> limits) { upperLimits = new ArrayList<>(limits); }

    public List<List<Integer>> getResult() {

        // Check if none of lower and upper limits lists are empty
        // If both are empty, add one 0 to each of them
        // If one is empty add amount of 0's to empty one so it will be same length as completed list
        if ((lowerLimits == null) && (upperLimits == null)) {
            lowerLimits = new ArrayList<>(List.of(0));
            upperLimits = new ArrayList<>(List.of(0));
        } else {
            if (lowerLimits == null) {
                lowerLimits = new ArrayList<>();
                for (int i = 0; i < upperLimits.size(); i++) {
                    lowerLimits.add(0);
                }
            }

            if (upperLimits == null) {
                upperLimits = new ArrayList<>();
                for (int i = 0; i < lowerLimits.size(); i++) {
                    upperLimits.add(0);
                }
            }
        }

        setCurrentIndex(currentIndex);
        loop(nestLevel, lowerLimits, upperLimits, currentIndex, results);
        return results;
    }

    /**
     * Fill the list with 0's until it is same size as upperLimits
     * @param currIndexes List that holds particular item from results list
     */
    private void setCurrentIndex(List<Integer> currIndexes) {
        for (int i = 0; i < upperLimits.size(); i++) {
            currIndexes.add(0);
        }
    }

    /**
     * Recursive for loop function, that saves information about its iterators
     * @param nestLevel Counter of nest level (how deep for loops are)
     * @param lowerLimits List of lower limits
     * @param upperLimits List of upper limits
     * @param currentIndex List that holds particular item from results list
     * @param results List of results
     */
    private void loop(int nestLevel, List<Integer> lowerLimits, List<Integer> upperLimits, List<Integer> currentIndex, List<List<Integer>> results) {

        boolean isFinalLoop = (nestLevel == lowerLimits.size() - 1);

        // Add iterator to list
        for (int i = lowerLimits.get(nestLevel); i <= upperLimits.get(nestLevel); i++) {
            currentIndex.set(nestLevel, i);

            if (isFinalLoop) {
                // Create a copy of a list, so it will not be modified in the next iterations
                List<Integer> copy = new ArrayList<Integer>(currentIndex);
                results.add(copy);
            }
            else {
                // Recursion call
                loop(nestLevel + 1, lowerLimits, upperLimits, currentIndex, results);
            }
        }
    }
}