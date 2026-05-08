#include <VExercise3.h>

void tick(VExercise3& model) {
  model.clk = 0;
  model.eval();
}

void tock(VExercise3& model) {
  model.clk = 1;
  model.eval();
}

int main() {
  VExercise3 model;

  // test reset behavior
  model.reset = 1;
  model.a = 0xF;
  model.b = 0xFFFF;
  model.c = 0xFFFF;
  tick(model);
  tock(model);
  assert(model.out == 0);

  // test some specific values
  struct TestCase {
    uint8_t a;
    uint16_t b;
    uint16_t c;
    uint16_t expected_out;
  } test_cases[] = {
      {0x0, 0x0000, 0x0000, 0},
      {0x1, 0x0001, 0x0001, /* expected value */},
      {0x2, 0x00FF, 0x00FF, /* expected value */},
      {0x3, 0x1234, 0x5678, /* expected value */},
      {0x4, 0xFFFF, 0xFFFF, /* expected value */},
      {0x5, 0xAAAA, 0x5555, /* expected value */},
      {0x6, 0x5555, 0xAAAA, /* expected value */},
      {0x7, 0xF00F, 0xF00F, /* expected value */},
      {0x8, 0x1234, 0x4321, /* expected value */},
      {0x9, 0xABCD, 0xDCBA, /* expected value */},
      {0xA, 0x0001, 0xFFFF, /* expected value */},
      {0xB, 0xFFFF, 0x0001, /* expected value */},
      {0xC, 0x7E00, 0x7E00, /* expected value */},
      {0xD, 0x00FE, 0x00FE, /* expected value */},
      {0xE, 0xFE00, 0xFE00, /* expected value */},
      {0xF, 0xFFFF, 0xFFFF, /* expected value */}
};

int main() {
  for (const auto& test : test_cases) {
    model.reset = 0;
    model.a = test.a;
    model.b = test.b;
    model.c = test.c;
    tick(model);
    tock(model);
    assert(model.out == test.expected_out);
  }
  return 0;
}