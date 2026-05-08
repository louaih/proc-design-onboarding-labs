#include <VExercise1.h>

void test_op(uint8_t op, uint8_t a, uint8_t b) {
    VExercise1 dut;
    dut.op = op;
    dut.a = a;
    dut.b = b;
    dut.eval();
    switch (op) {
        case 0:
            assert(dut.out == (a ^ b));
            break;
        case 1:
            assert(dut.out == (a << b));
            break;
        case 2:
            assert(dut.out == (a % b));
            break;
        case 3:
            assert(dut.out == ~(a & b));
            break;
    }
}

int main() {
  // test all operations with all numbers from 0 to 255
  for (uint8_t op = 0; op < 4; op++) {
    for (uint8_t a = 0; a < 255; a++) {
      for (uint8_t b = 0; b < 255; b++) {
        test_op(op, a, b);
      }
    }
  }
  return 0;
}