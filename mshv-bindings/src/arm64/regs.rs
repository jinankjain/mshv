// Copyright © 2025, Microsoft Corporation
//
// SPDX-License-Identifier: Apache-2.0 OR BSD-3-Clause
//

use zerocopy::{FromBytes, IntoBytes};

#[repr(C, packed)]
#[derive(Debug, Default, Copy, Clone, PartialEq, Eq, IntoBytes, FromBytes)]
#[cfg_attr(feature = "with-serde", derive(Deserialize, Serialize))]
pub struct StandardRegisters {
    pub gpr: [u64; 29usize], // 31 General Purpose Registers
    pub fp: u64,             // Frame Pointer
    pub lr: u64,             // Link Register
    pub sp: u64,             // Stack Pointer
    pub pc: u64,             // Program Counter
    pub pstate: u64,         // Program Status Register
    pub sp_el1: u64,         // Stack Pointer for EL1
    pub elr_el1: u64,        // Exception Link Register for EL1
    pub fpsr: u64,           // Floating point status register
    pub fpcr: u64,           // Floating point control register
                             // Note: Only add fields to the end of this struct otherwise it will
                             // break the get/set_reg function in the Vcpu trait.
}
