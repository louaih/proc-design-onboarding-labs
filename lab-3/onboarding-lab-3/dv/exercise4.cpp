/*
Write a test that reasonably verifies the behavior of the module.

module Exercise4 (
    input [1:0] sel,
    input cs,

    input [7:0] alpha,
    input [7:0] beta,
    input [7:0] gamma,

    output logic [7:0] out
);
  always_comb begin
    if (!cs) out = 0;
    else
      case (sel)
        0: out = alpha;
        1: out = beta;
        2: out = gamma;
        default: out = alpha & (beta | gamma);
      endcase
  end
endmodule

*/

#include <VExercise4.h>

void tick(VExercise4& model) {
  model.clk = 0;
  model.eval();
}

void tock(VExercise4& model) {
  model.clk = 1;
  model.eval();
}

int main() {
  VExercise4 model;

  // test cs = 0
  model.cs = 0;
  model.alpha = 0xFF;
  model.beta = 0xFF;
  model.gamma = 0xFF;
  tick(model);
  tock(model);
  assert(model.out == 0);

  // test sel = 0
  model.cs = 1;
  model.sel = 0;
  tick(model);
  tock(model);
  assert(model.out == model.alpha);

  // test sel = 1
  model.sel = 1;
  tick(model);
  tock(model);
  assert(model.out == model.beta);

  // test sel = 2
  model.sel = 2;
  tick(model);
  tock(model);
  assert(model.out == model.gamma);

  // test sel = default
  model.sel = 3;
  tick(model);
  tock(model);
  assert(model.out == (model.alpha & (model.beta | model.gamma)));

  return 0;
}
