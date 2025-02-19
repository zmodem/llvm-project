// RUN: %clang_cc1 -E -dM -triple arm64-apple-none-macho -target-cpu generic %s | FileCheck %s -check-prefix CHECK-64

// CHECK-64: #define __APPLE_CC__
// CHECK-64: #define __APPLE__
// CHECK-64: #define __ARM_64BIT_STATE 1
// CHECK-64-NOT: #define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__
// CHECK-64: #define __MACH__
// CHECK-64-NOT: #define __STDC_NO_THREADS__

// RUN: %clang_cc1 -E -dM -triple thumbv7m-apple-unknown-macho -target-cpu cortex-m3 %s | FileCheck %s -check-prefix CHECK-7M

// CHECK-7M: #define __APPLE_CC__
// CHECK-7M: #define __APPLE__
// CHECK-7M: #define __ARM_ARCH_7M__
// CHECK-7M-NOT: #define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__
// CHECK-7M: #define __MACH__
// CHECK-7M: #define __STDC_NO_THREADS__

// RUN: %clang_cc1 -E -dM -triple thumbv7em-apple-unknown-macho -target-cpu cortex-m4 %s | FileCheck %s -check-prefix CHECK-7EM

// CHECK-7EM: #define __APPLE_CC__
// CHECK-7EM: #define __APPLE__
// CHECK-7EM: #define __ARM_ARCH_7EM__
// CHECK-7EM-NOT: #define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__
// CHECK-7EM: #define __MACH__
// CHECK-7EM: #define __STDC_NO_THREADS__

// RUN: %clang_cc1 -E -dM -triple thumbv6m-apple-unknown-macho -target-cpu cortex-m0 %s | FileCheck %s -check-prefix CHECK-6M

// CHECK-6M: #define __APPLE_CC__
// CHECK-6M: #define __APPLE__
// CHECK-6M: #define __ARM_ARCH_6M__
// CHECK-6M-NOT: #define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__
// CHECK-6M: #define __MACH__
// CHECK-6M: #define __STDC_NO_THREADS__

// RUN: %clang_cc1 -E -dM -triple x86_64-pc-windows-macho -target-cpu x86-64 %s | FileCheck %s -check-prefix CHECK-WINDOWS

// CHECK-WINDOWS: #define __APPLE_CC__
// CHECK-WINDOWS: #define __APPLE__
// CHECK-WINDOWS-NOT: #define __ENVIRONMENT_OS_VERSION_MIN_REQUIRED__
// CHECK-WINDOWS-NOT: #define __MACH__
// CHECK-WINDOWS: #define __STDC_NO_THREADS__
