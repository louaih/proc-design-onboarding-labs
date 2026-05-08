/*
The following is a test of this module

module Exercise2 (
    input clk,
    input reset,
    input [15:0] init,
    output logic [15:0] out
);
  always_ff @(negedge clk)
    if (reset) out <= ~init;
    else out <= {out[14:0], out[10] ^ out[8] ^ out[3] ^ out[1]};
endmodule

*/
#include <VExercise2.h>

void tick(VExercise2& model) {
  model.clk = 0;
  model.eval();
}

void tock(VExercise2& model) {
  model.clk = 1;
  model.eval();
}

int main() {
  VExercise2 model;

  // test reset behavior
  model.reset = 1;
  model.init = 0x1234;
  tick(model);
  tock(model);
  assert(model.out == ~0x1234);

  // test all operations with all numbers from 0 to 255
  for (uint16_t init = 0; init < 65535; init++) {
    model.reset = 1;
    model.init = init;
    tick(model);
    tock(model);
    assert(model.out == ~init);
    for (int i = 0; i < 16; i++) {
      tick(model);
      tock(model);
      uint16_t expected = (model.out << 1) | ((model.out >> 10) ^ (model.out >> 8) ^ (model.out >> 3) ^ (model.out >> 1)) & 1;
      assert(model.out == expected);
    }
  }
  return 0;
}
