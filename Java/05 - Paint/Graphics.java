import java.util.LinkedList;
import java.util.List;

public class Graphics implements GraphicsInterface {

    CanvasInterface canvas;
    List<Position> visitedPixels = new LinkedList<>();
    List<Position> reachablePixels = new LinkedList<>();

    @Override
    public void setCanvas(CanvasInterface canvas) {
        this.canvas = canvas;
    }

    @Override
    public void fillWithColor(Position startingPosition, Color color) throws WrongStartingPosition, NoCanvasException {
        // Empty canvas
        if (canvas == null)
            throw new NoCanvasException();

        // Extract color
        Color currentColor;
        try {
            throw new CanvasInterface.BorderColorException(Color.WHITE);
        } catch (CanvasInterface.BorderColorException exception) {
            currentColor = exception.previousColor;
        }

        // Starting point isn't white
        if (currentColor != Color.WHITE)
            throw new WrongStartingPosition();

        try {
            canvas.setColor(startingPosition, color);
        }
        // Starting point out of canvas
        catch (CanvasInterface.CanvasBorderException ignored) {
            throw new WrongStartingPosition();
        }
        // Starting point on border
        catch (CanvasInterface.BorderColorException exception) {
            // Reverse color change
            try {
                canvas.setColor(startingPosition, exception.previousColor);
            } catch (CanvasInterface.BorderColorException | CanvasInterface.CanvasBorderException ignored) {}
            throw new WrongStartingPosition();
        }

        reachablePixels.add(startingPosition);
        boolean painted = false;

        while (!painted) {
            // Get new unused pixel and move it to used list
            Position workingPixel = reachablePixels.get(0);
            reachablePixels.remove(workingPixel);
            visitedPixels.add(workingPixel);

            try {
                canvas.setColor(workingPixel, color);
            } catch (CanvasInterface.CanvasBorderException ignored) {
            } catch (CanvasInterface.BorderColorException exception) {
                try {
                    canvas.setColor(workingPixel, exception.previousColor);
                } catch (CanvasInterface.CanvasBorderException | CanvasInterface.BorderColorException ignored) {}
            }

            // Consider neighbour pixels and add if there are no exceptions thrown
            Position pixelAbove = movePixel(workingPixel, Direction.Up);
            Position pixelBelow = movePixel(workingPixel, Direction.Down);
            Position pixelRight = movePixel(workingPixel, Direction.Right);
            Position pixelLeft = movePixel(workingPixel, Direction.Left);

            if (!(visitedPixels.contains(pixelAbove)))
                pixelAnalyzer(pixelAbove, color);
            if (!(visitedPixels.contains(pixelBelow)))
                pixelAnalyzer(pixelBelow, color);
            if (!(visitedPixels.contains(pixelRight)))
                pixelAnalyzer(pixelRight, color);
            if (!(visitedPixels.contains(pixelLeft)))
                pixelAnalyzer(pixelLeft, color);

            // If there are no more reachable pixels canvas is painted
            if (reachablePixels.size() == 0) {
                painted = true;
            }
        }
    }

    /**
     * Check if pixel on this position does not return any exceptions.
     * @param position Position of pixel that will be checked.
     * @param color Color that pixel is trying to be painted.
     */
    void pixelAnalyzer(Position position, Color color) {
        boolean good = true;
        try {
            canvas.setColor(position, color);
        } catch (CanvasInterface.CanvasBorderException e) {
            good = false;
        } catch (CanvasInterface.BorderColorException e) {
            good = false;
            try {
                canvas.setColor(position, e.previousColor);
            } catch (CanvasInterface.CanvasBorderException | CanvasInterface.BorderColorException ignored) {}
        }
        if (good) {
            reachablePixels.add(position);
        }
    }

    /**
     * Set new parameters for the pixel.
     * @param position Current position of pixel.
     * @param direction Direction in which pixel will 'go'.
     * @return New coordinates of pixel.
     */
    Position movePixel(Position position, Direction direction) {
        if (direction == Direction.Up)
            return new Position2D(position.getRow() + 1, position.getCol());
        if (direction == Direction.Down)
            return new Position2D(position.getRow() - 1, position.getCol());
        if (direction == Direction.Right)
            return new Position2D(position.getRow(), position.getCol() + 1);
        if (direction == Direction.Left)
            return new Position2D(position.getRow(), position.getCol() - 1);
        return position;
    }

    enum Direction { Up, Down, Right, Left }

    static class Position2D implements Position {
        int row;
        int col;

        public Position2D(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public int getRow() { return row; }

        @Override
        public int getCol() { return col; }

        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Position2D other = (Position2D) obj;
            return col == other.col && row == other.row;
        }
    }
}