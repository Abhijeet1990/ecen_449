`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: Texas A&M University
// Engineer: Abhijeet Sahu
//
// Create Date:   00:39:34 02/28/2016
// Design Name:   coffeecar
// Module Name:   H:/AccountSettings/Desktop/assignment/assignment/test.v
// Project Name:  assignment
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: coffeecar
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test;

	// Inputs
	reg [7:0] CoffeeLevel;

	// Outputs
	wire Status;

	// Instantiate the Unit Under Test (UUT)
	coffeecar uut (
		.CoffeeLevel(CoffeeLevel), 
		.Status(Status)
	);

	initial begin
		// Initialize Inputs
		CoffeeLevel = 8'b01100100;

		// Wait 100 ns for global reset to finish
		#100;
		CoffeeLevel =8'b00110011;
		#100;
		CoffeeLevel =8'b00110010;
		#100;
		CoffeeLevel =8'b00110000;
		#100;
      CoffeeLevel =8'b00000000; 
		// Add stimulus here
		#100;
		CoffeeLevel = 8'b01100100;
		#100;
		CoffeeLevel =8'b00110011;
		#100;
		CoffeeLevel =8'b00110010;
		#100;
      CoffeeLevel =8'b00000000; 
		#20;
		#100;
		CoffeeLevel = 8'b01100100;
		#100;
		CoffeeLevel =8'b00110011;
		#100;
		CoffeeLevel =8'b00110010;
		#100;
      CoffeeLevel =8'b00000000; 
	end
      
endmodule

