class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.spots = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.spots[carType] > 0:
            self.spots[carType] -= 1
            return True
        return False


# Test scaffolding
if __name__ == "__main__":
    ps = ParkingSystem(1, 1, 0)
    print(ps.addCar(1), "|", True)
    print(ps.addCar(2), "|", True)
    print(ps.addCar(3), "|", False)
    print(ps.addCar(1), "|", False)
