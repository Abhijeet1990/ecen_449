`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Texas A&M University
// Engineer: Abhijeet Sahu
// 
// Create Date:    23:44:33 02/27/2016 
// Design Name: 
// Module Name:    coffeecar 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module coffeecar(CoffeeLevel,Status);
	 
	 input [7:0] CoffeeLevel;
	 //status is the output that either outputs coffee price or no coffee
	 output reg Status;
	 //these registers holds the status of the level of coffee in the truck
	 reg V1,V2,V3;
	 //parameter size=3;
	 parameter MSC=2'b00, EVANS=2'b01, WEB=2'b10;
	 //state is the present state
	 reg [1:0] state;
	 //next_state is the next state
	 wire [1:0] next_state;
	 
	 
	 //we continously assign the next_state by calling a fsm function that process state transition
	 assign next_state=fsm(state,CoffeeLevel);
	 
	 //defining the fsm function
	 function [1:0] fsm;
		input [1:0] state;
		input CoffeeLevel;
		//output Status;
		case (state)
		//V1: is high when the coffee level become 100%, the truck is ready to leave MSC and move to evans
		//if it is low it stays in MSC until it fills the truck
		MSC: 
			  if(V1 == 1)
			    fsm=EVANS;
			  else
			    fsm=MSC;  
		//V2: is low when coffee level goes below 50%, the truck goes to WEB from EVANS
		//if it is high it stays in EVANS
		EVANS: 
				 if(V2==1)
				   fsm=EVANS;
				 else
				   fsm=WEB;
		//V3:is high when the truck become empty,truck move from WEB to MSC
		// is low stays in WEB
		WEB: 
		     if(V3==1)
					begin
			     fsm=MSC;
				  
				   end
			  else
			      begin
			     fsm=WEB;
				  
				   end
					
		endcase
		
		endfunction//end of function
		
	always@(*)
		begin
		//if coffee level is 100,V1=1
		if(CoffeeLevel==8'b00000000)
			V3=1;
		else 
			V3=0;
		//if coffee level is >50,V2=1
		if(CoffeeLevel>=8'b00110010)
			V2=1;
		else 
			V2=0;
		//if coffee level is 100,V2=1
		if(CoffeeLevel==8'b01100100)
			V1=1;
		else 
			V1=0;
		
		if(Status == 1)
			$display("Coffee price is $1");
		else 
			$display("No Coffee");
		
		if(V3==1)
			Status =0;
		else 
			Status =1;
	   end
		
		

endmodule
