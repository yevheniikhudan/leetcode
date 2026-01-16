#include <iostream>
using namespace std;

class ParkingSystem {
   public:
    int spots[4];
    ParkingSystem(int big, int medium, int small) {
        spots[1] = big;
        spots[2] = medium;
        spots[3] = small;
    }
    bool addCar(int carType) {
        if (spots[carType] > 0) {
            spots[carType]--;
            return true;
        }
        return false;
    }
};

int main() {
    ParkingSystem ps(1, 1, 0);
    cout << boolalpha;
    cout << ps.addCar(1) << " | " << true << endl;
    cout << ps.addCar(2) << " | " << true << endl;
    cout << ps.addCar(3) << " | " << false << endl;
    cout << ps.addCar(1) << " | " << false << endl;
    return 0;
}
