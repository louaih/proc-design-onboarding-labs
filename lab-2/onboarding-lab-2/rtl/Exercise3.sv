module Exercise3 (
    input clk,
    input nReset,
    input [3:0] a,
    input [15:0] b,
    input [15:0] c,
    output [15:0] out
);

reg [15:0] alpha_d, beta_d, gamma_out;

Mystery1 alpha (
    .a(a),
    .b(b),
    .c(c),
    .d(alpha_d)
);

Mystery1 beta (
    .a(a),
    .b(b),
    .c(c),
    .d(beta_d)
);

Mystery2 gamma (
    .clk(clk),
    .nReset(nReset),
    .a_in(alpha_d),
    .b_in(beta_d),
    .out(gamma_out)
);



assign out = gamma_out;



endmodule
