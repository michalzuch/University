import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;

class BusLine implements BusLineInterface {

    Map<String, List<Position>> lines = new HashMap<>();
    Map<String, List<Position>> intersectionPositions = new HashMap<>();
    Map<String, List<String>> intersectionsWithLines = new HashMap<>();
    Map<BusLineInterface.LinesPair, Set<Position>> intersectionOfLinesPair = new HashMap<>();

    Map<String, Set<LineSegment>> unsortedSegments = new HashMap<>();
    Map<String, Set<Position>> suspiciousPoints = new HashMap<>();

    class LinesPair implements BusLineInterface.LinesPair {
        String firstLineName;
        String secondLineName;

        LinesPair(String firstLineName, String secondLineName) {
            this.firstLineName = firstLineName;
            this.secondLineName = secondLineName;
        }

        @Override
        public String getFirstLineName() {
            return firstLineName;
        }

        @Override
        public String getSecondLineName() {
            return secondLineName;
        }

        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null) return false;
            if (getClass() != obj.getClass()) return false;
            LinesPair other = (LinesPair) obj;
            return Objects.equals(getFirstLineName(), other.getFirstLineName()) && Objects.equals(getSecondLineName(), other.getSecondLineName());
        }
    }

    @Override
    public void addBusLine(String busLineName, Position firstPoint, Position lastPoint) {
        List<Position> positions = new LinkedList<>();
        positions.add(firstPoint);
        positions.add(lastPoint);
        lines.put(busLineName, positions);
    }

    @Override
    public void addLineSegment(String busLineName, LineSegment lineSegment) {
        unsortedSegments.putIfAbsent(busLineName, new HashSet<>());
        Set<LineSegment> temp = unsortedSegments.get(busLineName);
        temp.add(lineSegment);
        unsortedSegments.put(busLineName, temp);
    }

    @Override
    public void findIntersections() {
        for (String name : lines.keySet()) {
            createPointsMap(name, unsortedSegments.get(name));
        }
        for (String name : lines.keySet()) {
            findSuspiciousPoints(name);
        }
        for (String name : lines.keySet()) {
            for (String otherName : lines.keySet()) {
                intersectionOfLinesPair.put(new LinesPair(name, otherName), new HashSet<>());
            }
        }
        for (String name : suspiciousPoints.keySet()) {
            intersectionPositions.putIfAbsent(name, new LinkedList<>());
            intersectionsWithLines.putIfAbsent(name, new LinkedList<>());
            analyzePoints(name);
        }
    }

    @Override
    public Map<String, List<Position>> getLines() {
        List<String> toRemove = new LinkedList<>();
        for (String line : lines.keySet()) {
            if (intersectionPositions.get(line).isEmpty()) {
                toRemove.add(line);
            }
        }
        for (String name : toRemove) {
            lines.remove(name);
        }
        return lines;
    }

    @Override
    public Map<String, List<Position>> getIntersectionPositions() {
        List<String> toRemove = new LinkedList<>();
        for (String name : intersectionPositions.keySet()) {
            if (intersectionPositions.get(name).isEmpty()) {
                toRemove.add(name);
            }
        }
        for (String name : toRemove) {
            intersectionPositions.remove(name);
        }
        return intersectionPositions;
    }

    @Override
    public Map<String, List<String>> getIntersectionsWithLines() {
        List<String> toRemove = new LinkedList<>();
        for (String name : intersectionsWithLines.keySet()) {
            if (intersectionsWithLines.get(name).isEmpty()) {
                toRemove.add(name);
            }
        }
        for (String name : toRemove) {
            intersectionsWithLines.remove(name);
        }
        return intersectionsWithLines;
    }

    @Override
    public Map<BusLineInterface.LinesPair, Set<Position>> getIntersectionOfLinesPair() {
        return intersectionOfLinesPair;
    }

    private void createPointsMap(String lineName, Set<LineSegment> entrySet) {
        List<Position> positionsInOrder = new LinkedList<>();
        Position startingPoint = lines.get(lineName).get(0);
        Position finishingPosition = lines.get(lineName).get(1);
        lines.get(lineName).clear();
        positionsInOrder.add(startingPoint);
        Set<LineSegment> removed = new HashSet<>();
        while (!positionsInOrder.get(positionsInOrder.size() - 1).equals(finishingPosition)) {
            for (LineSegment segment : entrySet) {
                if (segment.getFirstPosition().equals(positionsInOrder.get(positionsInOrder.size() - 1)) || (segment.getLastPosition().equals(positionsInOrder.get(positionsInOrder.size() - 1)))) {
                    unpackLineSegment(segment, positionsInOrder);
                    removed.add(segment);
                    break;
                }
            }
            entrySet.removeAll(removed);
            removed.clear();
        }
        lines.put(lineName, positionsInOrder);
    }

    private void unpackLineSegment(LineSegment segment, List<Position> entryList) {
        List<Position> workingList = new LinkedList<>();
        int firstColumn = segment.getFirstPosition().getCol();
        int lastColumn = segment.getLastPosition().getCol();
        int firstRow = segment.getFirstPosition().getRow();
        int lastRow = segment.getLastPosition().getRow();

        // Vertical
        if (firstColumn == lastColumn) {
            if (firstRow < lastRow) {
                for (int i = firstRow; i <= lastRow; i++) {
                    workingList.add(new Position2D(firstColumn, i));
                }
            } else {
                for (int i = firstRow; i >= lastRow; i--) {
                    workingList.add(new Position2D(firstColumn, i));
                }
            }
        } else
            // Horizontal
            if (firstRow == lastRow) {
                if (firstColumn < lastColumn) {
                    for (int i = firstColumn; i <= lastColumn; i++) {
                        workingList.add(new Position2D(i, firstRow));
                    }
                } else {
                    for (int i = firstColumn; i >= lastColumn; i--) {
                        workingList.add(new Position2D(i, firstRow));
                    }
                }
            } else {
                // Diagonal
                if (firstRow < lastRow && firstColumn < lastColumn) {
                    int i = firstColumn;
                    int j = firstRow;
                    for (int k = 0; k <= lastColumn - firstColumn; k++) {
                        workingList.add(new Position2D(i, j));
                        i++;
                        j++;
                    }
                } else if (firstRow > lastRow && firstColumn > lastColumn) {
                    int i = firstColumn;
                    int j = firstRow;
                    for (int k = 0; k <= firstRow - lastRow; k++) {
                        workingList.add(new Position2D(i, j));
                        i--;
                        j--;
                    }
                } else if (firstRow < lastRow && firstColumn > lastColumn) {
                    int i = firstColumn;
                    int j = firstRow;
                    for (int k = 0; k <= lastRow - firstRow; k++) {
                        workingList.add(new Position2D(i, j));
                        i--;
                        j++;
                    }
                } else if (firstRow > lastRow && firstColumn < lastColumn) {
                    int i = firstColumn;
                    int j = firstRow;
                    for (int k = 0; k <= firstRow - lastRow; k++) {
                        workingList.add(new Position2D(i, j));
                        i++;
                        j--;
                    }
                }
            }
        workingList.remove(0);
        entryList.addAll(workingList);
    }

    private void findSuspiciousPoints(String lineName) {
        Set<Position> susPoints = new HashSet<>();
        List<String> otherLines = new LinkedList<>(lines.keySet());
        otherLines.remove(lineName);
        for (Position point : lines.get(lineName)) {
            for (String otherLine : otherLines) {
                if (lines.get(otherLine).contains(point)) {
                    susPoints.add(point);
                }
            }
        }
        suspiciousPoints.put(lineName, susPoints);
    }

    private void analyzePoints(String lineName) {
        List<String> otherLines = new LinkedList<>(lines.keySet());
        otherLines.remove(lineName);
        for (Position point : lines.get(lineName)) {
            for (String name : lines.keySet()) {
                if (Objects.equals(lineName, name)) {
                    checkIfPerpendicular(lineName, point, lineName);
                } else {
                    if (suspiciousPoints.get(name).contains(point)) {
                        checkIfPerpendicular(lineName, point, name);
                    }
                }
            }
        }
    }

    private void checkIfPerpendicular(String lineName, Position susPoint, String otherLine) {
        if (susPoint != lines.get(lineName).get(0) && susPoint != lines.get(lineName).get(lines.get(lineName).size() - 1)) {
            if (lines.get(otherLine).contains(susPoint)) {
                Position before = lines.get(lineName).get(lines.get(lineName).indexOf(susPoint) - 1);
                Position after = lines.get(lineName).get(lines.get(lineName).indexOf(susPoint) + 1);
                Position temp1 = null;
                Position temp2 = null;
                Position temp3 = null;
                Position temp4 = null;

                if (before.getRow() == after.getRow()) {
                    temp1 = new Position2D(susPoint.getCol(), susPoint.getRow() + 1);
                    temp2 = new Position2D(susPoint.getCol(), susPoint.getRow() - 1);
                    temp3 = new Position2D(susPoint.getCol() + 1, susPoint.getRow());
                    temp4 = new Position2D(susPoint.getCol() - 1, susPoint.getRow());
                } else if (before.getCol() == after.getCol()) {
                    temp1 = new Position2D(susPoint.getCol() + 1, susPoint.getRow());
                    temp2 = new Position2D(susPoint.getCol() - 1, susPoint.getRow());
                    temp3 = new Position2D(susPoint.getCol(), susPoint.getRow() + 1);
                    temp4 = new Position2D(susPoint.getCol(), susPoint.getRow() - 1);
                } else {
                    if (before.getRow() > after.getRow() && before.getCol() > after.getCol() || before.getRow() < after.getRow() && before.getCol() < after.getCol()) {
                        temp1 = new Position2D(susPoint.getCol() + 1, susPoint.getRow() - 1);
                        temp2 = new Position2D(susPoint.getCol() - 1, susPoint.getRow() + 1);
                        temp3 = new Position2D(susPoint.getCol() + 1, susPoint.getRow() + 1);
                        temp4 = new Position2D(susPoint.getCol() - 1, susPoint.getRow() - 1);
                    } else if (before.getRow() > after.getRow() && before.getCol() < after.getCol() || before.getRow() < after.getRow() && before.getCol() > after.getCol()) {
                        temp1 = new Position2D(susPoint.getCol() - 1, susPoint.getRow() - 1);
                        temp2 = new Position2D(susPoint.getCol() + 1, susPoint.getRow() + 1);
                        temp3 = new Position2D(susPoint.getCol() - 1, susPoint.getRow() + 1);
                        temp4 = new Position2D(susPoint.getCol() + 1, susPoint.getRow() - 1);
                    }
                }
                if ((before.equals(temp4) || before.equals(temp3)) && (after.equals(temp4) || after.equals(temp3))) {
                    if (lines.get(otherLine).contains(temp1) && lines.get(otherLine).contains(temp2)) {
                        int index1 = lines.get(otherLine).indexOf(temp1);
                        int index2 = lines.get(otherLine).indexOf(temp2);
                        if (index1 - index2 == 2 || index2 - index1 == 2) {
                            intersectionPositions.get(lineName).add(susPoint);
                            intersectionsWithLines.get(lineName).add(otherLine);

                            for (BusLineInterface.LinesPair item : intersectionOfLinesPair.keySet()) {
                                if (item.getFirstLineName().equals(lineName) && item.getSecondLineName().equals(otherLine)) {
                                    intersectionOfLinesPair.get(item).add(susPoint);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}