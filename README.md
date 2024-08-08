# IEEE 754 Floating Point Unit (FPU) Project

This project implements a Floating Point Unit (FPU) based on the IEEE 754 standard for floating-point arithmetic. The FPU supports addition, subtraction, multiplication, and division operations.

## Table of Contents

- [Overview](#overview)
- [Modules](#modules)
- [Features](#features)
- [Results](#results)

## Overview

The IEEE 754 standard is widely used for floating-point arithmetic in computer systems. This project provides an implementation of an FPU that can perform the following operations:
- Addition
- Subtraction
- Multiplication
- Division

The FPU handles special cases such as NaN (Not a Number), infinity, and zero according to the IEEE 754 standard.

## Modules

### fpu_normalize

The `fpu_normalize` module normalizes a 25-bit floating-point value by shifting it appropriately.

**Inputs:**
- `value` (25-bit): The value to be normalized.

**Outputs:**
- `normalized_value` (23-bit): The normalized value.
- `shifted` (5-bit): The amount by which the value was shifted.

### fpu

The `fpu` module is the main floating-point unit that performs the arithmetic operations.

**Inputs:**
- `clk`: Clock signal.
- `start`: Start signal.
- `A` (32-bit): First operand.
- `B` (32-bit): Second operand.
- `mode` (2-bit): Operation mode (00 - Add, 01 - Subtract, 10 - Multiply, 11 - Divide).
- `round_mode`: Rounding mode.

**Outputs:**
- `error`: Error signal.
- `overflow`: Overflow signal.
- `underflow`: Underflow signal.
- `done`: Done signal.
- `Y` (32-bit): Result of the operation.

### top_module

The `top_module` connects the FPU with the clock and reset signals and manages the input and output signals.

**Inputs:**
- `clk`: Clock signal.
- `reset`: Reset signal.
- `A` (32-bit): First operand.
- `B` (32-bit): Second operand.
- `mode` (2-bit): Operation mode.
- `round_mode`: Rounding mode.
- `start`: Start signal.

**Outputs:**
- `error`: Error signal.
- `overflow`: Overflow signal.
- `underflow`: Underflow signal.
- `done`: Done signal.
- `Y` (32-bit): Result of the operation.

## Features

- Supports IEEE 754 standard floating-point addition, subtraction, multiplication, and division.
- Handles special cases such as NaN, infinity, and zero.
- Provides normalization and rounding for accurate results.
- Includes a testbench for validating the FPU functionality.

## Results
The results of the FPU operations are verified through simulations. Below is an example of the waveform generated during the simulation of the FPU:
![waveform](https://github.com/user-attachments/assets/4416f072-1e3d-4606-b946-be2a7f72d07f)

