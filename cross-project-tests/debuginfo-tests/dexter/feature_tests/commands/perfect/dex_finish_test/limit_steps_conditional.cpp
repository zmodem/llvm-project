// Purpose:
//      Test that \DexFinishTest can be used with a condition, so the test exits
//      when the line referenced by \DexFinishTest is stepped on and the given
//      condition (x == 5) is satisfied.
//      Test using the conditional controller (using \DexLimitSteps).
//
// The dbgeng driver doesn't support \DexLimitSteps yet.
// UNSUPPORTED: system-windows
//
// RUN: %dexter_regression_test_cxx_build %s -o %t
// RUN: %dexter_regression_test_run --binary %t -- %s | FileCheck %s
// CHECK: limit_steps_conditional.cpp

int main() {
    for (int x = 0; x < 10; ++x)
        (void)0; // DexLabel('finish_line')
}

// DexLimitSteps(on_line=ref('finish_line'))
// DexFinishTest('x', 5, on_line=ref('finish_line'))
// DexExpectWatchValue('x', 0, 1, 2, 3, 4, 5)
