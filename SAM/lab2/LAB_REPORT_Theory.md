# Lab Report: Theory of Linear Congruential Generators (SAM Lab 2)

## Introduction
Random number generation is important in simulation, statistics, games, security, and algorithm testing. In this lab, pseudo-random numbers are generated using congruential methods. These methods are deterministic, meaning every next value is computed from the previous value by modular arithmetic.

Although the activity text uses the term "LCM," the correct term in random number generation is **LCG (Linear Congruential Generator)**.

## General Congruential Model
A linear congruential generator produces a sequence using:

\[
X_{i+1} = (aX_i + c) \bmod m
\]

Where:
- `X_i` is the current value (state)
- `X_{i+1}` is the next generated value
- `a` is the multiplier
- `c` is the increment
- `m` is the modulus
- `X_0` is the initial seed

Each generated value lies in the range `0` to `m-1`.

## Activity 1 Theory: Generation, Mean, and Variance
In Activity 1, random numbers are generated using the mixed LCG formula above. After generating `n` numbers, two statistical measures are calculated:

1. **Mean**
\[
\mu = \frac{1}{n}\sum_{i=0}^{n-1} X_i
\]

2. **Variance**
\[
\sigma^2 = \frac{1}{n}\sum_{i=0}^{n-1}(X_i - \mu)^2
\]

Mean gives the average value of the sequence, while variance indicates how spread out the generated numbers are around the mean.

For the sample constants (`a = 9`, `c = 3`, `m = 31`, `X_0 = 2`), the sequence starts:
`2, 21, 6, 26, 20, 28, 7, 4, 8, ...`

## Activity 2 Theory: Cycle Length Detection
Because congruential generators are finite-state systems (only `m` possible values), the sequence must eventually repeat. The number of unique values before repetition forms a cycle.

A practical stopping rule is:
- Continue generating values until the initial seed appears again.
- The number of generated values before this repeat is the cycle length.

Cycle length is important because longer cycles generally provide better pseudo-random behavior for repeated use.

## Activity 3 Theory: Additive, Multiplicative, and Mixed Methods
Depending on values of `a` and `c`, the generator type changes:

1. **Additive Congruential Method** (`a = 1` or effectively no multiplication term in simplified classroom form)
\[
X_{i+1} = (X_i + c) \bmod m
\]

2. **Multiplicative Congruential Method** (`c = 0`)
\[
X_{i+1} = (aX_i) \bmod m
\]

3. **Mixed Congruential Method** (`a \neq 0`, `c \neq 0`)
\[
X_{i+1} = (aX_i + c) \bmod m
\]

The program can determine the method from user inputs and apply the corresponding recurrence.

## Activity 4 Theory: Period Analysis for Different Seeds
For multiplicative generation with fixed `a` and `m`, different initial seeds `X_0` can produce different cycle lengths.

Given:
- `a = 13`
- `m = 64`
- `X_0 = 1, 2, 3, 4` (or more user-defined seeds)

The sequence for each seed is generated until a repeated value is detected. The cycle length for each seed is measured, then:
- Minimum cycle length and corresponding seed are reported.
- Maximum cycle length and corresponding seed are reported.

This comparison demonstrates that seed selection affects period quality even when `a` and `m` are unchanged.

## Hull-Dobell Conditions (Theoretical Note)
For a **mixed LCG** to achieve full period `m`, these conditions are required:
1. `gcd(c, m) = 1`
2. Every prime factor of `m` divides `(a - 1)`
3. If `m` is divisible by `4`, then `(a - 1)` is divisible by `4`

These conditions explain why some parameter choices produce long cycles and others produce short, quickly repeating sequences.

## Conclusion
This lab studies pseudo-random number generation using congruential methods and evaluates output quality through cycle length and basic statistics. The activities show that generator parameters (`a`, `c`, `m`) and initial seed (`X_0`) strongly affect repetition behavior, statistical characteristics, and practical suitability of the generated sequence.
