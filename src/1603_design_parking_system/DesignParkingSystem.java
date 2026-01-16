class ParkingSystem {
    private int[] spots;

    public ParkingSystem(int big, int medium, int small) {
        spots = new int[] { 0, big, medium, small };
    }

    public boolean addCar(int carType) {
        if (spots[carType] > 0) {
            spots[carType]--;
            return true;
        }
        return false;
    }
}

public class DesignParkingSystem {
    public static void main(String[] args) {
        ParkingSystem ps = new ParkingSystem(1, 1, 0);
        System.out.println(ps.addCar(1) + " | " + true);
        System.out.println(ps.addCar(2) + " | " + true);
        System.out.println(ps.addCar(3) + " | " + false);
        System.out.println(ps.addCar(1) + " | " + false);
    }
}
