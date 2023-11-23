package source_code.src;

public class PointN extends Element {

    public double[] points;
    public int dimension;

    public PointN() {
        dimension = 2;
        points = new double[2];
        points[0] = points[1] = 0;
    }

    public PointN(double[] _points) {
        dimension = _points.length;
        points = new double[dimension];
        System.arraycopy(_points, 0, points, 0, dimension);
    }

    public PointN(int dim) {
        dimension = dim;
        points = new double[dimension];
    }

    public void setRandomPoints() {
        for (int i = 0; i < dimension; i++) {
            points[i] = Math.round(Math.random() * 10);
        }
    }

    @Override
    public double norm() {
        double result = 0;
        for (int i = 0; i < dimension; i++) {
            result += Math.pow(points[i], 2);
        }
        return result;
    }

    @Override
    public void print() {
        System.out.println("Dimension = " + dimension);
        System.out.println("Norm = " + norm());
    }
}
