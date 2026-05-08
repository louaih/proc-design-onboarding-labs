# Notes for reading through the nyu-core documentation
I will try to give the best explanation according to my understanding of the documentation, but please feel free to correct me if I am wrong.

## 01_Module_Docs

### Module 00: CPU General Purpose Registers
I will try to give the best explanation according to my understanding of the documentation, but please feel free to correct me if I am wrong.

Inputs:
- clk: clock signal, used to synchronize the operations of the CPU.
- rstn_h: active-low reset signal, used to reset the CPU to its initial state.
- rs1n: 5-bit input representing the first source register number.
- rs2n: 5-bit input representing the second source register number.
- rdn: 5-bit input representing the destination register number.
- rdd: 32-bit input representing the data to be written to the destination register.
- wbe: write-back enable signal, used to indicate whether the data should be written back to the register file.

Outputs:
- rs1d: 32-bit output representing the data read from the first source register.
- rs2d: 32-bit output representing the data read from the second source register.

The functionality section was self-explanatory, but I will try to summarize it in my own words. The CPU General Purpose Registers module is responsible for managing the register file of the CPU. It takes in the register numbers and data to be written, and outputs the data read from the source registers. The module also handles the write-back operation when the write-back enable signal is asserted.

### Module 01: IF/ID Latch

Inputs:
- clk: clock signal, used to synchronize the operations of the CPU.
- rstn: active-low reset signal, used to reset the CPU to its initial state.
- immode: 3-bit input representing the immediate mode, used to determine how the immediate value is generated.
- ins: 32-bit input representing the instruction fetched from memory.
- pc_in: 32-bit input representing the program counter value of the instruction being fetched.

Outputs:
- imm: 32-bit output representing the immediate value generated based on the instruction and immediate mode.
- pc: 32-bit output representing the program counter value of the instruction being fetched.
- rdn: 5-bit output representing the destination register number, extracted from the instruction.
- rs1n: 5-bit output representing the first source register number, extracted from the instruction.
- rs2n: 5-bit output representing the second source register number, extracted from the instruction.

Functionality:
The IF/ID Latch module is responsible for holding the instruction and related information between the Instruction Fetch (IF) stage and the Instruction Decode (ID) stage of the CPU pipeline. It takes in the instruction, program counter value, and immediate mode, and outputs the immediate value, program counter value, and register numbers extracted from the instruction. This allows the ID stage to access the necessary information for decoding and executing the instruction.

### From here I will try my best to only define new inputs and outputs but still give a brief explanation of the functionality of the module.

### Module 02: ID/EX Latch
New Inputs:
- a_sel: 2-bit input representing the selection signal for the first operand, used to determine whether to use the register value or the immediate value.
- b_sel: 2-bit input representing the selection signal for the second operand, used to determine whether to use the register value or the immediate value.
- branch_taken_in: 1-bit input representing whether a branch is taken, used to determine the next program counter value.
- rs2d_in: 32-bit input representing the data read from the second source register, used for certain instructions that require the second operand to be read from the register file.
- branch_addr_in: 32-bit input representing the branch target address, used to determine the next program counter value when a branch is taken.

New Outputs:
- branch_taken: 1-bit output representing whether a branch is taken, used to determine the next program counter value.
- branch_addr: 32-bit output representing the branch target address, used to determine the next program counter value when a branch is taken.
- a: 32-bit output representing the first operand, determined based on the a_sel signal.
- b: 32-bit output representing the second operand, determined based on the b_sel signal.
- rs2d: 32-bit output representing the data read from the second source register, used for certain instructions that require the second operand to be read from the register file.

Functionality:
The ID/EX Latch module is responsible for holding the instruction and related information between the Instruction Decode (ID) stage and the Execute (EX) stage of the CPU pipeline. It takes in the immediate value, program counter value, register numbers, and other control signals, and outputs the operands for the EX stage, as well as the branch information. This allows the EX stage to access the necessary information for executing the instruction and determining the next program counter value when a branch is taken.

### Module 03: EX/MEM InLatch

New Inputs: None

New Outputs: None

Functionality:
The EX/MEM InLatch module is responsible for holding the instruction and related information between the Execute (EX) stage and the Memory (MEM) stage of the CPU pipeline. It takes in the operands, branch information, and other control signals from the EX stage, and outputs them to the MEM stage. This allows the MEM stage to access the necessary information for executing memory operations and determining the next program counter value when a branch is taken. The module also includes registers to hold the relevant information and handles the reset operation to initialize the registers to their default values.

### Module 05: General Control Module

New Inputs: None

New Outputs:
- pc_en: 1-bit output representing the program counter enable signal, used to control whether the program counter should be updated.
- addr_mode: 1-bit output representing the address mode, used to determine how the memory address is calculated for load and store instructions.
- branch_occr: 2-bit output representing the branch occurrence signal, used to indicate whether a branch is taken and the type of branch.
- a_sel: 2-bit output representing the selection signal for the first operand, used to determine whether to use the register value or the immediate value.
- b_sel: 2-bit output representing the selection signal for the second operand, used to determine whether to use the register value or the immediate value.
- alu_mode: 6-bit output representing the ALU mode, used to determine the operation performed by the ALU.
- branch_cond: 2-bit output representing the branch condition, used to determine the condition for taking a branch.
- data_mode: 2-bit output representing the data mode, used to determine the size of the data for load and store instructions.
- dcache_rw: 1-bit output representing the data cache read/write signal, used to indicate whether the memory operation is a read or a write.
- dcache_en: 1-bit output representing the data cache enable signal, used to indicate whether the data cache should be accessed.
- wbs: 3-bit output representing the write-back source signal, used to determine the source of the data to be written back to the register file.

Functionality:
The General Control Module is responsible for generating the control signals for the CPU based on the instruction being executed. It uses combinational logic to decode the instruction and determine the appropriate control signals for each stage of the pipeline. The module also includes hazard detection logic to identify potential data hazards and control hazards, and generates a program counter enable signal to stall the pipeline when a hazard is detected. The control signals generated by this module are used to control the operations of the other modules in the CPU, such as the ALU, data cache, and register file.

### Module 06: Branch Evaluator

New Inputs: None

New Outputs:
- act_taken: 1-bit output representing the actual branch taken signal, used to indicate whether the branch condition is met and the branch should be taken.

Functionality:
The Branch Evaluator module is responsible for evaluating the branch condition for branch instructions. It takes in the ALU output and the branch condition signal, and outputs the actual branch taken signal based on the evaluation of the branch condition. The module uses combinational logic to determine whether the branch condition is met and whether the branch should be taken. This information is used by the General Control Module to determine the next program counter value when a branch is taken.

### Module 09: ALU

New Inputs: None

New Outputs: None

Functionality:
The ALU (Arithmetic Logic Unit) module is responsible for performing arithmetic and logical operations based on the ALU mode signal. It takes in the operands and the ALU mode signal, and outputs the result of the operation. The ALU supports a variety of operations, including addition, subtraction, logical shifts, set on less than, bitwise operations, and arithmetic right shift. The specific operation performed by the ALU is determined by the ALU mode signal, which is generated by the General Control Module based on the instruction being executed. The ALU is a critical component of the CPU, as it performs the necessary computations for executing instructions and determining the results of operations.

### Module 10: L1_Data_Cache

New Inputs:
- request_address: 32-bit input representing the address for the current read/write request, used to determine the cache line and block for the operation.
- write_data: 32-bit input representing the data to be written into the cache, used for write operations to update the cache line with the new data.
- mem_response_data: 32-bit input representing the data received from the RAM, used to update the cache line with the data fetched from memory during read operations.
- mem_ready: 1-bit input representing the signal indicating readiness of the RAM, used to determine when the cache can proceed with read/write operations involving the RAM.
- write_enable: 1-bit input representing the enable signal for write operations, used to control whether the cache should perform a write operation to update the cache line with new data.
- read_enable: 1-bit input representing the enable signal for read operations, used to control whether the cache should perform a read operation to fetch data from the cache line or from RAM when a cache miss occurs.

New Outputs:
- response_data: 32-bit output representing the data returned in response to a read operation, used to provide the requested data to the CPU when a read operation is performed.
- c_state: 3-bit output representing the current state of the cache, used for debugging and monitoring purposes to understand the behavior of the cache during read/write operations and cache hits/misses.
- mem_request: 1-bit output representing the signal to request data from RAM, used to indicate when the cache needs to access the RAM for read/write operations due to cache misses or write-backs.

Functionality:
The L1 Data Cache module is responsible for managing the data cache of the CPU. It handles read and write requests from the CPU, checks for cache hits and misses, and interacts with the RAM when necessary. The cache uses a 2-way set associative design with a total size of 4 KB and a block size of 4 bytes. It implements an LRU (Least Recently Used) replacement policy to determine which cache line to evict on a cache miss. The module also includes logic for handling write-back operations when a dirty cache line is evicted, as well as logic for filling the cache with data from RAM on a cache miss. The state machine within the module manages the different states of the cache during read/write operations, ensuring that the correct actions are taken based on whether a hit or miss occurs.
