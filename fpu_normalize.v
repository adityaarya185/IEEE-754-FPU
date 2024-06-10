module fpu_normalize
(
    input [24:0] value,
    output [22:0] normalized_value,
    output [4:0] shifted
);

wire [24:0] initial_value = value;

wire [24:0] shift_layer_1 = initial_value[24:9]  == 0 ? { initial_value[8:0], 16'd0 } : initial_value;
wire [24:0] shift_layer_2 = shift_layer_1[24:17] == 0 ? { shift_layer_1[16:0], 8'd0 } : shift_layer_1;
wire [24:0] shift_layer_3 = shift_layer_2[24:21] == 0 ? { shift_layer_2[20:0], 4'd0 } : shift_layer_2;
wire [24:0] shift_layer_4 = shift_layer_3[24:23] == 0 ? { shift_layer_3[22:0], 2'd0 } : shift_layer_3;
assign normalized_value = shift_layer_4[24] == 0 ? shift_layer_4[22:0] : shift_layer_4[23:1];

assign shifted = { initial_value[24:9] == 0, shift_layer_1[24:17] == 0, shift_layer_2[24:21] == 0, shift_layer_3[24:23] == 0, shift_layer_4[24] == 0 };

endmodule



