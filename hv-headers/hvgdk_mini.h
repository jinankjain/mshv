/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Type definitions for the hypervisor guest interface to kernel.
 */
#ifndef _UAPI_HV_HVGDK_MINI_H
#define _UAPI_HV_HVGDK_MINI_H

#include <linux/types.h>
#if defined(__KERNEL__)
#include <linux/bits.h>
#endif

#define HVGDK_MINI_H_VERSION		(25294)
typedef __u64 hv_nano100_time_t;	/* HV_NANO100_TIME */

struct hv_u128 {
	__u64 low_part;
	__u64 high_part;
} __packed;

/* NOTE: when adding below, update hv_status_to_string() */
#define HV_STATUS_SUCCESS			    0x0
#define HV_STATUS_INVALID_HYPERCALL_CODE	    0x2
#define HV_STATUS_INVALID_HYPERCALL_INPUT	    0x3
#define HV_STATUS_INVALID_ALIGNMENT		    0x4
#define HV_STATUS_INVALID_PARAMETER		    0x5
#define HV_STATUS_ACCESS_DENIED			    0x6
#define HV_STATUS_INVALID_PARTITION_STATE	    0x7
#define HV_STATUS_OPERATION_DENIED		    0x8
#define HV_STATUS_UNKNOWN_PROPERTY		    0x9
#define HV_STATUS_PROPERTY_VALUE_OUT_OF_RANGE	    0xA
#define HV_STATUS_INSUFFICIENT_MEMORY		    0xB
#define HV_STATUS_INVALID_PARTITION_ID		    0xD
#define HV_STATUS_INVALID_VP_INDEX		    0xE
#define HV_STATUS_NOT_FOUND			    0x10
#define HV_STATUS_INVALID_PORT_ID		    0x11
#define HV_STATUS_INVALID_CONNECTION_ID		    0x12
#define HV_STATUS_INSUFFICIENT_BUFFERS		    0x13
#define HV_STATUS_NOT_ACKNOWLEDGED		    0x14
#define HV_STATUS_INVALID_VP_STATE		    0x15
#define HV_STATUS_NO_RESOURCES			    0x1D
#define HV_STATUS_PROCESSOR_FEATURE_NOT_SUPPORTED   0x20
#define HV_STATUS_INVALID_LP_INDEX		    0x41
#define HV_STATUS_INVALID_REGISTER_VALUE	    0x50
#define HV_STATUS_OPERATION_FAILED		    0x71
#define HV_STATUS_TIME_OUT			    0x78
#define HV_STATUS_CALL_PENDING			    0x79
#define HV_STATUS_VTL_ALREADY_ENABLED		    0x86

/*
 * The Hyper-V TimeRefCount register and the TSC
 * page provide a guest VM clock with 100ns tick rate
 */
#define HV_CLOCK_HZ (NSEC_PER_SEC/100)


/* TODO not in hv headers */

#ifndef BIT
#define BIT(nr)				(1UL << (nr))
#endif

#define HV_LINUX_VENDOR_ID		0x8100
#define HV_HYP_PAGE_SHIFT		12
#define HV_HYP_PAGE_SIZE		BIT(HV_HYP_PAGE_SHIFT)
#define HV_HYP_PAGE_MASK		(~(HV_HYP_PAGE_SIZE - 1))
#define HV_HYP_LARGE_PAGE_SHIFT		21


#define HV_PARTITION_ID_INVALID		((__u64) 0)
#define HV_PARTITION_ID_SELF		((__u64)-1)


/* Hyper-V specific model specific registers (MSRs) */

#if defined(__x86_64__)
/* HV_X64_SYNTHETIC_MSR */
#define HV_X64_MSR_GUEST_OS_ID			0x40000000
#define HV_X64_MSR_HYPERCALL			0x40000001
#define HV_X64_MSR_VP_INDEX			0x40000002
#define HV_X64_MSR_RESET			0x40000003
#define HV_X64_MSR_VP_RUNTIME			0x40000010
#define HV_X64_MSR_TIME_REF_COUNT		0x40000020
#define HV_X64_MSR_REFERENCE_TSC		0x40000021
#define HV_X64_MSR_TSC_FREQUENCY		0x40000022
#define HV_X64_MSR_APIC_FREQUENCY		0x40000023

/* Define the virtual APIC registers */
#define HV_X64_MSR_EOI				0x40000070
#define HV_X64_MSR_ICR				0x40000071
#define HV_X64_MSR_TPR				0x40000072
#define HV_X64_MSR_VP_ASSIST_PAGE		0x40000073

/* Note: derived, not in hvgdk_mini.h */
#define HV_X64_MSR_VP_ASSIST_PAGE_ENABLE	0x00000001
#define HV_X64_MSR_VP_ASSIST_PAGE_ADDRESS_SHIFT	12
#define HV_X64_MSR_VP_ASSIST_PAGE_ADDRESS_MASK	\
		(~((1ull << HV_X64_MSR_VP_ASSIST_PAGE_ADDRESS_SHIFT) - 1))

/* Define synthetic interrupt controller model specific registers. */
#define HV_X64_MSR_SCONTROL			0x40000080
#define HV_X64_MSR_SVERSION			0x40000081
#define HV_X64_MSR_SIEFP			0x40000082
#define HV_X64_MSR_SIMP				0x40000083
#define HV_X64_MSR_EOM				0x40000084
#define HV_X64_MSR_SIRBP			0x40000085
#define HV_X64_MSR_SINT0			0x40000090
#define HV_X64_MSR_SINT1			0x40000091
#define HV_X64_MSR_SINT2			0x40000092
#define HV_X64_MSR_SINT3			0x40000093
#define HV_X64_MSR_SINT4			0x40000094
#define HV_X64_MSR_SINT5			0x40000095
#define HV_X64_MSR_SINT6			0x40000096
#define HV_X64_MSR_SINT7			0x40000097
#define HV_X64_MSR_SINT8			0x40000098
#define HV_X64_MSR_SINT9			0x40000099
#define HV_X64_MSR_SINT10			0x4000009A
#define HV_X64_MSR_SINT11			0x4000009B
#define HV_X64_MSR_SINT12			0x4000009C
#define HV_X64_MSR_SINT13			0x4000009D
#define HV_X64_MSR_SINT14			0x4000009E
#define HV_X64_MSR_SINT15			0x4000009F

/* Define synthetic interrupt controller model specific registers for nested hypervisor */
#define HV_X64_MSR_NESTED_SCONTROL		0x40001080
#define HV_X64_MSR_NESTED_SVERSION		0x40001081
#define HV_X64_MSR_NESTED_SIEFP			0x40001082
#define HV_X64_MSR_NESTED_SIMP			0x40001083
#define HV_X64_MSR_NESTED_EOM			0x40001084
#define HV_X64_MSR_NESTED_SINT0			0x40001090

/*
 * Synthetic Timer MSRs. Four timers per vcpu.
 */
#define HV_X64_MSR_STIMER0_CONFIG		0x400000B0
#define HV_X64_MSR_STIMER0_COUNT		0x400000B1
#define HV_X64_MSR_STIMER1_CONFIG		0x400000B2
#define HV_X64_MSR_STIMER1_COUNT		0x400000B3
#define HV_X64_MSR_STIMER2_CONFIG		0x400000B4
#define HV_X64_MSR_STIMER2_COUNT		0x400000B5
#define HV_X64_MSR_STIMER3_CONFIG		0x400000B6
#define HV_X64_MSR_STIMER3_COUNT		0x400000B7

/* Hyper-V guest idle MSR */
#define HV_X64_MSR_GUEST_IDLE			0x400000F0

/* Hyper-V guest crash notification MSR's */
#define HV_X64_MSR_CRASH_P0			0x40000100
#define HV_X64_MSR_CRASH_P1			0x40000101
#define HV_X64_MSR_CRASH_P2			0x40000102
#define HV_X64_MSR_CRASH_P3			0x40000103
#define HV_X64_MSR_CRASH_P4			0x40000104
#define HV_X64_MSR_CRASH_CTL			0x40000105
/* NOTE: derived, not in hvgdk_mini.h */
#define HV_X64_MSR_CRASH_PARAMS		\
		(1 + (HV_X64_MSR_CRASH_P4 - HV_X64_MSR_CRASH_P0))

#define HV_IPI_LOW_VECTOR	 0x10
#define HV_IPI_HIGH_VECTOR	 0xff

struct hv_reenlightenment_control {
	__u64 vector:8;
	__u64 reserved1:8;
	__u64 enabled:1;
	__u64 reserved2:15;
	__u64 target_vp:32;
}  __packed;

struct hv_tsc_emulation_status {	 /* HV_TSC_EMULATION_STATUS */
	__u64 inprogress:1;
	__u64 reserved:63;
} __packed;

struct hv_tsc_emulation_control {	 /* HV_TSC_INVARIANT_CONTROL */
	__u64 enabled:1;
	__u64 reserved:63;
} __packed;

/* TSC emulation after migration */
#define HV_X64_MSR_REENLIGHTENMENT_CONTROL	0x40000106
#define HV_X64_MSR_TSC_EMULATION_CONTROL	0x40000107
#define HV_X64_MSR_TSC_EMULATION_STATUS		0x40000108
#define HV_X64_MSR_TSC_INVARIANT_CONTROL	0x40000118
#define HV_EXPOSE_INVARIANT_TSC		BIT_ULL(0)

#endif /* __x86_64__ */

struct hv_get_partition_id {	 /* HV_OUTPUT_GET_PARTITION_ID */
	__u64 partition_id;
} __packed;

/* HV_CRASH_CTL_REG_CONTENTS */
#define HV_CRASH_CTL_CRASH_NOTIFY_MSG		 BIT_ULL(62)
#define HV_CRASH_CTL_CRASH_NOTIFY		 BIT_ULL(63)

union hv_reference_tsc_msr {
	__u64 as_uint64;
	struct {
		__u64 enable:1;
		__u64 reserved:11;
		__u64 pfn:52;
	} __packed;
};

/* The maximum number of sparse vCPU banks which can be encoded by 'struct hv_vpset' */
#define HV_MAX_SPARSE_VCPU_BANKS (64)
/* The number of vCPUs in one sparse bank */
#define HV_VCPUS_PER_SPARSE_BANK (64)

/* Some of Hyper-V structs do not use hv_vpset where linux uses them */
struct hv_vpset {	 /* HV_VP_SET */
	__u64 format;
	__u64 valid_bank_mask;
	__u64 bank_contents[];
} __packed;

/*
 * Version info reported by hypervisor
 * Changed to a union for convenience
 */
union hv_hypervisor_version_info {
	struct {
		__u32 build_number;

		__u32 minor_version : 16;
		__u32 major_version : 16;

		__u32 service_pack;

		__u32 service_number : 24;
		__u32 service_branch : 8;
	};
	struct {
		__u32 eax;
		__u32 ebx;
		__u32 ecx;
		__u32 edx;
	};
};

/* HV_CPUID_FUNCTION */
#define HYPERV_CPUID_VENDOR_AND_MAX_FUNCTIONS	0x40000000
#define HYPERV_CPUID_INTERFACE			0x40000001
#define HYPERV_CPUID_VERSION			0x40000002
#define HYPERV_CPUID_FEATURES			0x40000003
#define HYPERV_CPUID_ENLIGHTMENT_INFO		0x40000004
#define HYPERV_CPUID_IMPLEMENT_LIMITS		0x40000005
#define HYPERV_CPUID_CPU_MANAGEMENT_FEATURES	0x40000007
#define HYPERV_CPUID_NESTED_FEATURES		0x4000000A
#define HYPERV_CPUID_ISOLATION_CONFIG		0x4000000C

#define HYPERV_CPUID_VIRT_STACK_INTERFACE	 0x40000081
#define HYPERV_VS_INTERFACE_EAX_SIGNATURE	 0x31235356  /* "VS#1" */

#define HYPERV_CPUID_VIRT_STACK_PROPERTIES	 0x40000082
/* Support for the extended IOAPIC RTE format */
#define HYPERV_VS_PROPERTIES_EAX_EXTENDED_IOAPIC_RTE	 BIT(2)

#define HYPERV_HYPERVISOR_PRESENT_BIT		 0x80000000
#define HYPERV_CPUID_MIN			 0x40000005
#define HYPERV_CPUID_MAX			 0x4000ffff


/* HV_PARTITION_PRIVILEGE_MASK */
#define HV_MSR_VP_RUNTIME_AVAILABLE		BIT(0)
#define HV_MSR_TIME_REF_COUNT_AVAILABLE		BIT(1)
#define HV_MSR_SYNIC_AVAILABLE			BIT(2)
#define HV_MSR_SYNTIMER_AVAILABLE		BIT(3)
#define HV_MSR_APIC_ACCESS_AVAILABLE		BIT(4)
#define HV_MSR_HYPERCALL_AVAILABLE		BIT(5)
#define HV_MSR_VP_INDEX_AVAILABLE		BIT(6)
#define HV_MSR_RESET_AVAILABLE			BIT(7)
#define HV_MSR_STAT_PAGES_AVAILABLE		BIT(8)
#define HV_MSR_REFERENCE_TSC_AVAILABLE		BIT(9)
#define HV_MSR_GUEST_IDLE_AVAILABLE		BIT(10)
#define HV_ACCESS_FREQUENCY_MSRS		BIT(11)
#define HV_ACCESS_REENLIGHTENMENT		BIT(13)
#define HV_ACCESS_TSC_INVARIANT			BIT(15)

/* HV_PARTITION_PRIVILEGE_MASK */
#define HV_CREATE_PARTITIONS			BIT(0)
#define HV_ACCESS_PARTITION_ID			BIT(1)
#define HV_ACCESS_MEMORY_POOL			BIT(2)
#define HV_ADJUST_MESSAGE_BUFFERS		BIT(3)
#define HV_POST_MESSAGES			BIT(4)
#define HV_SIGNAL_EVENTS			BIT(5)
#define HV_CREATE_PORT				BIT(6)
#define HV_CONNECT_PORT				BIT(7)
#define HV_ACCESS_STATS				BIT(8)
#define HV_DEBUGGING				BIT(11)
#define HV_CPU_MANAGEMENT			BIT(12)
#define HV_ACCESS_VSM				BIT(16)
#define HV_ACCESS_VP_REGS			BIT(17)
#define HV_ENABLE_EXTENDED_HYPERCALLS		BIT(20)
#define HV_ISOLATION				BIT(22)

#if defined(__x86_64__)
/* HV_X64_HYPERVISOR_FEATURES (EDX) */
#define HV_X64_MWAIT_AVAILABLE				BIT(0)
#define HV_X64_GUEST_DEBUGGING_AVAILABLE		BIT(1)
#define HV_X64_PERF_MONITOR_AVAILABLE			BIT(2)
#define HV_X64_CPU_DYNAMIC_PARTITIONING_AVAILABLE	BIT(3)
#define HV_X64_HYPERCALL_XMM_INPUT_AVAILABLE		BIT(4)
#define HV_X64_GUEST_IDLE_STATE_AVAILABLE		BIT(5)
#define HV_FEATURE_FREQUENCY_MSRS_AVAILABLE		BIT(8)
#define HV_FEATURE_GUEST_CRASH_MSR_AVAILABLE		BIT(10)
#define HV_FEATURE_DEBUG_MSRS_AVAILABLE			BIT(11)
/*
 * Support for returning hypercall output block via XMM
 * registers is available
 */
#define HV_X64_HYPERCALL_XMM_OUTPUT_AVAILABLE		BIT(15)
/* stimer Direct Mode is available */
#define HV_STIMER_DIRECT_MODE_AVAILABLE			BIT(19)

#define HV_DEVICE_DOMAIN_AVAILABLE		BIT(24)
#define HV_S1_DEVICE_DOMAIN_AVAILABLE		BIT(25)

/* HV_X64_ENLIGHTENMENT_INFORMATION */
#define HV_X64_AS_SWITCH_RECOMMENDED			BIT(0)
#define HV_X64_LOCAL_TLB_FLUSH_RECOMMENDED		BIT(1)
#define HV_X64_REMOTE_TLB_FLUSH_RECOMMENDED		BIT(2)
#define HV_X64_APIC_ACCESS_RECOMMENDED			BIT(3)
#define HV_X64_SYSTEM_RESET_RECOMMENDED			BIT(4)
#define HV_X64_RELAXED_TIMING_RECOMMENDED		BIT(5)
#define HV_DEPRECATING_AEOI_RECOMMENDED			BIT(9)
#define HV_X64_CLUSTER_IPI_RECOMMENDED			BIT(10)
#define HV_X64_EX_PROCESSOR_MASKS_RECOMMENDED		BIT(11)
#define HV_X64_HYPERV_NESTED				BIT(12)
#define HV_X64_ENLIGHTENED_VMCS_RECOMMENDED		BIT(14)
#define HV_X64_USE_MMIO_HYPERCALLS			BIT(21)


/* HYPERV_CPUID_ISOLATION_CONFIG.EBX bits. */
#define HV_ISOLATION_TYPE				 GENMASK(3, 0)
#define HV_SHARED_GPA_BOUNDARY_ACTIVE			 BIT(5)
#define HV_SHARED_GPA_BOUNDARY_BITS			 GENMASK(11, 6)

/* HYPERV_CPUID_FEATURES.ECX bits. */
#define HV_VP_DISPATCH_INTERRUPT_INJECTION_AVAILABLE	BIT(9)
#define HV_VP_GHCB_ROOT_MAPPING_AVAILABLE		BIT(10)

enum hv_isolation_type {
	HV_ISOLATION_TYPE_NONE	= 0,	/* HV_PARTITION_ISOLATION_TYPE_NONE */
	HV_ISOLATION_TYPE_VBS	= 1,
	HV_ISOLATION_TYPE_SNP	= 2,
	HV_ISOLATION_TYPE_TDX	= 3
};

union hv_x64_msr_hypercall_contents {
	__u64 as_uint64;
	struct {
		__u64 enable:1;
		__u64 reserved:11;
		__u64 guest_physical_address:52;
	} __packed;
};
#endif /* if defined(__x86_64__) */

#if defined(__aarch64__)
#define HV_FEATURE_GUEST_CRASH_MSR_AVAILABLE	BIT(8)
#define HV_STIMER_DIRECT_MODE_AVAILABLE		BIT(13)
#endif /* #if defined(__aarch64__) */

#if defined(__x86_64__)
#define HV_MAXIMUM_PROCESSORS	    2048
#else
#define HV_MAXIMUM_PROCESSORS	    320
#endif

#define HV_MAX_VP_INDEX			(HV_MAXIMUM_PROCESSORS - 1)
#define HV_VP_INDEX_SELF		((__u32)-2)
#define HV_ANY_VP			((__u32)-1)

union hv_vp_assist_msr_contents {	 /* HV_REGISTER_VP_ASSIST_PAGE */
	__u64 as_uint64;
	struct {
		__u64 enable:1;
		__u64 reserved:11;
		__u64 pfn:52;
	} __packed;
};

/* Declare the various hypercall operations. */
/* HV_CALL_CODE */
#define HVCALL_FLUSH_VIRTUAL_ADDRESS_SPACE	0x0002
#define HVCALL_FLUSH_VIRTUAL_ADDRESS_LIST	0x0003
#define HVCALL_GET_LOGICAL_PROCESSOR_RUN_TIME	0x0004
#define HVCALL_NOTIFY_LONG_SPIN_WAIT		0x0008
#define HVCALL_SEND_IPI				0x000b
#define HVCALL_ENABLE_VP_VTL			0x000f
#define HVCALL_FLUSH_VIRTUAL_ADDRESS_SPACE_EX	0x0013
#define HVCALL_FLUSH_VIRTUAL_ADDRESS_LIST_EX	0x0014
#define HVCALL_SEND_IPI_EX			0x0015
#define HVCALL_CREATE_PARTITION			0x0040
#define HVCALL_INITIALIZE_PARTITION		0x0041
#define HVCALL_FINALIZE_PARTITION		0x0042
#define HVCALL_DELETE_PARTITION			0x0043
#define HVCALL_GET_PARTITION_PROPERTY		0x0044
#define HVCALL_SET_PARTITION_PROPERTY		0x0045
#define HVCALL_GET_PARTITION_ID			0x0046
#define HVCALL_DEPOSIT_MEMORY			0x0048
#define HVCALL_WITHDRAW_MEMORY			0x0049
#define HVCALL_MAP_GPA_PAGES			0x004b
#define HVCALL_UNMAP_GPA_PAGES			0x004c
#define HVCALL_INSTALL_INTERCEPT		0x004d
#define HVCALL_CREATE_VP			0x004e
#define HVCALL_DELETE_VP			0x004f
#define HVCALL_GET_VP_REGISTERS			0x0050
#define HVCALL_SET_VP_REGISTERS			0x0051
#define HVCALL_TRANSLATE_VIRTUAL_ADDRESS	0x0052
#define HVCALL_READ_GPA			0x0053
#define HVCALL_WRITE_GPA		0x0054
#define HVCALL_CLEAR_VIRTUAL_INTERRUPT		0x0056
#define HVCALL_DELETE_PORT			0x0058
#define HVCALL_DISCONNECT_PORT			0x005b
#define HVCALL_POST_MESSAGE			0x005c
#define HVCALL_SIGNAL_EVENT			0x005d
#define HVCALL_INITIALIZE_EVENT_LOG_BUFFER_GROUP	0x0060
#define HVCALL_FINALIZE_EVENT_LOG_BUFFER_GROUP	0x0061
#define HVCALL_CREATE_EVENT_LOG_BUFFER		0x0062
#define HVCALL_DELETE_EVENT_LOG_BUFFER		0x0063
#define HVCALL_MAP_EVENT_LOG_BUFFER		0x0064
#define HVCALL_UNMAP_EVENT_LOG_BUFFER		0x0065
#define HVCALL_SET_EVENT_LOG_GROUP_SOURCES	0x0066
#define HVCALL_RELEASE_EVENT_LOG_BUFFER		0x0067
#define HVCALL_FLUSH_EVENT_LOG_BUFFER		0x0068
#define HVCALL_POST_DEBUG_DATA			0x0069
#define HVCALL_RETRIEVE_DEBUG_DATA		0x006a
#define HVCALL_RESET_DEBUG_SESSION		0x006b
#define HVCALL_MAP_STATS_PAGE			0x006c
#define HVCALL_UNMAP_STATS_PAGE			0x006d
#define HVCALL_SET_SYSTEM_PROPERTY		0x006f
#define HVCALL_ADD_LOGICAL_PROCESSOR		0x0076
#define HVCALL_GET_SYSTEM_PROPERTY		0x007b
#define HVCALL_MAP_DEVICE_INTERRUPT		0x007c
#define HVCALL_UNMAP_DEVICE_INTERRUPT		0x007d
#define HVCALL_RETARGET_INTERRUPT		0x007e
#define HVCALL_ATTACH_DEVICE			0x0082
#define HVCALL_DETACH_DEVICE			0x0083
#define HVCALL_ENTER_SLEEP_STATE		0x0084
#define HVCALL_NOTIFY_PARTITION_EVENT		0x0087
#define HVCALL_NOTIFY_PORT_RING_EMPTY		0x008b
#define HVCALL_REGISTER_INTERCEPT_RESULT	0x0091
#define HVCALL_ASSERT_VIRTUAL_INTERRUPT		0x0094
#define HVCALL_CREATE_PORT			0x0095
#define HVCALL_CONNECT_PORT			0x0096
#define HVCALL_START_VP				0x0099
#define HVCALL_GET_VP_ID_FROM_APIC_ID		0x009a
#define HVCALL_FLUSH_GUEST_PHYSICAL_ADDRESS_SPACE 0x00af
#define HVCALL_FLUSH_GUEST_PHYSICAL_ADDRESS_LIST 0x00b0
#define HVCALL_CREATE_DEVICE_DOMAIN		0x00b1
#define HVCALL_ATTACH_DEVICE_DOMAIN		0x00b2
#define HVCALL_MAP_DEVICE_GPA_PAGES		0x00b3
#define HVCALL_UNMAP_DEVICE_GPA_PAGES		0x00b4
#define HVCALL_SIGNAL_EVENT_DIRECT		0x00c0
#define HVCALL_POST_MESSAGE_DIRECT		0x00c1
#define HVCALL_DISPATCH_VP			0x00c2
#define HVCALL_DETACH_DEVICE_DOMAIN		0x00c4
#define HVCALL_DELETE_DEVICE_DOMAIN		0x00c5
#define HVCALL_QUERY_DEVICE_DOMAIN		0x00c6
#define HVCALL_MAP_SPARSE_DEVICE_GPA_PAGES	0x00c7
#define HVCALL_UNMAP_SPARSE_DEVICE_GPA_PAGES	0x00c8
#define HVCALL_GET_GPA_PAGES_ACCESS_STATES	 0x00c9
#define HVCALL_CONFIGURE_DEVICE_DOMAIN		0x00ce
#define HVCALL_FLUSH_DEVICE_DOMAIN		0x00d0
#define HVCALL_ACQUIRE_SPARSE_SPA_PAGE_HOST_ACCESS	0x00d7
#define HVCALL_RELEASE_SPARSE_SPA_PAGE_HOST_ACCESS	0x00d8
#define HVCALL_MAP_VP_STATE_PAGE			0x00e1
#define HVCALL_UNMAP_VP_STATE_PAGE		0x00e2
#define HVCALL_GET_VP_STATE				0x00e3
#define HVCALL_SET_VP_STATE				0x00e4
#define HVCALL_IMPORT_ISOLATED_PAGES		0x00ef
#define HVCALL_COMPLETE_ISOLATED_IMPORT		0x00f1
#define HVCALL_ISSUE_SNP_PSP_GUEST_REQUEST	0x00f2
#define HVCALL_GET_VP_CPUID_VALUES		0x00f4
#define HVCALL_LOG_HYPERVISOR_SYSTEM_CONFIG	0x00f8
#define HVCALL_MMIO_READ			0x0106
#define HVCALL_MMIO_WRITE			0x0107
#define HVCALL_DISABLE_HYP_EX			0x010f

/*
 * Some macros - i.e. GENMASK_ULL and BIT_ULL - are not currently supported by
 * userspace rust bindings generation tool.
 * As the below are not currently needed in userspace, don't export them and
 * avoid the issue altogether for now.
 */
#if defined(__KERNEL__)

/* HV_HYPERCALL_INPUT */
#define HV_HYPERCALL_RESULT_MASK	GENMASK_ULL(15, 0)
#define HV_HYPERCALL_FAST_BIT		BIT(16)
#define HV_HYPERCALL_VARHEAD_OFFSET	17
#define HV_HYPERCALL_NESTED		BIT(31)
#define HV_HYPERCALL_REP_COMP_OFFSET	32
#define HV_HYPERCALL_REP_COMP_1		BIT_ULL(32)
#define HV_HYPERCALL_REP_COMP_MASK	GENMASK_ULL(43, 32)
#define HV_HYPERCALL_REP_START_OFFSET	48
#define HV_HYPERCALL_REP_START_MASK	GENMASK_ULL(59, 48)

#endif /* __KERNEL__ */

/* HvFlushGuestPhysicalAddressSpace hypercalls */
struct hv_guest_mapping_flush {
	__u64 address_space;
	__u64 flags;
} __packed;

/*
 *  HV_MAX_FLUSH_PAGES = "additional_pages" + 1. It's limited
 *  by the bitwidth of "additional_pages" in union hv_gpa_page_range.
 */
#define HV_MAX_FLUSH_PAGES (2048)
#define HV_GPA_PAGE_RANGE_PAGE_SIZE_2MB		0
#define HV_GPA_PAGE_RANGE_PAGE_SIZE_1GB		1

#define HV_FLUSH_ALL_PROCESSORS		 BIT(0)
#define HV_FLUSH_ALL_VIRTUAL_ADDRESS_SPACES	 BIT(1)
#define HV_FLUSH_NON_GLOBAL_MAPPINGS_ONLY	 BIT(2)
#define HV_FLUSH_USE_EXTENDED_RANGE_FORMAT	 BIT(3)

/* HvFlushGuestPhysicalAddressList, HvExtCallMemoryHeatHint hypercall */
union hv_gpa_page_range {
	__u64 address_space;
	struct {
		__u64 additional_pages:11;
		__u64 largepage:1;
		__u64 basepfn:52;
	} page;
	struct {
		__u64 reserved:12;
		__u64 page_size:1;
		__u64 reserved1:8;
		__u64 base_large_pfn:43;
	};
};

#if defined(__KERNEL__)
/*
 * All input flush parameters should be in single page. The max flush
 * count is equal with how many entries of union hv_gpa_page_range can
 * be populated into the input parameter page.
 */
#define HV_MAX_FLUSH_REP_COUNT ((HV_HYP_PAGE_SIZE - 2 * sizeof(__u64)) / \
				sizeof(union hv_gpa_page_range))

struct hv_guest_mapping_flush_list {
	__u64 address_space;
	__u64 flags;
	union hv_gpa_page_range gpa_list[HV_MAX_FLUSH_REP_COUNT];
};

struct hv_tlb_flush {	 /* HV_INPUT_FLUSH_VIRTUAL_ADDRESS_LIST */
	__u64 address_space;
	__u64 flags;
	__u64 processor_mask;
	__u64 gva_list[];
} __packed;

/* HvFlushVirtualAddressSpaceEx, HvFlushVirtualAddressListEx hypercalls */
struct hv_tlb_flush_ex {
	__u64 address_space;
	__u64 flags;
	struct hv_vpset hv_vp_set;
	__u64 gva_list[];
} __packed;

struct ms_hyperv_tsc_page {	 /* HV_REFERENCE_TSC_PAGE */
	volatile __u32 tsc_sequence;
	__u32 reserved1;
	volatile __u64 tsc_scale;
	volatile __s64 tsc_offset;
} __packed;

#endif /* __KERNEL__ */

/* Define the number of synthetic interrupt sources. */
#define HV_SYNIC_SINT_COUNT (16)

/* Hyper-V defined statically assigned SINTs */
#define HV_SYNIC_INTERCEPTION_SINT_INDEX 0x00000000
#define HV_SYNIC_IOMMU_FAULT_SINT_INDEX  0x00000001
#define HV_SYNIC_VMBUS_SINT_INDEX	 0x00000002
#define HV_SYNIC_HAL_HV_TIMER_SINT_INDEX 0x00000003
#define HV_SYNIC_HVL_SHARED_SINT_INDEX	 0x00000004
#define HV_SYNIC_FIRST_UNUSED_SINT_INDEX 0x00000005

/* mshv assigned SINT for doorbell */
#define HV_SYNIC_DOORBELL_SINT_INDEX	 HV_SYNIC_FIRST_UNUSED_SINT_INDEX

#define HV_INTERRUPT_VECTOR_NONE 0xFFFFFFFF

enum hv_interrupt_type {
#if defined(__aarch64__)
	HV_ARM64_INTERRUPT_TYPE_FIXED		= 0x0000,
	HV_ARM64_INTERRUPT_TYPE_MAXIMUM		= 0x0008,
#else
	HV_X64_INTERRUPT_TYPE_FIXED		= 0x0000,
	HV_X64_INTERRUPT_TYPE_LOWESTPRIORITY	= 0x0001,
	HV_X64_INTERRUPT_TYPE_SMI		= 0x0002,
	HV_X64_INTERRUPT_TYPE_REMOTEREAD	= 0x0003,
	HV_X64_INTERRUPT_TYPE_NMI		= 0x0004,
	HV_X64_INTERRUPT_TYPE_INIT		= 0x0005,
	HV_X64_INTERRUPT_TYPE_SIPI		= 0x0006,
	HV_X64_INTERRUPT_TYPE_EXTINT		= 0x0007,
	HV_X64_INTERRUPT_TYPE_LOCALINT0		= 0x0008,
	HV_X64_INTERRUPT_TYPE_LOCALINT1		= 0x0009,
	HV_X64_INTERRUPT_TYPE_MAXIMUM		= 0x000A,
#endif
};

/* Define synthetic interrupt source. */
union hv_synic_sint {
	__u64 as_uint64;
	struct {
#if defined(__aarch64__)
		__u64 vector : 5;
		__u64 reserved1 : 11;
#else
		__u64 vector : 8;
		__u64 reserved1 : 8;
#endif
		__u64 masked : 1;
		__u64 auto_eoi : 1;
		__u64 polling : 1;
		__u64 as_intercept : 1;
		__u64 proxy : 1;
		__u64 reserved2 : 43;
	} __packed;
};


union hv_x64_xsave_xfem_register {
	__u64 as_uint64;
	struct {
		__u32 low_uint32;
		__u32 high_uint32;
	} __packed;
	struct {
		__u64 legacy_x87 : 1;
		__u64 legacy_sse : 1;
		__u64 avx : 1;
		__u64 mpx_bndreg : 1;
		__u64 mpx_bndcsr : 1;
		__u64 avx_512_op_mask : 1;
		__u64 avx_512_zmmhi : 1;
		__u64 avx_512_zmm16_31 : 1;
		__u64 rsvd8_9 : 2;
		__u64 pasid : 1;
		__u64 cet_u : 1;
		__u64 cet_s : 1;
		__u64 rsvd13_16 : 4;
		__u64 xtile_cfg : 1;
		__u64 xtile_data : 1;
		__u64 rsvd19_63 : 45;
	} __packed;
};

/* Synthetic timer configuration */
union hv_stimer_config {	 /* HV_X64_MSR_STIMER_CONFIG_CONTENTS */
	__u64 as_uint64;
	struct {
		__u64 enable:1;
		__u64 periodic:1;
		__u64 lazy:1;
		__u64 auto_enable:1;
		__u64 apic_vector:8;
		__u64 direct_mode:1;
		__u64 reserved_z0:3;
		__u64 sintx:4;
		__u64 reserved_z1:44;
	} __packed;
};

/* Define the number of synthetic timers */
#define HV_SYNIC_STIMER_COUNT	(4)

/* Define port identifier type. */
union hv_port_id {
	__u32 as__u32;
	struct {
		__u32 id : 24;
		__u32 reserved : 8;
	} __packed u; // TODO remove this u
};

#define HV_MESSAGE_SIZE			(256)
#define HV_MESSAGE_PAYLOAD_BYTE_COUNT	(240)
#define HV_MESSAGE_PAYLOAD_QWORD_COUNT	(30)

/* Define hypervisor message types. */
enum hv_message_type {
	HVMSG_NONE				= 0x00000000,

	/* Memory access messages. */
	HVMSG_UNMAPPED_GPA			= 0x80000000,
	HVMSG_GPA_INTERCEPT			= 0x80000001,
	HVMSG_UNACCEPTED_GPA			= 0x80000003,
	HVMSG_GPA_ATTRIBUTE_INTERCEPT		= 0x80000004,

	/* Timer notification messages. */
	HVMSG_TIMER_EXPIRED			= 0x80000010,

	/* Error messages. */
	HVMSG_INVALID_VP_REGISTER_VALUE		= 0x80000020,
	HVMSG_UNRECOVERABLE_EXCEPTION		= 0x80000021,
	HVMSG_UNSUPPORTED_FEATURE		= 0x80000022,

	/*
	 * Opaque intercept message. The original intercept message is only
	 * accessible from the mapped intercept message page.
	 */
	HVMSG_OPAQUE_INTERCEPT			= 0x8000003F,

	/* Trace buffer complete messages. */
	HVMSG_EVENTLOG_BUFFERCOMPLETE		= 0x80000040,

	/* Hypercall intercept */
	HVMSG_HYPERCALL_INTERCEPT		= 0x80000050,

	/* SynIC intercepts */
	HVMSG_SYNIC_EVENT_INTERCEPT		= 0x80000060,
	HVMSG_SYNIC_SINT_INTERCEPT		= 0x80000061,
	HVMSG_SYNIC_SINT_DELIVERABLE	= 0x80000062,

	/* Async call completion intercept */
	HVMSG_ASYNC_CALL_COMPLETION		= 0x80000070,

	/* Root scheduler messages */
	HVMSG_SCHEDULER_VP_SIGNAL_BITSET	= 0x80000100,
	HVMSG_SCHEDULER_VP_SIGNAL_PAIR		= 0x80000101,

	/* Platform-specific processor intercept messages. */
	HVMSG_X64_IO_PORT_INTERCEPT		= 0x80010000,
	HVMSG_X64_MSR_INTERCEPT			= 0x80010001,
	HVMSG_X64_CPUID_INTERCEPT		= 0x80010002,
	HVMSG_X64_EXCEPTION_INTERCEPT		= 0x80010003,
	HVMSG_X64_APIC_EOI			= 0x80010004,
	HVMSG_X64_LEGACY_FP_ERROR		= 0x80010005,
	HVMSG_X64_IOMMU_PRQ			= 0x80010006,
	HVMSG_X64_HALT				= 0x80010007,
	HVMSG_X64_INTERRUPTION_DELIVERABLE	= 0x80010008,
	HVMSG_X64_SIPI_INTERCEPT		= 0x80010009,
	HVMSG_X64_RDTSC_INTERCEPT		= 0x8001000A,
	HVMSG_X64_APIC_SMI_INTERCEPT		= 0x8001000B,
	HVMSG_X64_APIC_INIT_SIPI_INTERCEPT	= 0x8001000D,
	HVMSG_X64_APIC_WRITE_INTERCEPT		= 0x8001000E,
	HVMSG_X64_PROXY_INTERRUPT_INTERCEPT	= 0x8001000F,
	HVMSG_X64_ISOLATION_CTRL_REG_INTERCEPT	= 0x80010010,
	HVMSG_X64_SNP_GUEST_REQUEST_INTERCEPT	= 0x80010011,
	HVMSG_X64_EXCEPTION_TRAP_INTERCEPT	= 0x80010012,
	HVMSG_X64_SEV_VMGEXIT_INTERCEPT		= 0x80010013,

	HVMSG_ARM64_RESET_INTERCEPT = 0x8001000C,
};

/* Define the format of the SIMP register */
union hv_synic_simp {
	__u64 as_uint64;
	struct {
		__u64 simp_enabled : 1;
		__u64 preserved : 11;
		__u64 base_simp_gpa : 52;
	} __packed;
};

union hv_message_flags {
	__u8 asu8;
	struct {
		__u8 msg_pending : 1;
		__u8 reserved : 7;
	} __packed;
};

struct hv_message_header {
	__u32 message_type;
	__u8 payload_size;
	union hv_message_flags message_flags;
	__u8 reserved[2];
	union {
		__u64 sender;
		union hv_port_id port;
	};
} __packed;

/*
 * Message format for notifications delivered via
 * intercept message(as_intercept=1)
 */
struct hv_notification_message_payload {
	__u32 sint_index;
} __packed;

struct hv_message {
	struct hv_message_header header;
	union {
		__u64 payload[HV_MESSAGE_PAYLOAD_QWORD_COUNT];
	} u;
} __packed;

/* Define the synthetic interrupt message page layout. */
struct hv_message_page {
	struct hv_message sint_message[HV_SYNIC_SINT_COUNT];
} __packed;

struct hv_x64_segment_register {
	__u64 base;
	__u32 limit;
	__u16 selector;
	union {
		struct {
			__u16 segment_type : 4;
			__u16 non_system_segment : 1;
			__u16 descriptor_privilege_level : 2;
			__u16 present : 1;
			__u16 reserved : 4;
			__u16 available : 1;
			__u16 _long : 1;
			__u16 _default : 1;
			__u16 granularity : 1;
		} __packed;
		__u16 attributes;
	};
} __packed;

struct hv_x64_table_register {
	__u16 pad[3];
	__u16 limit;
	__u64 base;
} __packed;

union hv_x64_fp_control_status_register {
	struct hv_u128 as_uint128;
	struct {
		__u16 fp_control;
		__u16 fp_status;
		__u8 fp_tag;
		__u8 reserved;
		__u16 last_fp_op;
		union {
			/* long mode */
			__u64 last_fp_rip;
			/* 32 bit mode */
			struct {
				__u32 last_fp_eip;
				__u16 last_fp_cs;
				__u16 padding;
			} __packed;
		};
	} __packed;
} __packed;

union hv_x64_xmm_control_status_register {
	struct hv_u128 as_uint128;
	struct {
		union {
			/* long mode */
			__u64 last_fp_rdp;
			/* 32 bit mode */
			struct {
				__u32 last_fp_dp;
				__u16 last_fp_ds;
				__u16 padding;
			} __packed;
		};
		__u32 xmm_status_control;
		__u32 xmm_status_control_mask;
	} __packed;
} __packed;

union hv_x64_fp_register {
	struct hv_u128 as_uint128;
	struct {
		__u64 mantissa;
		__u64 biased_exponent : 15;
		__u64 sign : 1;
		__u64 reserved : 48;
	} __packed;
} __packed;

union hv_x64_msr_npiep_config_contents {
	__u64 as_uint64;
	struct {
		/*
		 * These bits enable instruction execution prevention for
		 * specific instructions.
		 */
		__u64 prevents_gdt : 1;
		__u64 prevents_idt : 1;
		__u64 prevents_ldt : 1;
		__u64 prevents_tr : 1;

		/* The reserved bits must always be 0. */
		__u64 reserved : 60;
	} __packed;
};

#define HV_NUM_VTLS 3
#define HV_NUM_VTLS_ROOT 2
#define HV_NORMAL_VTL 0
#define HV_VTL_ALL 0xF

union hv_input_vtl {
	__u8 as_uint8;
	struct {
		__u8 target_vtl : 4;
		__u8 use_target_vtl : 1;
		__u8 reserved_z : 3;
	};
} __packed;

struct hv_init_vp_context {
#if defined(CONFIG_ARM64)
	__u64 rsvd[9];
#else /* CONFIG_ARM64 */
	__u64 rip;
	__u64 rsp;
	__u64 rflags;

	struct hv_x64_segment_register cs;
	struct hv_x64_segment_register ds;
	struct hv_x64_segment_register es;
	struct hv_x64_segment_register fs;
	struct hv_x64_segment_register gs;
	struct hv_x64_segment_register ss;
	struct hv_x64_segment_register tr;
	struct hv_x64_segment_register ldtr;

	struct hv_x64_table_register idtr;
	struct hv_x64_table_register gdtr;

	__u64 efer;
	__u64 cr0;
	__u64 cr3;
	__u64 cr4;
	__u64 msr_cr_pat;
#endif /* !CONFIG_ARM64 */
} __packed;

struct hv_enable_vp_vtl {
	__u64				partition_id;
	__u32				vp_index;
	union hv_input_vtl		target_vtl;
	__u8				mbz0;
	__u16				mbz1;
	struct hv_init_vp_context	vp_context;
} __packed;

struct hv_get_vp_from_apic_id_in {
	__u64 partition_id;
	union hv_input_vtl target_vtl;
	__u8 res[7];
	__u32 apic_ids[];
} __packed;

/* Note: not in hvgdk_mini.h */
#if defined(__x86_64__)
#define HV_SUPPORTS_REGISTER_DELIVERABILITY_NOTIFICATIONS
#endif

union hv_register_vsm_partition_config {
	__u64 as_u64;
	struct {
		__u64 enable_vtl_protection : 1;
		__u64 default_vtl_protection_mask : 4;
		__u64 zero_memory_on_reset : 1;
		__u64 deny_lower_vtl_startup : 1;
		__u64 intercept_acceptance : 1;
		__u64 intercept_enable_vtl_protection : 1;
		__u64 intercept_vp_startup : 1;
		__u64 intercept_cpuid_unimplemented : 1;
		__u64 intercept_unrecoverable_exception : 1;
		__u64 intercept_page : 1;
		__u64 intercept_restore_partition_time: 1;
		__u64 intercept_not_present: 1;
		__u64 mbz : 49;
	} __packed;
};

struct hv_nested_enlightenments_control {
	struct {
		__u32 directhypercall : 1;
		__u32 reserved : 31;
	} __packed features;
	struct {
		__u32 inter_partition_comm : 1;
		__u32 reserved : 31;
	} __packed hypercall_controls;
} __packed;

/* Define virtual processor assist page structure. */
struct hv_vp_assist_page {
	__u32 apic_assist;
	__u32 reserved1;
	__u32 vtl_entry_reason;
	__u32 vtl_reserved;
	__u64 vtl_ret_x64rax;
	__u64 vtl_ret_x64rcx;
	struct hv_nested_enlightenments_control nested_control;
	__u8 enlighten_vmentry;
	__u8 reserved2[7];
	__u64 current_nested_vmcs;
	__u8 synthetic_time_unhalted_timer_expired;
	__u8 reserved3[7];
	__u8 virtualization_fault_information[40];
	__u8 reserved4[8];
	__u8 intercept_message[256];
	__u8 vtl_ret_actions[256];
} __packed;

enum hv_register_name {
	/* Suspend Registers */
	HV_REGISTER_EXPLICIT_SUSPEND		= 0x00000000,
	HV_REGISTER_INTERCEPT_SUSPEND		= 0x00000001,
	HV_REGISTER_INSTRUCTION_EMULATION_HINTS	= 0x00000002,
	HV_REGISTER_DISPATCH_SUSPEND		= 0x00000003,
	HV_REGISTER_INTERNAL_ACTIVITY_STATE	= 0x00000004,

	/* Version */
	HV_REGISTER_HYPERVISOR_VERSION	= 0x00000100, /* 128-bit result same as CPUID 0x40000002 */

	/* Feature Access (registers are 128 bits) - same as CPUID 0x40000003 - 0x4000000B */
	HV_REGISTER_PRIVILEGES_AND_FEATURES_INFO	= 0x00000200,
	HV_REGISTER_FEATURES_INFO			= 0x00000201,
	HV_REGISTER_IMPLEMENTATION_LIMITS_INFO		= 0x00000202,
	HV_REGISTER_HARDWARE_FEATURES_INFO		= 0x00000203,
	HV_REGISTER_CPU_MANAGEMENT_FEATURES_INFO	= 0x00000204,
	HV_REGISTER_SVM_FEATURES_INFO			= 0x00000205,
	HV_REGISTER_SKIP_LEVEL_FEATURES_INFO		= 0x00000206,
	HV_REGISTER_NESTED_VIRT_FEATURES_INFO		= 0x00000207,
	HV_REGISTER_IPT_FEATURES_INFO			= 0x00000208,

	/* Guest Crash Registers */
	HV_REGISTER_GUEST_CRASH_P0	= 0x00000210,
	HV_REGISTER_GUEST_CRASH_P1	= 0x00000211,
	HV_REGISTER_GUEST_CRASH_P2	= 0x00000212,
	HV_REGISTER_GUEST_CRASH_P3	= 0x00000213,
	HV_REGISTER_GUEST_CRASH_P4	= 0x00000214,
	HV_REGISTER_GUEST_CRASH_CTL	= 0x00000215,

	/* Power State Configuration */
	HV_REGISTER_POWER_STATE_CONFIG_C1	= 0x00000220,
	HV_REGISTER_POWER_STATE_TRIGGER_C1	= 0x00000221,
	HV_REGISTER_POWER_STATE_CONFIG_C2	= 0x00000222,
	HV_REGISTER_POWER_STATE_TRIGGER_C2	= 0x00000223,
	HV_REGISTER_POWER_STATE_CONFIG_C3	= 0x00000224,
	HV_REGISTER_POWER_STATE_TRIGGER_C3	= 0x00000225,

	/* Frequency Registers */
	HV_REGISTER_PROCESSOR_CLOCK_FREQUENCY	= 0x00000240,
	HV_REGISTER_INTERRUPT_CLOCK_FREQUENCY	= 0x00000241,

	/* Idle Register */
	HV_REGISTER_GUEST_IDLE	= 0x00000250,

	/* Guest Debug */
	HV_REGISTER_DEBUG_DEVICE_OPTIONS	= 0x00000260,

	/* Memory Zeroing Conrol Register */
	HV_REGISTER_MEMORY_ZEROING_CONTROL	= 0x00000270,

	/* Pending Event Register */
	HV_REGISTER_PENDING_EVENT0	= 0x00010004,
	HV_REGISTER_PENDING_EVENT1	= 0x00010005,
	HV_REGISTER_DELIVERABILITY_NOTIFICATIONS	= 0x00010006,

	/* Misc */
	HV_REGISTER_VP_RUNTIME			= 0x00090000,
	HV_REGISTER_GUEST_OS_ID			= 0x00090002,
	HV_REGISTER_VP_INDEX			= 0x00090003,
	HV_REGISTER_TIME_REF_COUNT		= 0x00090004,
	HV_REGISTER_CPU_MANAGEMENT_VERSION	= 0x00090007,
	HV_REGISTER_VP_ASSIST_PAGE		= 0x00090013,
	HV_REGISTER_VP_ROOT_SIGNAL_COUNT	= 0x00090014,
	HV_REGISTER_REFERENCE_TSC		= 0x00090017,

	/* Performance statistics Registers */
	HV_REGISTER_STATS_PARTITION_RETAIL	= 0x00090020,
	HV_REGISTER_STATS_PARTITION_INTERNAL	= 0x00090021,
	HV_REGISTER_STATS_VP_RETAIL		= 0x00090022,
	HV_REGISTER_STATS_VP_INTERNAL		= 0x00090023,

	HV_REGISTER_NESTED_VP_INDEX	= 0x00091003,

	/* Hypervisor-defined Registers (Synic) */
	HV_REGISTER_SINT0	= 0x000A0000,
	HV_REGISTER_SINT1	= 0x000A0001,
	HV_REGISTER_SINT2	= 0x000A0002,
	HV_REGISTER_SINT3	= 0x000A0003,
	HV_REGISTER_SINT4	= 0x000A0004,
	HV_REGISTER_SINT5	= 0x000A0005,
	HV_REGISTER_SINT6	= 0x000A0006,
	HV_REGISTER_SINT7	= 0x000A0007,
	HV_REGISTER_SINT8	= 0x000A0008,
	HV_REGISTER_SINT9	= 0x000A0009,
	HV_REGISTER_SINT10	= 0x000A000A,
	HV_REGISTER_SINT11	= 0x000A000B,
	HV_REGISTER_SINT12	= 0x000A000C,
	HV_REGISTER_SINT13	= 0x000A000D,
	HV_REGISTER_SINT14	= 0x000A000E,
	HV_REGISTER_SINT15	= 0x000A000F,
	HV_REGISTER_SCONTROL	= 0x000A0010,
	HV_REGISTER_SVERSION	= 0x000A0011,
	HV_REGISTER_SIEFP	= 0x000A0012,
	HV_REGISTER_SIMP	= 0x000A0013,
	HV_REGISTER_EOM		= 0x000A0014,
	HV_REGISTER_SIRBP	= 0x000A0015,

	HV_REGISTER_NESTED_SINT0	= 0x000A1000,
	HV_REGISTER_NESTED_SINT1	= 0x000A1001,
	HV_REGISTER_NESTED_SINT2	= 0x000A1002,
	HV_REGISTER_NESTED_SINT3	= 0x000A1003,
	HV_REGISTER_NESTED_SINT4	= 0x000A1004,
	HV_REGISTER_NESTED_SINT5	= 0x000A1005,
	HV_REGISTER_NESTED_SINT6	= 0x000A1006,
	HV_REGISTER_NESTED_SINT7	= 0x000A1007,
	HV_REGISTER_NESTED_SINT8	= 0x000A1008,
	HV_REGISTER_NESTED_SINT9	= 0x000A1009,
	HV_REGISTER_NESTED_SINT10	= 0x000A100A,
	HV_REGISTER_NESTED_SINT11	= 0x000A100B,
	HV_REGISTER_NESTED_SINT12	= 0x000A100C,
	HV_REGISTER_NESTED_SINT13	= 0x000A100D,
	HV_REGISTER_NESTED_SINT14	= 0x000A100E,
	HV_REGISTER_NESTED_SINT15	= 0x000A100F,
	HV_REGISTER_NESTED_SCONTROL	= 0x000A1010,
	HV_REGISTER_NESTED_SVERSION	= 0x000A1011,
	HV_REGISTER_NESTED_SIFP		= 0x000A1012,
	HV_REGISTER_NESTED_SIPP		= 0x000A1013,
	HV_REGISTER_NESTED_EOM		= 0x000A1014,
	HV_REGISTER_NESTED_SIRBP	= 0x000a1015,


	/* Hypervisor-defined Registers (Synthetic Timers) */
	HV_REGISTER_STIMER0_CONFIG		= 0x000B0000,
	HV_REGISTER_STIMER0_COUNT		= 0x000B0001,
	HV_REGISTER_STIMER1_CONFIG		= 0x000B0002,
	HV_REGISTER_STIMER1_COUNT		= 0x000B0003,
	HV_REGISTER_STIMER2_CONFIG		= 0x000B0004,
	HV_REGISTER_STIMER2_COUNT		= 0x000B0005,
	HV_REGISTER_STIMER3_CONFIG		= 0x000B0006,
	HV_REGISTER_STIMER3_COUNT		= 0x000B0007,
	HV_REGISTER_STIME_UNHALTED_TIMER_CONFIG	= 0x000B0100,
	HV_REGISTER_STIME_UNHALTED_TIMER_COUNT	= 0x000b0101,

	/* Synthetic VSM registers */

	/* 0x000D0000-1 are available for future use. */
	HV_REGISTER_VSM_CODE_PAGE_OFFSETS	= 0x000D0002,
	HV_REGISTER_VSM_VP_STATUS		= 0x000D0003,
	HV_REGISTER_VSM_PARTITION_STATUS	= 0x000D0004,
	HV_REGISTER_VSM_VINA			= 0x000D0005,
	HV_REGISTER_VSM_CAPABILITIES		= 0x000D0006,
	HV_REGISTER_VSM_PARTITION_CONFIG	= 0x000D0007,

	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL0	= 0x000D0010,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL1	= 0x000D0011,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL2	= 0x000D0012,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL3	= 0x000D0013,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL4	= 0x000D0014,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL5	= 0x000D0015,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL6	= 0x000D0016,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL7	= 0x000D0017,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL8	= 0x000D0018,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL9	= 0x000D0019,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL10	= 0x000D001A,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL11	= 0x000D001B,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL12	= 0x000D001C,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL13	= 0x000D001D,
	HV_REGISTER_VSM_VP_SECURE_CONFIG_VTL14	= 0x000D001E,

	HV_REGISTER_VSM_VP_WAIT_FOR_TLB_LOCK	= 0x000D0020,

	HV_REGISTER_ISOLATION_CAPABILITIES	= 0x000D0100,

#if defined(__x86_64__)
	/* Pending Interruption Register */
	HV_REGISTER_PENDING_INTERRUPTION		= 0x00010002,

	/* Interrupt State register */
	HV_REGISTER_INTERRUPT_STATE			= 0x00010003,

	/* Interruptible notification register */
	HV_X64_REGISTER_DELIVERABILITY_NOTIFICATIONS	= 0x00010006,

	/* Pending debug exceptions register */
	HV_X64_REGISTER_PENDING_DEBUG_EXCEPTION		= 0x00010007,

	/* X64 User-Mode Registers */
	HV_X64_REGISTER_RAX	= 0x00020000,
	HV_X64_REGISTER_RCX	= 0x00020001,
	HV_X64_REGISTER_RDX	= 0x00020002,
	HV_X64_REGISTER_RBX	= 0x00020003,
	HV_X64_REGISTER_RSP	= 0x00020004,
	HV_X64_REGISTER_RBP	= 0x00020005,
	HV_X64_REGISTER_RSI	= 0x00020006,
	HV_X64_REGISTER_RDI	= 0x00020007,
	HV_X64_REGISTER_R8	= 0x00020008,
	HV_X64_REGISTER_R9	= 0x00020009,
	HV_X64_REGISTER_R10	= 0x0002000A,
	HV_X64_REGISTER_R11	= 0x0002000B,
	HV_X64_REGISTER_R12	= 0x0002000C,
	HV_X64_REGISTER_R13	= 0x0002000D,
	HV_X64_REGISTER_R14	= 0x0002000E,
	HV_X64_REGISTER_R15	= 0x0002000F,
	HV_X64_REGISTER_RIP	= 0x00020010,
	HV_X64_REGISTER_RFLAGS	= 0x00020011,

	/* X64 Floating Point and Vector Registers */
	HV_X64_REGISTER_XMM0			= 0x00030000,
	HV_X64_REGISTER_XMM1			= 0x00030001,
	HV_X64_REGISTER_XMM2			= 0x00030002,
	HV_X64_REGISTER_XMM3			= 0x00030003,
	HV_X64_REGISTER_XMM4			= 0x00030004,
	HV_X64_REGISTER_XMM5			= 0x00030005,
	HV_X64_REGISTER_XMM6			= 0x00030006,
	HV_X64_REGISTER_XMM7			= 0x00030007,
	HV_X64_REGISTER_XMM8			= 0x00030008,
	HV_X64_REGISTER_XMM9			= 0x00030009,
	HV_X64_REGISTER_XMM10			= 0x0003000A,
	HV_X64_REGISTER_XMM11			= 0x0003000B,
	HV_X64_REGISTER_XMM12			= 0x0003000C,
	HV_X64_REGISTER_XMM13			= 0x0003000D,
	HV_X64_REGISTER_XMM14			= 0x0003000E,
	HV_X64_REGISTER_XMM15			= 0x0003000F,
	HV_X64_REGISTER_FP_MMX0			= 0x00030010,
	HV_X64_REGISTER_FP_MMX1			= 0x00030011,
	HV_X64_REGISTER_FP_MMX2			= 0x00030012,
	HV_X64_REGISTER_FP_MMX3			= 0x00030013,
	HV_X64_REGISTER_FP_MMX4			= 0x00030014,
	HV_X64_REGISTER_FP_MMX5			= 0x00030015,
	HV_X64_REGISTER_FP_MMX6			= 0x00030016,
	HV_X64_REGISTER_FP_MMX7			= 0x00030017,
	HV_X64_REGISTER_FP_CONTROL_STATUS	= 0x00030018,
	HV_X64_REGISTER_XMM_CONTROL_STATUS	= 0x00030019,

	/* X64 Control Registers */
	HV_X64_REGISTER_CR0	= 0x00040000,
	HV_X64_REGISTER_CR2	= 0x00040001,
	HV_X64_REGISTER_CR3	= 0x00040002,
	HV_X64_REGISTER_CR4	= 0x00040003,
	HV_X64_REGISTER_CR8	= 0x00040004,
	HV_X64_REGISTER_XFEM	= 0x00040005,

	/* X64 Intermediate Control Registers */
	HV_X64_REGISTER_INTERMEDIATE_CR0	= 0x00041000,
	HV_X64_REGISTER_INTERMEDIATE_CR4	= 0x00041003,
	HV_X64_REGISTER_INTERMEDIATE_CR8	= 0x00041004,

	/* X64 Debug Registers */
	HV_X64_REGISTER_DR0	= 0x00050000,
	HV_X64_REGISTER_DR1	= 0x00050001,
	HV_X64_REGISTER_DR2	= 0x00050002,
	HV_X64_REGISTER_DR3	= 0x00050003,
	HV_X64_REGISTER_DR6	= 0x00050004,
	HV_X64_REGISTER_DR7	= 0x00050005,

	/* X64 Segment Registers */
	HV_X64_REGISTER_ES	= 0x00060000,
	HV_X64_REGISTER_CS	= 0x00060001,
	HV_X64_REGISTER_SS	= 0x00060002,
	HV_X64_REGISTER_DS	= 0x00060003,
	HV_X64_REGISTER_FS	= 0x00060004,
	HV_X64_REGISTER_GS	= 0x00060005,
	HV_X64_REGISTER_LDTR	= 0x00060006,
	HV_X64_REGISTER_TR	= 0x00060007,

	/* X64 Table Registers */
	HV_X64_REGISTER_IDTR	= 0x00070000,
	HV_X64_REGISTER_GDTR	= 0x00070001,

	/* X64 Virtualized MSRs */
	HV_X64_REGISTER_TSC		= 0x00080000,
	HV_X64_REGISTER_EFER		= 0x00080001,
	HV_X64_REGISTER_KERNEL_GS_BASE	= 0x00080002,
	HV_X64_REGISTER_APIC_BASE	= 0x00080003,
	HV_X64_REGISTER_PAT		= 0x00080004,
	HV_X64_REGISTER_SYSENTER_CS	= 0x00080005,
	HV_X64_REGISTER_SYSENTER_EIP	= 0x00080006,
	HV_X64_REGISTER_SYSENTER_ESP	= 0x00080007,
	HV_X64_REGISTER_STAR		= 0x00080008,
	HV_X64_REGISTER_LSTAR		= 0x00080009,
	HV_X64_REGISTER_CSTAR		= 0x0008000A,
	HV_X64_REGISTER_SFMASK		= 0x0008000B,
	HV_X64_REGISTER_INITIAL_APIC_ID	= 0x0008000C,

	/* X64 Cache control MSRs */
	HV_X64_REGISTER_MSR_MTRR_CAP		= 0x0008000D,
	HV_X64_REGISTER_MSR_MTRR_DEF_TYPE	= 0x0008000E,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE0	= 0x00080010,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE1	= 0x00080011,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE2	= 0x00080012,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE3	= 0x00080013,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE4	= 0x00080014,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE5	= 0x00080015,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE6	= 0x00080016,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE7	= 0x00080017,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE8	= 0x00080018,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASE9	= 0x00080019,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASEA	= 0x0008001A,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASEB	= 0x0008001B,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASEC	= 0x0008001C,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASED	= 0x0008001D,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASEE	= 0x0008001E,
	HV_X64_REGISTER_MSR_MTRR_PHYS_BASEF	= 0x0008001F,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK0	= 0x00080040,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK1	= 0x00080041,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK2	= 0x00080042,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK3	= 0x00080043,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK4	= 0x00080044,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK5	= 0x00080045,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK6	= 0x00080046,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK7	= 0x00080047,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK8	= 0x00080048,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASK9	= 0x00080049,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKA	= 0x0008004A,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKB	= 0x0008004B,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKC	= 0x0008004C,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKD	= 0x0008004D,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKE	= 0x0008004E,
	HV_X64_REGISTER_MSR_MTRR_PHYS_MASKF	= 0x0008004F,
	HV_X64_REGISTER_MSR_MTRR_FIX64K00000	= 0x00080070,
	HV_X64_REGISTER_MSR_MTRR_FIX16K80000	= 0x00080071,
	HV_X64_REGISTER_MSR_MTRR_FIX16KA0000	= 0x00080072,
	HV_X64_REGISTER_MSR_MTRR_FIX4KC0000	= 0x00080073,
	HV_X64_REGISTER_MSR_MTRR_FIX4KC8000	= 0x00080074,
	HV_X64_REGISTER_MSR_MTRR_FIX4KD0000	= 0x00080075,
	HV_X64_REGISTER_MSR_MTRR_FIX4KD8000	= 0x00080076,
	HV_X64_REGISTER_MSR_MTRR_FIX4KE0000	= 0x00080077,
	HV_X64_REGISTER_MSR_MTRR_FIX4KE8000	= 0x00080078,
	HV_X64_REGISTER_MSR_MTRR_FIX4KF0000	= 0x00080079,
	HV_X64_REGISTER_MSR_MTRR_FIX4KF8000	= 0x0008007A,

	HV_X64_REGISTER_TSC_AUX		= 0x0008007B,
	HV_X64_REGISTER_BNDCFGS		= 0x0008007C,
	HV_X64_REGISTER_DEBUG_CTL	= 0x0008007D,

	/* Available */
	HV_X64_REGISTER_AVAILABLE0008007E	= 0x0008007E,
	HV_X64_REGISTER_AVAILABLE0008007F	= 0x0008007F,

	HV_X64_REGISTER_SGX_LAUNCH_CONTROL0	= 0x00080080,
	HV_X64_REGISTER_SGX_LAUNCH_CONTROL1	= 0x00080081,
	HV_X64_REGISTER_SGX_LAUNCH_CONTROL2	= 0x00080082,
	HV_X64_REGISTER_SGX_LAUNCH_CONTROL3	= 0x00080083,
	HV_X64_REGISTER_SPEC_CTRL		= 0x00080084,
	HV_X64_REGISTER_PRED_CMD		= 0x00080085,
	HV_X64_REGISTER_VIRT_SPEC_CTRL		= 0x00080086,
	HV_X64_REGISTER_TSC_ADJUST		= 0x00080096,

	/* Other MSRs */
	HV_X64_REGISTER_MSR_IA32_MISC_ENABLE		= 0x000800A0,
	HV_X64_REGISTER_IA32_FEATURE_CONTROL		= 0x000800A1,
	HV_X64_REGISTER_IA32_VMX_BASIC			= 0x000800A2,
	HV_X64_REGISTER_IA32_VMX_PINBASED_CTLS		= 0x000800A3,
	HV_X64_REGISTER_IA32_VMX_PROCBASED_CTLS		= 0x000800A4,
	HV_X64_REGISTER_IA32_VMX_EXIT_CTLS		= 0x000800A5,
	HV_X64_REGISTER_IA32_VMX_ENTRY_CTLS		= 0x000800A6,
	HV_X64_REGISTER_IA32_VMX_MISC			= 0x000800A7,
	HV_X64_REGISTER_IA32_VMX_CR0_FIXED0		= 0x000800A8,
	HV_X64_REGISTER_IA32_VMX_CR0_FIXED1		= 0x000800A9,
	HV_X64_REGISTER_IA32_VMX_CR4_FIXED0		= 0x000800AA,
	HV_X64_REGISTER_IA32_VMX_CR4_FIXED1		= 0x000800AB,
	HV_X64_REGISTER_IA32_VMX_VMCS_ENUM		= 0x000800AC,
	HV_X64_REGISTER_IA32_VMX_PROCBASED_CTLS2	= 0x000800AD,
	HV_X64_REGISTER_IA32_VMX_EPT_VPID_CAP		= 0x000800AE,
	HV_X64_REGISTER_IA32_VMX_TRUE_PINBASED_CTLS	= 0x000800AF,
	HV_X64_REGISTER_IA32_VMX_TRUE_PROCBASED_CTLS	= 0x000800B0,
	HV_X64_REGISTER_IA32_VMX_TRUE_EXIT_CTLS		= 0x000800B1,
	HV_X64_REGISTER_IA32_VMX_TRUE_ENTRY_CTLS	= 0x000800B2,

	/* Performance monitoring MSRs */
	HV_X64_REGISTER_PERF_GLOBAL_CTRL	= 0x00081000,
	HV_X64_REGISTER_PERF_GLOBAL_STATUS	= 0x00081001,
	HV_X64_REGISTER_PERF_GLOBAL_IN_USE	= 0x00081002,
	HV_X64_REGISTER_FIXED_CTR_CTRL		= 0x00081003,
	HV_X64_REGISTER_DS_AREA			= 0x00081004,
	HV_X64_REGISTER_PEBS_ENABLE		= 0x00081005,
	HV_X64_REGISTER_PEBS_LD_LAT		= 0x00081006,
	HV_X64_REGISTER_PEBS_FRONTEND		= 0x00081007,
	HV_X64_REGISTER_PERF_EVT_SEL0		= 0x00081100,
	HV_X64_REGISTER_PMC0			= 0x00081200,
	HV_X64_REGISTER_FIXED_CTR0		= 0x00081300,

	HV_X64_REGISTER_LBR_TOS		= 0x00082000,
	HV_X64_REGISTER_LBR_SELECT	= 0x00082001,
	HV_X64_REGISTER_LER_FROM_LIP	= 0x00082002,
	HV_X64_REGISTER_LER_TO_LIP	= 0x00082003,
	HV_X64_REGISTER_LBR_FROM0	= 0x00082100,
	HV_X64_REGISTER_LBR_TO0		= 0x00082200,
	HV_X64_REGISTER_LBR_INFO0	= 0x00083300,

	/* Intel processor trace MSRs */
	HV_X64_REGISTER_RTIT_CTL		= 0x00081008,
	HV_X64_REGISTER_RTIT_STATUS		= 0x00081009,
	HV_X64_REGISTER_RTIT_OUTPUT_BASE	= 0x0008100A,
	HV_X64_REGISTER_RTIT_OUTPUT_MASK_PTRS	= 0x0008100B,
	HV_X64_REGISTER_RTIT_CR3_MATCH		= 0x0008100C,
	HV_X64_REGISTER_RTIT_ADDR0A		= 0x00081400,

	/* RtitAddr0A/B - RtitAddr3A/B occupy 0x00081400-0x00081407. */

	/* X64 Apic registers. These match the equivalent x2APIC MSR offsets. */
	HV_X64_REGISTER_APIC_ID		= 0x00084802,
	HV_X64_REGISTER_APIC_VERSION	= 0x00084803,

	/* Hypervisor-defined registers (Misc) */
	HV_X64_REGISTER_HYPERCALL	= 0x00090001,

	/* X64 Virtual APIC registers synthetic MSRs */
	HV_X64_REGISTER_SYNTHETIC_EOI	= 0x00090010,
	HV_X64_REGISTER_SYNTHETIC_ICR	= 0x00090011,
	HV_X64_REGISTER_SYNTHETIC_TPR	= 0x00090012,

	HV_X64_REGISTER_REG_PAGE	= 0x0009001C,
	HV_X64_REGISTER_GHCB		= 0x00090019,

	/* Partition Timer Assist Registers */
	HV_X64_REGISTER_EMULATED_TIMER_PERIOD	= 0x00090030,
	HV_X64_REGISTER_EMULATED_TIMER_CONTROL	= 0x00090031,
	HV_X64_REGISTER_PM_TIMER_ASSIST		= 0x00090032,

	/* AMD SEV SNP configuration register */
	HV_X64_REGISTER_SEV_CONTROL		= 0x00090040,
	HV_X64_REGISTER_SEV_GHCB_GPA		= 0x00090041,
	HV_X64_REGISTER_SEV_DOORBELL_GPA	= 0x00090042,

	/* Intercept Control Registers */
	HV_X64_REGISTER_CR_INTERCEPT_CONTROL			= 0x000E0000,
	HV_X64_REGISTER_CR_INTERCEPT_CR0_MASK			= 0x000E0001,
	HV_X64_REGISTER_CR_INTERCEPT_CR4_MASK			= 0x000E0002,
	HV_X64_REGISTER_CR_INTERCEPT_IA32_MISC_ENABLE_MASK	= 0x000E0003,

#elif defined(__aarch64__)
	/* AArch64 System Register Descriptions: General-purpose registers */
	HV_ARM64_REGISTER_XZR = 0x0002FFFE,
	HV_ARM64_REGISTER_X0 = 0x00020000,
	HV_ARM64_REGISTER_X1 = 0x00020001,
	HV_ARM64_REGISTER_X2 = 0x00020002,
	HV_ARM64_REGISTER_X3 = 0x00020003,
	HV_ARM64_REGISTER_X4 = 0x00020004,
	HV_ARM64_REGISTER_X5 = 0x00020005,
	HV_ARM64_REGISTER_X6 = 0x00020006,
	HV_ARM64_REGISTER_X7 = 0x00020007,
	HV_ARM64_REGISTER_X8 = 0x00020008,
	HV_ARM64_REGISTER_X9 = 0x00020009,
	HV_ARM64_REGISTER_X10 = 0x0002000A,
	HV_ARM64_REGISTER_X11 = 0x0002000B,
	HV_ARM64_REGISTER_X12 = 0x0002000C,
	HV_ARM64_REGISTER_X13 = 0x0002000D,
	HV_ARM64_REGISTER_X14 = 0x0002000E,
	HV_ARM64_REGISTER_X15 = 0x0002000F,
	HV_ARM64_REGISTER_X16 = 0x00020010,
	HV_ARM64_REGISTER_X17 = 0x00020011,
	HV_ARM64_REGISTER_X18 = 0x00020012,
	HV_ARM64_REGISTER_X19 = 0x00020013,
	HV_ARM64_REGISTER_X20 = 0x00020014,
	HV_ARM64_REGISTER_X21 = 0x00020015,
	HV_ARM64_REGISTER_X22 = 0x00020016,
	HV_ARM64_REGISTER_X23 = 0x00020017,
	HV_ARM64_REGISTER_X24 = 0x00020018,
	HV_ARM64_REGISTER_X25 = 0x00020019,
	HV_ARM64_REGISTER_X26 = 0x0002001A,
	HV_ARM64_REGISTER_X27 = 0x0002001B,
	HV_ARM64_REGISTER_X28 = 0x0002001C,
	HV_ARM64_REGISTER_FP = 0x0002001D,
	HV_ARM64_REGISTER_LR = 0x0002001E,
	HV_ARM64_REGISTER_PC = 0x00020022,

	/* AArch64 System Register Descriptions: Floating-point registers */
	HV_ARM64_REGISTER_Q0 = 0x00030000,
	HV_ARM64_REGISTER_Q1 = 0x00030001,
	HV_ARM64_REGISTER_Q2 = 0x00030002,
	HV_ARM64_REGISTER_Q3 = 0x00030003,
	HV_ARM64_REGISTER_Q4 = 0x00030004,
	HV_ARM64_REGISTER_Q5 = 0x00030005,
	HV_ARM64_REGISTER_Q6 = 0x00030006,
	HV_ARM64_REGISTER_Q7 = 0x00030007,
	HV_ARM64_REGISTER_Q8 = 0x00030008,
	HV_ARM64_REGISTER_Q9 = 0x00030009,
	HV_ARM64_REGISTER_Q10 = 0x0003000A,
	HV_ARM64_REGISTER_Q11 = 0x0003000B,
	HV_ARM64_REGISTER_Q12 = 0x0003000C,
	HV_ARM64_REGISTER_Q13 = 0x0003000D,
	HV_ARM64_REGISTER_Q14 = 0x0003000E,
	HV_ARM64_REGISTER_Q15 = 0x0003000F,
	HV_ARM64_REGISTER_Q16 = 0x00030010,
	HV_ARM64_REGISTER_Q17 = 0x00030011,
	HV_ARM64_REGISTER_Q18 = 0x00030012,
	HV_ARM64_REGISTER_Q19 = 0x00030013,
	HV_ARM64_REGISTER_Q20 = 0x00030014,
	HV_ARM64_REGISTER_Q21 = 0x00030015,
	HV_ARM64_REGISTER_Q22 = 0x00030016,
	HV_ARM64_REGISTER_Q23 = 0x00030017,
	HV_ARM64_REGISTER_Q24 = 0x00030018,
	HV_ARM64_REGISTER_Q25 = 0x00030019,
	HV_ARM64_REGISTER_Q26 = 0x0003001A,
	HV_ARM64_REGISTER_Q27 = 0x0003001B,
	HV_ARM64_REGISTER_Q28 = 0x0003001C,
	HV_ARM64_REGISTER_Q29 = 0x0003001D,
	HV_ARM64_REGISTER_Q30 = 0x0003001E,
	HV_ARM64_REGISTER_Q31 = 0x0003001F,

	/* AArch64 System Register Descriptions: SVE */
	HV_ARM64_REGISTER_Z0 = 0x00030100,
	HV_ARM64_REGISTER_Z1 = 0x00030101,
	HV_ARM64_REGISTER_Z2 = 0x00030102,
	HV_ARM64_REGISTER_Z3 = 0x00030103,
	HV_ARM64_REGISTER_Z4 = 0x00030104,
	HV_ARM64_REGISTER_Z5 = 0x00030105,
	HV_ARM64_REGISTER_Z6 = 0x00030106,
	HV_ARM64_REGISTER_Z7 = 0x00030107,
	HV_ARM64_REGISTER_Z8 = 0x00030108,
	HV_ARM64_REGISTER_Z9 = 0x00030109,
	HV_ARM64_REGISTER_Z10 = 0x0003010A,
	HV_ARM64_REGISTER_Z11 = 0x0003010B,
	HV_ARM64_REGISTER_Z12 = 0x0003010C,
	HV_ARM64_REGISTER_Z13 = 0x0003010D,
	HV_ARM64_REGISTER_Z14 = 0x0003010E,
	HV_ARM64_REGISTER_Z15 = 0x0003010F,
	HV_ARM64_REGISTER_Z16 = 0x00030110,
	HV_ARM64_REGISTER_Z17 = 0x00030111,
	HV_ARM64_REGISTER_Z18 = 0x00030112,
	HV_ARM64_REGISTER_Z19 = 0x00030113,
	HV_ARM64_REGISTER_Z20 = 0x00030114,
	HV_ARM64_REGISTER_Z21 = 0x00030115,
	HV_ARM64_REGISTER_Z22 = 0x00030116,
	HV_ARM64_REGISTER_Z23 = 0x00030117,
	HV_ARM64_REGISTER_Z24 = 0x00030118,
	HV_ARM64_REGISTER_Z25 = 0x00030119,
	HV_ARM64_REGISTER_Z26 = 0x0003011A,
	HV_ARM64_REGISTER_Z27 = 0x0003011B,
	HV_ARM64_REGISTER_Z28 = 0x0003011C,
	HV_ARM64_REGISTER_Z29 = 0x0003011D,
	HV_ARM64_REGISTER_Z30 = 0x0003011E,
	HV_ARM64_REGISTER_Z31 = 0x0003011F,
	HV_ARM64_REGISTER_P0 = 0x00030120,
	HV_ARM64_REGISTER_P1 = 0x00030121,
	HV_ARM64_REGISTER_P2 = 0x00030122,
	HV_ARM64_REGISTER_P3 = 0x00030123,
	HV_ARM64_REGISTER_P4 = 0x00030124,
	HV_ARM64_REGISTER_P5 = 0x00030125,
	HV_ARM64_REGISTER_P6 = 0x00030126,
	HV_ARM64_REGISTER_P7 = 0x00030127,
	HV_ARM64_REGISTER_P8 = 0x00030128,
	HV_ARM64_REGISTER_P9 = 0x00030129,
	HV_ARM64_REGISTER_P10 = 0x0003012A,
	HV_ARM64_REGISTER_P11 = 0x0003012B,
	HV_ARM64_REGISTER_P12 = 0x0003012C,
	HV_ARM64_REGISTER_P13 = 0x0003012D,
	HV_ARM64_REGISTER_P14 = 0x0003012E,
	HV_ARM64_REGISTER_P15 = 0x0003012F,
	HV_ARM64_REGISTER_FFR = 0x00030130,

	/* AArch64 System Register Descriptions: Special-purpose registers */
	HV_ARM64_REGISTER_CURRENT_EL = 0x00021003,
	HV_ARM64_REGISTER_DAIF = 0x00021004,
	HV_ARM64_REGISTER_DIT = 0x00021005,
	HV_ARM64_REGISTER_PSTATE = 0x00020023, // Legacy
	HV_ARM64_REGISTER_ELR_EL1 = 0x00040015, // Legacy
	HV_ARM64_REGISTER_ELR_EL2 = 0x00021001,
	HV_ARM64_REGISTER_ELR_ELX =
		0x0002100C, // ElrEl1 or ElrEl2 depending on current EL.
	HV_ARM64_REGISTER_FPCR = 0x00040012, // Legacy
	HV_ARM64_REGISTER_FPSR = 0x00040013, // Legacy
	HV_ARM64_REGISTER_NZCV = 0x00021006,
	HV_ARM64_REGISTER_PAN = 0x00021007,
	HV_ARM64_REGISTER_SP = 0x0002001F, // Legacy
	HV_ARM64_REGISTER_SP_EL0 = 0x00020020, // Legacy
	HV_ARM64_REGISTER_SP_EL1 = 0x00020021, // Legacy
	HV_ARM64_REGISTER_SP_EL2 = 0x00021000,
	HV_ARM64_REGISTER_SP_SEL = 0x00021008,
	HV_ARM64_REGISTER_SPSR_EL1 = 0x00040014, // Legacy
	HV_ARM64_REGISTER_SPSR_EL2 = 0x00021002,
	HV_ARM64_REGISTER_SPSR_ELX =
		0x0002100D, // SpsrEl1 or SpsrEl2 depending on current EL.
	HV_ARM64_REGISTER_SSBS = 0x00021009,
	HV_ARM64_REGISTER_TCO = 0x0002100A,
	HV_ARM64_REGISTER_UAO = 0x0002100B,

	/* AArch64 System Register Descriptions: ID Registers */
	HV_ARM64_REGISTER_ID_MIDR_EL1 = 0x00022000,
	HV_ARM64_REGISTER_ID_RES01_EL1 = 0x00022001,
	HV_ARM64_REGISTER_ID_RES02_EL1 = 0x00022002,
	HV_ARM64_REGISTER_ID_RES03_EL1 = 0x00022003,
	HV_ARM64_REGISTER_ID_RES04_EL1 = 0x00022004,
	HV_ARM64_REGISTER_ID_MPIDR_EL1 = 0x00022005,
	HV_ARM64_REGISTER_ID_REVIDR_EL1 = 0x00022006,
	HV_ARM64_REGISTER_ID_RES07_EL1 = 0x00022007,
	HV_ARM64_REGISTER_ID_PFR0_EL1 = 0x00022008,
	HV_ARM64_REGISTER_ID_PFR1_EL1 = 0x00022009,
	HV_ARM64_REGISTER_ID_DFR0_EL1 = 0x0002200a,
	HV_ARM64_REGISTER_ID_RES13_EL1 = 0x0002200b,
	HV_ARM64_REGISTER_ID_MMFR0_EL1 = 0x0002200c,
	HV_ARM64_REGISTER_ID_MMFR1_EL1 = 0x0002200d,
	HV_ARM64_REGISTER_ID_MMFR2_EL1 = 0x0002200e,
	HV_ARM64_REGISTER_ID_MMFR3_EL1 = 0x0002200f,
	HV_ARM64_REGISTER_ID_ISAR0_EL1 = 0x00022010,
	HV_ARM64_REGISTER_ID_ISAR1_EL1 = 0x00022011,
	HV_ARM64_REGISTER_ID_ISAR2_EL1 = 0x00022012,
	HV_ARM64_REGISTER_ID_ISAR3_EL1 = 0x00022013,
	HV_ARM64_REGISTER_ID_ISAR4_EL1 = 0x00022014,
	HV_ARM64_REGISTER_ID_ISAR5_EL1 = 0x00022015,
	HV_ARM64_REGISTER_ID_RES26_EL1 = 0x00022016,
	HV_ARM64_REGISTER_ID_RES27_EL1 = 0x00022017,
	HV_ARM64_REGISTER_ID_MVFR0_EL1 = 0x00022018,
	HV_ARM64_REGISTER_ID_MVFR1_EL1 = 0x00022019,
	HV_ARM64_REGISTER_ID_MVFR2_EL1 = 0x0002201a,
	HV_ARM64_REGISTER_ID_RES33_EL1 = 0x0002201b,
	HV_ARM64_REGISTER_ID_PFR2_EL1 = 0x0002201c,
	HV_ARM64_REGISTER_ID_RES35_EL1 = 0x0002201d,
	HV_ARM64_REGISTER_ID_RES36_EL1 = 0x0002201e,
	HV_ARM64_REGISTER_ID_RES37_EL1 = 0x0002201f,
	HV_ARM64_REGISTER_ID_AA64_PFR0_EL1 = 0x00022020,
	HV_ARM64_REGISTER_ID_AA64_PFR1_EL1 = 0x00022021,
	HV_ARM64_REGISTER_ID_AA64_PFR2_EL1 = 0x00022022,
	HV_ARM64_REGISTER_ID_RES43_EL1 = 0x00022023,
	HV_ARM64_REGISTER_ID_AA64_ZFR0_EL1 = 0x00022024,
	HV_ARM64_REGISTER_ID_AA64_SMFR0_EL1 = 0x00022025,
	HV_ARM64_REGISTER_ID_RES46_EL1 = 0x00022026,
	HV_ARM64_REGISTER_ID_RES47_EL1 = 0x00022027,
	HV_ARM64_REGISTER_ID_AA64_DFR0_EL1 = 0x00022028,
	HV_ARM64_REGISTER_ID_AA64_DFR1_EL1 = 0x00022029,
	HV_ARM64_REGISTER_ID_RES52_EL1 = 0x0002202a,
	HV_ARM64_REGISTER_ID_RES53_EL1 = 0x0002202b,
	HV_ARM64_REGISTER_ID_RES54_EL1 = 0x0002202c,
	HV_ARM64_REGISTER_ID_RES55_EL1 = 0x0002202d,
	HV_ARM64_REGISTER_ID_RES56_EL1 = 0x0002202e,
	HV_ARM64_REGISTER_ID_RES57_EL1 = 0x0002202f,
	HV_ARM64_REGISTER_ID_AA64_ISAR0_EL1 = 0x00022030,
	HV_ARM64_REGISTER_ID_AA64_ISAR1_EL1 = 0x00022031,
	HV_ARM64_REGISTER_ID_AA64_ISAR2_EL1 = 0x00022032,
	HV_ARM64_REGISTER_ID_RES63_EL1 = 0x00022033,
	HV_ARM64_REGISTER_ID_RES64_EL1 = 0x00022034,
	HV_ARM64_REGISTER_ID_RES65_EL1 = 0x00022035,
	HV_ARM64_REGISTER_ID_RES66_EL1 = 0x00022036,
	HV_ARM64_REGISTER_ID_RES67_EL1 = 0x00022037,
	HV_ARM64_REGISTER_ID_AA64_MMFR0_EL1 = 0x00022038,
	HV_ARM64_REGISTER_ID_AA64_MMFR1_EL1 = 0x00022039,
	HV_ARM64_REGISTER_ID_AA64_MMFR2_EL1 = 0x0002203a,
	HV_ARM64_REGISTER_ID_AA64_MMFR3_EL1 = 0x0002203b,
	HV_ARM64_REGISTER_ID_AA64_MMFR4_EL1 = 0x0002203c,
	HV_ARM64_REGISTER_ID_RES75_EL1 = 0x0002203d,
	HV_ARM64_REGISTER_ID_RES76_EL1 = 0x0002203e,
	HV_ARM64_REGISTER_ID_RES77_EL1 = 0x0002203f,
	HV_ARM64_REGISTER_ID_RES80_EL1 = 0x00022040,
	HV_ARM64_REGISTER_ID_RES81_EL1 = 0x00022041,
	HV_ARM64_REGISTER_ID_RES82_EL1 = 0x00022042,
	HV_ARM64_REGISTER_ID_RES83_EL1 = 0x00022043,
	HV_ARM64_REGISTER_ID_RES84_EL1 = 0x00022044,
	HV_ARM64_REGISTER_ID_RES85_EL1 = 0x00022045,
	HV_ARM64_REGISTER_ID_RES86_EL1 = 0x00022046,
	HV_ARM64_REGISTER_ID_RES87_EL1 = 0x00022047,
	HV_ARM64_REGISTER_ID_RES90_EL1 = 0x00022048,
	HV_ARM64_REGISTER_ID_RES91_EL1 = 0x00022049,
	HV_ARM64_REGISTER_ID_RES92_EL1 = 0x0002204a,
	HV_ARM64_REGISTER_ID_RES93_EL1 = 0x0002204b,
	HV_ARM64_REGISTER_ID_RES94_EL1 = 0x0002204c,
	HV_ARM64_REGISTER_ID_RES95_EL1 = 0x0002204d,
	HV_ARM64_REGISTER_ID_RES96_EL1 = 0x0002204e,
	HV_ARM64_REGISTER_ID_RES97_EL1 = 0x0002204f,
	HV_ARM64_REGISTER_ID_RES100_EL1 = 0x00022050,
	HV_ARM64_REGISTER_ID_RES101_EL1 = 0x00022051,
	HV_ARM64_REGISTER_ID_RES102_EL1 = 0x00022052,
	HV_ARM64_REGISTER_ID_RES103_EL1 = 0x00022053,
	HV_ARM64_REGISTER_ID_RES104_EL1 = 0x00022054,
	HV_ARM64_REGISTER_ID_RES105_EL1 = 0x00022055,
	HV_ARM64_REGISTER_ID_RES106_EL1 = 0x00022056,
	HV_ARM64_REGISTER_ID_RES107_EL1 = 0x00022057,
	HV_ARM64_REGISTER_ID_RES110_EL1 = 0x00022058,
	HV_ARM64_REGISTER_ID_RES111_EL1 = 0x00022059,
	HV_ARM64_REGISTER_ID_RES112_EL1 = 0x0002205a,
	HV_ARM64_REGISTER_ID_RES113_EL1 = 0x0002205b,
	HV_ARM64_REGISTER_ID_RES114_EL1 = 0x0002205c,
	HV_ARM64_REGISTER_ID_RES115_EL1 = 0x0002205d,
	HV_ARM64_REGISTER_ID_RES116_EL1 = 0x0002205e,
	HV_ARM64_REGISTER_ID_RES117_EL1 = 0x0002205f,
	HV_ARM64_REGISTER_ID_RES120_EL1 = 0x00022060,
	HV_ARM64_REGISTER_ID_RES121_EL1 = 0x00022061,
	HV_ARM64_REGISTER_ID_RES122_EL1 = 0x00022062,
	HV_ARM64_REGISTER_ID_RES123_EL1 = 0x00022063,
	HV_ARM64_REGISTER_ID_RES124_EL1 = 0x00022064,
	HV_ARM64_REGISTER_ID_RES125_EL1 = 0x00022065,
	HV_ARM64_REGISTER_ID_RES126_EL1 = 0x00022066,
	HV_ARM64_REGISTER_ID_RES127_EL1 = 0x00022067,
	HV_ARM64_REGISTER_ID_RES130_EL1 = 0x00022068,
	HV_ARM64_REGISTER_ID_RES131_EL1 = 0x00022069,
	HV_ARM64_REGISTER_ID_RES132_EL1 = 0x0002206a,
	HV_ARM64_REGISTER_ID_RES133_EL1 = 0x0002206b,
	HV_ARM64_REGISTER_ID_RES134_EL1 = 0x0002206c,
	HV_ARM64_REGISTER_ID_RES135_EL1 = 0x0002206d,
	HV_ARM64_REGISTER_ID_RES136_EL1 = 0x0002206e,
	HV_ARM64_REGISTER_ID_RES137_EL1 = 0x0002206f,
	HV_ARM64_REGISTER_ID_RES140_EL1 = 0x00022070,
	HV_ARM64_REGISTER_ID_RES141_EL1 = 0x00022071,
	HV_ARM64_REGISTER_ID_RES142_EL1 = 0x00022072,
	HV_ARM64_REGISTER_ID_RES143_EL1 = 0x00022073,
	HV_ARM64_REGISTER_ID_RES144_EL1 = 0x00022074,
	HV_ARM64_REGISTER_ID_RES145_EL1 = 0x00022075,
	HV_ARM64_REGISTER_ID_RES146_EL1 = 0x00022076,
	HV_ARM64_REGISTER_ID_RES147_EL1 = 0x00022077,
	HV_ARM64_REGISTER_ID_RES150_EL1 = 0x00022078,
	HV_ARM64_REGISTER_ID_RES151_EL1 = 0x00022079,
	HV_ARM64_REGISTER_ID_RES152_EL1 = 0x0002207a,
	HV_ARM64_REGISTER_ID_RES153_EL1 = 0x0002207b,
	HV_ARM64_REGISTER_ID_RES154_EL1 = 0x0002207c,
	HV_ARM64_REGISTER_ID_RES155_EL1 = 0x0002207d,
	HV_ARM64_REGISTER_ID_RES156_EL1 = 0x0002207e,
	HV_ARM64_REGISTER_ID_RES157_EL1 = 0x0002207F,

	/* AArch64 System Register Descriptions: General system control registers */
	HV_ARM64_REGISTER_ACCDATA_EL1 = 0x00040020,
	HV_ARM64_REGISTER_ACTLR_EL1 = 0x00040003,
	HV_ARM64_REGISTER_ACTLR_EL2 = 0x00040021,
	HV_ARM64_REGISTER_AFSR0_EL1 = 0x00040016,
	HV_ARM64_REGISTER_AFSR0_EL2 = 0x00040022,
	HV_ARM64_REGISTER_AFSR0_ELX = 0x00040073,
	HV_ARM64_REGISTER_AFSR1_EL2 = 0x00040023,
	HV_ARM64_REGISTER_AFSR1_ELX = 0x00040074,
	HV_ARM64_REGISTER_AIDR_EL1 = 0x00040024,
	HV_ARM64_REGISTER_AMAIR_EL1 = 0x00040018,
	HV_ARM64_REGISTER_AMAIR_EL2 = 0x00040025,
	HV_ARM64_REGISTER_AMAIR_ELX = 0x00040075,
	HV_ARM64_REGISTER_APD_A_KEY_HI_EL1 = 0x00040026,
	HV_ARM64_REGISTER_APD_A_KEY_LO_EL1 = 0x00040027,
	HV_ARM64_REGISTER_APD_B_KEY_HI_EL1 = 0x00040028,
	HV_ARM64_REGISTER_APD_B_KEY_LO_EL1 = 0x00040029,
	HV_ARM64_REGISTER_APG_A_KEY_HI_EL1 = 0x0004002A,
	HV_ARM64_REGISTER_APG_A_KEY_LO_EL1 = 0x0004002B,
	HV_ARM64_REGISTER_API_A_KEY_HI_EL1 = 0x0004002C,
	HV_ARM64_REGISTER_API_A_KEY_LO_EL1 = 0x0004002D,
	HV_ARM64_REGISTER_API_B_KEY_HI_EL1 = 0x0004002E,
	HV_ARM64_REGISTER_API_B_KEY_LO_EL1 = 0x0004002F,
	HV_ARM64_REGISTER_CCSIDR_EL1 = 0x00040030,
	HV_ARM64_REGISTER_CCSIDR2_EL1 = 0x00040031,
	HV_ARM64_REGISTER_CLIDR_EL1 = 0x00040032,
	HV_ARM64_REGISTER_CONTEXTIDR_EL1 = 0x0004000D,
	HV_ARM64_REGISTER_CONTEXTIDR_EL2 = 0x00040033,
	HV_ARM64_REGISTER_CONTEXTIDR_ELX = 0x00040076,
	HV_ARM64_REGISTER_CPACR_EL1 = 0x00040004,
	HV_ARM64_REGISTER_CPTR_EL2 = 0x00040034,
	HV_ARM64_REGISTER_CPACR_ELX = 0x00040077,
	HV_ARM64_REGISTER_CSSELR_EL1 = 0x00040035,
	HV_ARM64_REGISTER_CTR_EL0 = 0x00040036,
	HV_ARM64_REGISTER_DACR32_EL2 = 0x00040037,
	HV_ARM64_REGISTER_DCZID_EL0 = 0x00040038,
	HV_ARM64_REGISTER_ESR_EL1 = 0x00040008,
	HV_ARM64_REGISTER_ESR_EL2 = 0x00040039,
	HV_ARM64_REGISTER_ESR_ELX = 0x00040078,
	HV_ARM64_REGISTER_FAR_EL1 = 0x00040009,
	HV_ARM64_REGISTER_FAR_EL2 = 0x0004003A,
	HV_ARM64_REGISTER_FAR_ELX = 0x00040079,
	HV_ARM64_REGISTER_FPEXC32_EL2 = 0x0004003B,
	HV_ARM64_REGISTER_GCR_EL1 = 0x0004003C,
	HV_ARM64_REGISTER_GMID_EL1 = 0x0004003D,
	HV_ARM64_REGISTER_HACR_EL2 = 0x0004003E,
	HV_ARM64_REGISTER_HAFGRTR_EL2 = 0x0004003F,
	HV_ARM64_REGISTER_HCR_EL2 = 0x00040040,
	HV_ARM64_REGISTER_HCRX_EL2 = 0x00040041,
	HV_ARM64_REGISTER_HDFGRTR_EL2 = 0x00040042,
	HV_ARM64_REGISTER_HDFGWTR_EL2 = 0x00040043,
	HV_ARM64_REGISTER_HFGITR_EL2 = 0x00040044,
	HV_ARM64_REGISTER_HFGRTR_EL2 = 0x00040045,
	HV_ARM64_REGISTER_HFGWTR_EL2 = 0x00040046,
	HV_ARM64_REGISTER_HPFAR_EL2 = 0x00040047,
	HV_ARM64_REGISTER_HSTR_EL2 = 0x00040048,
	HV_ARM64_REGISTER_IFSR32_EL2 = 0x00040049,
	HV_ARM64_REGISTER_ISR_EL1 = 0x0004004A,
	HV_ARM64_REGISTER_LORC_EL1 = 0x0004004B,
	HV_ARM64_REGISTER_LOREA_EL1 = 0x0004004C,
	HV_ARM64_REGISTER_LORID_EL1 = 0x0004004D,
	HV_ARM64_REGISTER_LORN_EL1 = 0x0004004E,
	HV_ARM64_REGISTER_LORSA_EL1 = 0x0004004F,
	HV_ARM64_REGISTER_MAIR_EL1 = 0x0004000B,
	HV_ARM64_REGISTER_MAIR_EL2 = 0x00040050,
	HV_ARM64_REGISTER_MAIR_ELX = 0x0004007A,
	HV_ARM64_REGISTER_MIDR_EL1 = 0x00040051,
	HV_ARM64_REGISTER_MPIDR_EL1 = 0x00040001,
	HV_ARM64_REGISTER_MVFR0_EL1 = 0x00040052,
	HV_ARM64_REGISTER_MVFR1_EL1 = 0x00040053,
	HV_ARM64_REGISTER_MVFR2_EL1 = 0x00040054,
	HV_ARM64_REGISTER_PAR_EL1 = 0x0004000A,
	HV_ARM64_REGISTER_REVIDR_EL1 = 0x00040055,
	HV_ARM64_REGISTER_RGSR_EL1 = 0x00040056,
	HV_ARM64_REGISTER_RNDR = 0x00040057,
	HV_ARM64_REGISTER_RNDRRS = 0x00040058,
	HV_ARM64_REGISTER_SCTLR_EL1 = 0x00040002,
	HV_ARM64_REGISTER_SCTLR_EL2 = 0x00040059,
	HV_ARM64_REGISTER_SCTLR_ELX = 0x0004007B,
	HV_ARM64_REGISTER_SCXTNUM_EL0 = 0x0004005A,
	HV_ARM64_REGISTER_SCXTNUM_EL1 = 0x0004005B,
	HV_ARM64_REGISTER_SCXTNUM_EL2 = 0x0004005C,
	HV_ARM64_REGISTER_SMCR_EL1 = 0x0004005D,
	HV_ARM64_REGISTER_SMCR_EL2 = 0x0004005E,
	HV_ARM64_REGISTER_SMIDR_EL1 = 0x0004005F,
	HV_ARM64_REGISTER_SMPRI_EL1 = 0x00040060,
	HV_ARM64_REGISTER_SMPRIMAP_EL2 = 0x00040061,
	HV_ARM64_REGISTER_TCR_EL1 = 0x00040007,
	HV_ARM64_REGISTER_TCR_EL2 = 0x00040062,
	HV_ARM64_REGISTER_TCR_ELX = 0x0004007C,
	HV_ARM64_REGISTER_TFSRE0_EL1 = 0x00040063,
	HV_ARM64_REGISTER_TFSR_EL1 = 0x00040064,
	HV_ARM64_REGISTER_TFSR_EL2 = 0x00040065,
	HV_ARM64_REGISTER_TPIDR2_EL0 = 0x00040066,
	HV_ARM64_REGISTER_TPIDR_EL0 = 0x00040011,
	HV_ARM64_REGISTER_TPIDR_EL1 = 0x0004000E,
	HV_ARM64_REGISTER_TPIDR_EL2 = 0x00040067,
	HV_ARM64_REGISTER_TPIDRRO_EL0 = 0x00040010,
	HV_ARM64_REGISTER_TTBR0_EL1 = 0x00040005,
	HV_ARM64_REGISTER_TTBR0_EL2 = 0x00040068,
	HV_ARM64_REGISTER_TTBR0_ELX = 0x0004007D,
	HV_ARM64_REGISTER_TTBR1_EL1 = 0x00040006,
	HV_ARM64_REGISTER_TTBR1_EL2 = 0x0004007E,
	HV_ARM64_REGISTER_TTBR1_ELX = 0x0004007F,
	HV_ARM64_REGISTER_VBAR_EL1 = 0x0004000C,
	HV_ARM64_REGISTER_VBAR_EL2 = 0x00040069,
	HV_ARM64_REGISTER_VBAR_ELX = 0x00040080,
	HV_ARM64_REGISTER_VMPIDR_EL2 = 0x0004006A,
	HV_ARM64_REGISTER_VNCR_EL2 = 0x0004006B,
	HV_ARM64_REGISTER_VPIDR_EL2 = 0x0004006C,
	HV_ARM64_REGISTER_VSTCR_EL2 = 0x0004006D,
	HV_ARM64_REGISTER_VSTTBR_EL2 = 0x0004006E,
	HV_ARM64_REGISTER_VTCR_EL2 = 0x0004006F,
	HV_ARM64_REGISTER_VTTBR_EL2 = 0x00040070,
	HV_ARM64_REGISTER_ZCR_EL1 = 0x00040071,
	HV_ARM64_REGISTER_ZCR_EL2 = 0x00040072,
	HV_ARM64_REGISTER_ZCR_ELX = 0x00040081,

	/* AArch64 System Register Descriptions: Debug Registers */
	HV_ARM64_REGISTER_DBGAUTHSTATUS_EL1 = 0x00050040,
	HV_ARM64_REGISTER_DBGBCR0_EL1 = 0x00050000,
	HV_ARM64_REGISTER_DBGBCR1_EL1 = 0x00050001,
	HV_ARM64_REGISTER_DBGBCR2_EL1 = 0x00050002,
	HV_ARM64_REGISTER_DBGBCR3_EL1 = 0x00050003,
	HV_ARM64_REGISTER_DBGBCR4_EL1 = 0x00050004,
	HV_ARM64_REGISTER_DBGBCR5_EL1 = 0x00050005,
	HV_ARM64_REGISTER_DBGBCR6_EL1 = 0x00050006,
	HV_ARM64_REGISTER_DBGBCR7_EL1 = 0x00050007,
	HV_ARM64_REGISTER_DBGBCR8_EL1 = 0x00050008,
	HV_ARM64_REGISTER_DBGBCR9_EL1 = 0x00050009,
	HV_ARM64_REGISTER_DBGBCR10_EL1 = 0x0005000A,
	HV_ARM64_REGISTER_DBGBCR11_EL1 = 0x0005000B,
	HV_ARM64_REGISTER_DBGBCR12_EL1 = 0x0005000C,
	HV_ARM64_REGISTER_DBGBCR13_EL1 = 0x0005000D,
	HV_ARM64_REGISTER_DBGBCR14_EL1 = 0x0005000E,
	HV_ARM64_REGISTER_DBGBCR15_EL1 = 0x0005000F,
	HV_ARM64_REGISTER_DBGBVR0_EL1 = 0x00050020,
	HV_ARM64_REGISTER_DBGBVR1_EL1 = 0x00050021,
	HV_ARM64_REGISTER_DBGBVR2_EL1 = 0x00050022,
	HV_ARM64_REGISTER_DBGBVR3_EL1 = 0x00050023,
	HV_ARM64_REGISTER_DBGBVR4_EL1 = 0x00050024,
	HV_ARM64_REGISTER_DBGBVR5_EL1 = 0x00050025,
	HV_ARM64_REGISTER_DBGBVR6_EL1 = 0x00050026,
	HV_ARM64_REGISTER_DBGBVR7_EL1 = 0x00050027,
	HV_ARM64_REGISTER_DBGBVR8_EL1 = 0x00050028,
	HV_ARM64_REGISTER_DBGBVR9_EL1 = 0x00050029,
	HV_ARM64_REGISTER_DBGBVR10_EL1 = 0x0005002A,
	HV_ARM64_REGISTER_DBGBVR11_EL1 = 0x0005002B,
	HV_ARM64_REGISTER_DBGBVR12_EL1 = 0x0005002C,
	HV_ARM64_REGISTER_DBGBVR13_EL1 = 0x0005002D,
	HV_ARM64_REGISTER_DBGBVR14_EL1 = 0x0005002E,
	HV_ARM64_REGISTER_DBGBVR15_EL1 = 0x0005002F,
	HV_ARM64_REGISTER_DBGCLAIMCLR_EL1 = 0x00050041,
	HV_ARM64_REGISTER_DBGCLAIMSET_EL1 = 0x00050042,
	HV_ARM64_REGISTER_DBGDTRRX_EL0 = 0x00050043,
	HV_ARM64_REGISTER_DBGDTRTX_EL0 = 0x00050044,
	HV_ARM64_REGISTER_DBGPRCR_EL1 = 0x00050045,
	HV_ARM64_REGISTER_DBGVCR32_EL2 = 0x00050046,
	HV_ARM64_REGISTER_DBGWCR0_EL1 = 0x00050010,
	HV_ARM64_REGISTER_DBGWCR1_EL1 = 0x00050011,
	HV_ARM64_REGISTER_DBGWCR2_EL1 = 0x00050012,
	HV_ARM64_REGISTER_DBGWCR3_EL1 = 0x00050013,
	HV_ARM64_REGISTER_DBGWCR4_EL1 = 0x00050014,
	HV_ARM64_REGISTER_DBGWCR5_EL1 = 0x00050015,
	HV_ARM64_REGISTER_DBGWCR6_EL1 = 0x00050016,
	HV_ARM64_REGISTER_DBGWCR7_EL1 = 0x00050017,
	HV_ARM64_REGISTER_DBGWCR8_EL1 = 0x00050018,
	HV_ARM64_REGISTER_DBGWCR9_EL1 = 0x00050019,
	HV_ARM64_REGISTER_DBGWCR10_EL1 = 0x0005001A,
	HV_ARM64_REGISTER_DBGWCR11_EL1 = 0x0005001B,
	HV_ARM64_REGISTER_DBGWCR12_EL1 = 0x0005001C,
	HV_ARM64_REGISTER_DBGWCR13_EL1 = 0x0005001D,
	HV_ARM64_REGISTER_DBGWCR14_EL1 = 0x0005001E,
	HV_ARM64_REGISTER_DBGWCR15_EL1 = 0x0005001F,
	HV_ARM64_REGISTER_DBGWVR0_EL1 = 0x00050030,
	HV_ARM64_REGISTER_DBGWVR1_EL1 = 0x00050031,
	HV_ARM64_REGISTER_DBGWVR2_EL1 = 0x00050032,
	HV_ARM64_REGISTER_DBGWVR3_EL1 = 0x00050033,
	HV_ARM64_REGISTER_DBGWVR4_EL1 = 0x00050034,
	HV_ARM64_REGISTER_DBGWVR5_EL1 = 0x00050035,
	HV_ARM64_REGISTER_DBGWVR6_EL1 = 0x00050036,
	HV_ARM64_REGISTER_DBGWVR7_EL1 = 0x00050037,
	HV_ARM64_REGISTER_DBGWVR8_EL1 = 0x00050038,
	HV_ARM64_REGISTER_DBGWVR9_EL1 = 0x00050039,
	HV_ARM64_REGISTER_DBGWVR10_EL1 = 0x0005003A,
	HV_ARM64_REGISTER_DBGWVR11_EL1 = 0x0005003B,
	HV_ARM64_REGISTER_DBGWVR12_EL1 = 0x0005003C,
	HV_ARM64_REGISTER_DBGWVR13_EL1 = 0x0005003D,
	HV_ARM64_REGISTER_DBGWVR14_EL1 = 0x0005003E,
	HV_ARM64_REGISTER_DBGWVR15_EL1 = 0x0005003F,
	HV_ARM64_REGISTER_DLR_EL0 = 0x00050047,
	HV_ARM64_REGISTER_DSPSR_EL0 = 0x00050048,
	HV_ARM64_REGISTER_MDCCINT_EL1 = 0x00050049,
	HV_ARM64_REGISTER_MDCCSR_EL0 = 0x0005004A,
	HV_ARM64_REGISTER_MDCR_EL2 = 0x0005004B,
	HV_ARM64_REGISTER_MDRAR_EL1 = 0x0005004C,
	HV_ARM64_REGISTER_MDSCR_EL1 = 0x0005004D,
	HV_ARM64_REGISTER_OSDLR_EL1 = 0x0005004E,
	HV_ARM64_REGISTER_OSDTRRX_EL1 = 0x0005004F,
	HV_ARM64_REGISTER_OSDTRTX_EL1 = 0x00050050,
	HV_ARM64_REGISTER_OSECCR_EL1 = 0x00050051,
	HV_ARM64_REGISTER_OSLAR_EL1 = 0x00050052,
	HV_ARM64_REGISTER_OSLSR_EL1 = 0x00050053,
	HV_ARM64_REGISTER_SDER32_EL2 = 0x00050054,
	HV_ARM64_REGISTER_TRFCR_EL1 = 0x00050055,
	HV_ARM64_REGISTER_TRFCR_EL2 = 0x00050056,
	HV_ARM64_REGISTER_TRFCR_ELX =
		0x00050057, // TrfcrEl1 or TrfcrEl2 depending on current EL.

	/* AArch64 System Register Descriptions: Performance Monitors Registers */
	HV_ARM64_REGISTER_PMCCFILTR_EL0 = 0x00052000,
	HV_ARM64_REGISTER_PMCCNTR_EL0 = 0x00052001,
	HV_ARM64_REGISTER_PMCEID0_EL0 = 0x00052002,
	HV_ARM64_REGISTER_PMCEID1_EL0 = 0x00052003,
	HV_ARM64_REGISTER_PMCNTENCLR_EL0 = 0x00052004,
	HV_ARM64_REGISTER_PMCNTENSET_EL0 = 0x00052005,
	HV_ARM64_REGISTER_PMCR_EL0 = 0x00052006,
	HV_ARM64_REGISTER_PMEVCNTR0_EL0 = 0x00052007,
	HV_ARM64_REGISTER_PMEVCNTR1_EL0 = 0x00052008,
	HV_ARM64_REGISTER_PMEVCNTR2_EL0 = 0x00052009,
	HV_ARM64_REGISTER_PMEVCNTR3_EL0 = 0x0005200A,
	HV_ARM64_REGISTER_PMEVCNTR4_EL0 = 0x0005200B,
	HV_ARM64_REGISTER_PMEVCNTR5_EL0 = 0x0005200C,
	HV_ARM64_REGISTER_PMEVCNTR6_EL0 = 0x0005200D,
	HV_ARM64_REGISTER_PMEVCNTR7_EL0 = 0x0005200E,
	HV_ARM64_REGISTER_PMEVCNTR8_EL0 = 0x0005200F,
	HV_ARM64_REGISTER_PMEVCNTR9_EL0 = 0x00052010,
	HV_ARM64_REGISTER_PMEVCNTR10_EL0 = 0x00052011,
	HV_ARM64_REGISTER_PMEVCNTR11_EL0 = 0x00052012,
	HV_ARM64_REGISTER_PMEVCNTR12_EL0 = 0x00052013,
	HV_ARM64_REGISTER_PMEVCNTR13_EL0 = 0x00052014,
	HV_ARM64_REGISTER_PMEVCNTR14_EL0 = 0x00052015,
	HV_ARM64_REGISTER_PMEVCNTR15_EL0 = 0x00052016,
	HV_ARM64_REGISTER_PMEVCNTR16_EL0 = 0x00052017,
	HV_ARM64_REGISTER_PMEVCNTR17_EL0 = 0x00052018,
	HV_ARM64_REGISTER_PMEVCNTR18_EL0 = 0x00052019,
	HV_ARM64_REGISTER_PMEVCNTR19_EL0 = 0x0005201A,
	HV_ARM64_REGISTER_PMEVCNTR20_EL0 = 0x0005201B,
	HV_ARM64_REGISTER_PMEVCNTR21_EL0 = 0x0005201C,
	HV_ARM64_REGISTER_PMEVCNTR22_EL0 = 0x0005201D,
	HV_ARM64_REGISTER_PMEVCNTR23_EL0 = 0x0005201E,
	HV_ARM64_REGISTER_PMEVCNTR24_EL0 = 0x0005201F,
	HV_ARM64_REGISTER_PMEVCNTR25_EL0 = 0x00052020,
	HV_ARM64_REGISTER_PMEVCNTR26_EL0 = 0x00052021,
	HV_ARM64_REGISTER_PMEVCNTR27_EL0 = 0x00052022,
	HV_ARM64_REGISTER_PMEVCNTR28_EL0 = 0x00052023,
	HV_ARM64_REGISTER_PMEVCNTR29_EL0 = 0x00052024,
	HV_ARM64_REGISTER_PMEVCNTR30_EL0 = 0x00052025,
	HV_ARM64_REGISTER_PMEVTYPER0_EL0 = 0x00052026,
	HV_ARM64_REGISTER_PMEVTYPER1_EL0 = 0x00052027,
	HV_ARM64_REGISTER_PMEVTYPER2_EL0 = 0x00052028,
	HV_ARM64_REGISTER_PMEVTYPER3_EL0 = 0x00052029,
	HV_ARM64_REGISTER_PMEVTYPER4_EL0 = 0x0005202A,
	HV_ARM64_REGISTER_PMEVTYPER5_EL0 = 0x0005202B,
	HV_ARM64_REGISTER_PMEVTYPER6_EL0 = 0x0005202C,
	HV_ARM64_REGISTER_PMEVTYPER7_EL0 = 0x0005202D,
	HV_ARM64_REGISTER_PMEVTYPER8_EL0 = 0x0005202E,
	HV_ARM64_REGISTER_PMEVTYPER9_EL0 = 0x0005202F,
	HV_ARM64_REGISTER_PMEVTYPER10_EL0 = 0x00052030,
	HV_ARM64_REGISTER_PMEVTYPER11_EL0 = 0x00052031,
	HV_ARM64_REGISTER_PMEVTYPER12_EL0 = 0x00052032,
	HV_ARM64_REGISTER_PMEVTYPER13_EL0 = 0x00052033,
	HV_ARM64_REGISTER_PMEVTYPER14_EL0 = 0x00052034,
	HV_ARM64_REGISTER_PMEVTYPER15_EL0 = 0x00052035,
	HV_ARM64_REGISTER_PMEVTYPER16_EL0 = 0x00052036,
	HV_ARM64_REGISTER_PMEVTYPER17_EL0 = 0x00052037,
	HV_ARM64_REGISTER_PMEVTYPER18_EL0 = 0x00052038,
	HV_ARM64_REGISTER_PMEVTYPER19_EL0 = 0x00052039,
	HV_ARM64_REGISTER_PMEVTYPER20_EL0 = 0x0005203A,
	HV_ARM64_REGISTER_PMEVTYPER21_EL0 = 0x0005203B,
	HV_ARM64_REGISTER_PMEVTYPER22_EL0 = 0x0005203C,
	HV_ARM64_REGISTER_PMEVTYPER23_EL0 = 0x0005203D,
	HV_ARM64_REGISTER_PMEVTYPER24_EL0 = 0x0005203E,
	HV_ARM64_REGISTER_PMEVTYPER25_EL0 = 0x0005203F,
	HV_ARM64_REGISTER_PMEVTYPER26_EL0 = 0x00052040,
	HV_ARM64_REGISTER_PMEVTYPER27_EL0 = 0x00052041,
	HV_ARM64_REGISTER_PMEVTYPER28_EL0 = 0x00052042,
	HV_ARM64_REGISTER_PMEVTYPER29_EL0 = 0x00052043,
	HV_ARM64_REGISTER_PMEVTYPER30_EL0 = 0x00052044,
	HV_ARM64_REGISTER_PMINTENCLR_EL1 = 0x00052045,
	HV_ARM64_REGISTER_PMINTENSET_EL1 = 0x00052046,
	HV_ARM64_REGISTER_PMMIR_EL1 = 0x00052047,
	HV_ARM64_REGISTER_PMOVSCLR_EL0 = 0x00052048,
	HV_ARM64_REGISTER_PMOVSSET_EL0 = 0x00052049,
	HV_ARM64_REGISTER_PMSELR_EL0 = 0x0005204A,
	HV_ARM64_REGISTER_PMSWINC_EL0 = 0x0005204B,
	HV_ARM64_REGISTER_PMUSERENR_EL0 = 0x0005204C,
	HV_ARM64_REGISTER_PMXEVCNTR_EL0 = 0x0005204D,
	HV_ARM64_REGISTER_PMXEVTYPER_EL0 = 0x0005204E,

	/* AArch64 System Register Descriptions: Activity Monitors registers */
	HV_ARM64_REGISTER_AMEVCNTR00_EL0 = 0x00053000,
	HV_ARM64_REGISTER_AMEVCNTR01_EL0 = 0x00053001,
	HV_ARM64_REGISTER_AMEVCNTR02_EL0 = 0x00053002,
	HV_ARM64_REGISTER_AMEVCNTR03_EL0 = 0x00053003,

	/* AArch64 System Register Descriptions: Statistical Profiling Extensions */
	HV_ARM64_REGISTER_PMBIDR_EL1 = 0x00054000,
	HV_ARM64_REGISTER_PMBLIMITR_EL1 = 0x00054001,
	HV_ARM64_REGISTER_PMBPTR_EL1 = 0x00054002,
	HV_ARM64_REGISTER_PMBSR_EL1 = 0x00054003,
	HV_ARM64_REGISTER_PMSCR_EL1 = 0x00054004,
	HV_ARM64_REGISTER_PMSCR_EL2 = 0x00054005,
	HV_ARM64_REGISTER_PMSEVFR_EL1 = 0x00054006,
	HV_ARM64_REGISTER_PMSFCR_EL1 = 0x00054007,
	HV_ARM64_REGISTER_PMSICR_EL1 = 0x00054008,
	HV_ARM64_REGISTER_PMSIDR_EL1 = 0x00054009,
	HV_ARM64_REGISTER_PMSIRR_EL1 = 0x0005400A,
	HV_ARM64_REGISTER_PMSLATFR_EL1 = 0x0005400B,
	HV_ARM64_REGISTER_PMSNEVFR_EL1 = 0x0005400C,

	/* AArch64 System Register Descriptions: RAS Registers s*/
	HV_ARM64_REGISTER_DISR_EL1 = 0x00056000,
	HV_ARM64_REGISTER_ERRIDR_EL1 = 0x00056001,
	HV_ARM64_REGISTER_ERRSELR_EL1 = 0x00056002,
	HV_ARM64_REGISTER_ERXADDR_EL1 = 0x00056003,
	HV_ARM64_REGISTER_ERXCTLR_EL1 = 0x00056004,
	HV_ARM64_REGISTER_ERRXFR_EL1 = 0x00056005,
	HV_ARM64_REGISTER_ERXMISC0_EL1 = 0x00056006,
	HV_ARM64_REGISTER_ERXMISC1_EL1 = 0x00056007,
	HV_ARM64_REGISTER_ERXMISC2_EL1 = 0x00056008,
	HV_ARM64_REGISTER_ERXMISC3_EL1 = 0x00056009,
	HV_ARM64_REGISTER_ERXPFGCDN_EL1 = 0x0005600A,
	HV_ARM64_REGISTER_ERXPFGCTL_EL1 = 0x0005600B,
	HV_ARM64_REGISTER_ERXPFGF_EL1 = 0x0005600C,
	HV_ARM64_REGISTER_ERXSTATUS_EL1 = 0x0005600D,
	HV_ARM64_REGISTER_VDISR_EL2 = 0x0005600E,
	HV_ARM64_REGISTER_VSESR_EL2 = 0x0005600F,

	/* AArch64 System Register Descriptions: Generic Timer Registers */
	HV_ARM64_REGISTER_CNTFRQ_EL0 = 0x00058000,
	HV_ARM64_REGISTER_CNTHCTL_EL2 = 0x00058001,
	HV_ARM64_REGISTER_CNTHP_CTL_EL2 = 0x00058002,
	HV_ARM64_REGISTER_CNTHP_CVAL_EL2 = 0x00058003,
	HV_ARM64_REGISTER_CNTHP_TVAL_EL2 = 0x00058004,
	HV_ARM64_REGISTER_CNTHV_CTL_EL2 = 0x00058005,
	HV_ARM64_REGISTER_CNTHV_CVAL_EL2 = 0x00058006,
	HV_ARM64_REGISTER_CNTHV_TVAL_EL2 = 0x00058007,
	HV_ARM64_REGISTER_CNTKCTL_EL1 = 0x00058008,
	HV_ARM64_REGISTER_CNTKCTL_ELX =
		0x00058013, // CntkctlEl1 or CnthctlEl2 depending on EL.
	HV_ARM64_REGISTER_CNTP_CTL_EL0 = 0x00058009,
	HV_ARM64_REGISTER_CNTP_CTL_ELX =
		0x00058014, // CntpCtlEl0 or CnthpCtlEl2 depending on EL.
	HV_ARM64_REGISTER_CNTP_CVAL_EL0 = 0x0005800A,
	HV_ARM64_REGISTER_CNTP_CVAL_ELX =
		0x00058015, // CntpCvalEl0 or CnthpCvalEl2 depending on EL.
	HV_ARM64_REGISTER_CNTP_TVAL_EL0 = 0x0005800B,
	HV_ARM64_REGISTER_CNTP_TVAL_ELX =
		0x00058016, // CntpTvalEl0 or CnthpTvalEl2 depending on EL.
	HV_ARM64_REGISTER_CNTPCT_EL0 = 0x0005800C,
	HV_ARM64_REGISTER_CNTPOFF_EL2 = 0x0005800D,
	HV_ARM64_REGISTER_CNTV_CTL_EL0 = 0x0005800E,
	HV_ARM64_REGISTER_CNTV_CTL_ELX =
		0x00058017, // CntvCtlEl0 or CnthvCtlEl2 depending on EL.
	HV_ARM64_REGISTER_CNTV_CVAL_EL0 = 0x0005800F,
	HV_ARM64_REGISTER_CNTV_CVAL_ELX =
		0x00058018, // CntvCvalEl0 or CnthvCvalEl2 depending on EL.
	HV_ARM64_REGISTER_CNTV_TVAL_EL0 = 0x00058010,
	HV_ARM64_REGISTER_CNTV_TVAL_ELX =
		0x00058019, // CntvTvalEl0 or CnthvTvalEl2 depending on EL.
	HV_ARM64_REGISTER_CNTVCT_EL0 = 0x00058011,
	HV_ARM64_REGISTER_CNTVOFF_EL2 = 0x00058012,

	/* ARM GIC (System Registers): AArch64 System Register Descriptions */
	HV_ARM64_REGISTER_ICC_AP1R0_EL1 = 0x00060000,
	HV_ARM64_REGISTER_ICC_AP1R1_EL1 = 0x00060001,
	HV_ARM64_REGISTER_ICC_AP1R2_EL1 = 0x00060002,
	HV_ARM64_REGISTER_ICC_AP1R3_EL1 = 0x00060003,
	HV_ARM64_REGISTER_ICC_ASGI1R_EL1 = 0x00060004,
	HV_ARM64_REGISTER_ICC_BPR1_EL1 = 0x00060005,
	HV_ARM64_REGISTER_ICC_CTLR_EL1 = 0x00060006,
	HV_ARM64_REGISTER_ICC_DIR_EL1 = 0x00060007,
	HV_ARM64_REGISTER_ICC_EOIR1_EL1 = 0x00060008,
	HV_ARM64_REGISTER_ICC_HPPIR1_EL1 = 0x00060009,
	HV_ARM64_REGISTER_ICC_IAR1_EL1 = 0x0006000A,
	HV_ARM64_REGISTER_ICC_IGRPEN1_EL1 = 0x0006000B,
	HV_ARM64_REGISTER_ICC_PMR_EL1 = 0x0006000C,
	HV_ARM64_REGISTER_ICC_RPR_EL1 = 0x0006000D,
	HV_ARM64_REGISTER_ICC_SGI1R_EL1 = 0x0006000E,
	HV_ARM64_REGISTER_ICC_SRE_EL1 = 0x0006000F,
	HV_ARM64_REGISTER_ICC_SRE_EL2 = 0x00060010,

	/* ARM GIC (System Registers): AArch64 Virtualization Control System Registers */
	HV_ARM64_REGISTER_ICH_AP1R0_EL2 = 0x00061000,
	HV_ARM64_REGISTER_ICH_AP1R1_EL2 = 0x00061001,
	HV_ARM64_REGISTER_ICH_AP1R2_EL2 = 0x00061002,
	HV_ARM64_REGISTER_ICH_AP1R3_EL2 = 0x00061003,
	HV_ARM64_REGISTER_ICH_EISR_EL2 = 0x00061004,
	HV_ARM64_REGISTER_ICH_ELRSR_EL2 = 0x00061005,
	HV_ARM64_REGISTER_ICH_HCR_EL2 = 0x00061006,
	HV_ARM64_REGISTER_ICH_LR0_EL2 = 0x00061007,
	HV_ARM64_REGISTER_ICH_LR1_EL2 = 0x00061008,
	HV_ARM64_REGISTER_ICH_LR2_EL2 = 0x00061009,
	HV_ARM64_REGISTER_ICH_LR3_EL2 = 0x0006100A,
	HV_ARM64_REGISTER_ICH_LR4_EL2 = 0x0006100B,
	HV_ARM64_REGISTER_ICH_LR5_EL2 = 0x0006100C,
	HV_ARM64_REGISTER_ICH_LR6_EL2 = 0x0006100D,
	HV_ARM64_REGISTER_ICH_LR7_EL2 = 0x0006100E,
	HV_ARM64_REGISTER_ICH_LR8_EL2 = 0x0006100F,
	HV_ARM64_REGISTER_ICH_LR9_EL2 = 0x00061010,
	HV_ARM64_REGISTER_ICH_LR10_EL2 = 0x00061011,
	HV_ARM64_REGISTER_ICH_LR11_EL2 = 0x00061012,
	HV_ARM64_REGISTER_ICH_LR12_EL2 = 0x00061013,
	HV_ARM64_REGISTER_ICH_LR13_EL2 = 0x00061014,
	HV_ARM64_REGISTER_ICH_LR14_EL2 = 0x00061015,
	HV_ARM64_REGISTER_ICH_LR15_EL2 = 0x00061016,
	HV_ARM64_REGISTER_ICH_MISR_EL2 = 0x00061017,
	HV_ARM64_REGISTER_ICH_VMCR_EL2 = 0x00061018,
	HV_ARM64_REGISTER_ICH_VTR_EL2 = 0x00061019,

	/* ARM GIC (System Registers): The GIC Redistributor */
	HV_ARM64_REGISTER_GICR_BASE_GPA = 0x00063000,

	/*
	 * AArch64 System Register Descriptions: Memory System Resource
	 * Partitioning And Monitoring
	 */
	HV_ARM64_REGISTER_MPAM0_EL1 = 0x00071000,
	HV_ARM64_REGISTER_MPAM1_EL1 = 0x00071001,
	HV_ARM64_REGISTER_MPAM2_EL2 = 0x00071002,
	HV_ARM64_REGISTER_MPAMHCR_EL2 = 0x00071003,
	HV_ARM64_REGISTER_MPAMIDR_EL1 = 0x00071004,
	HV_ARM64_REGISTER_MPAMSM_EL1 = 0x00071005,
	HV_ARM64_REGISTER_MPAMVPM0_EL2 = 0x00071006,
	HV_ARM64_REGISTER_MPAMVPM1_EL2 = 0x00071007,
	HV_ARM64_REGISTER_MPAMVPM2_EL2 = 0x00071008,
	HV_ARM64_REGISTER_MPAMVPM3_EL2 = 0x00071009,
	HV_ARM64_REGISTER_MPAMVPM4_EL2 = 0x0007100A,
	HV_ARM64_REGISTER_MPAMVPM5_EL2 = 0x0007100B,
	HV_ARM64_REGISTER_MPAMVPM6_EL2 = 0x0007100C,
	HV_ARM64_REGISTER_MPAMVPM7_EL2 = 0x0007100D,
	HV_ARM64_REGISTER_MPAMVPMV_EL2 = 0x0007100E,
#endif
};


/*
 * Arch compatibility regs for use with hv_set/get_register
 * NOTE: not really in hyperv headers
 */
#if defined(__x86_64__)

/*
 * To support arch-generic code calling hv_set/get_register:
 * - On x86, HV_MSR_ indicates an MSR accessed via rdmsrl/wrmsrl
 * - On ARM, HV_MSR_ indicates a VP register accessed via hypercall
 */
#define HV_MSR_CRASH_P0		(HV_X64_MSR_CRASH_P0)
#define HV_MSR_CRASH_P1		(HV_X64_MSR_CRASH_P1)
#define HV_MSR_CRASH_P2		(HV_X64_MSR_CRASH_P2)
#define HV_MSR_CRASH_P3		(HV_X64_MSR_CRASH_P3)
#define HV_MSR_CRASH_P4		(HV_X64_MSR_CRASH_P4)
#define HV_MSR_CRASH_CTL	(HV_X64_MSR_CRASH_CTL)

#define HV_MSR_VP_INDEX		(HV_X64_MSR_VP_INDEX)
#define HV_MSR_TIME_REF_COUNT	(HV_X64_MSR_TIME_REF_COUNT)
#define HV_MSR_REFERENCE_TSC	(HV_X64_MSR_REFERENCE_TSC)

#define HV_MSR_SINT0		(HV_X64_MSR_SINT0)
#define HV_MSR_SVERSION		(HV_X64_MSR_SVERSION)
#define HV_MSR_SCONTROL		(HV_X64_MSR_SCONTROL)
#define HV_MSR_SIEFP		(HV_X64_MSR_SIEFP)
#define HV_MSR_SIMP		(HV_X64_MSR_SIMP)
#define HV_MSR_EOM		(HV_X64_MSR_EOM)
#define HV_MSR_SIRBP		(HV_X64_MSR_SIRBP)

#define HV_MSR_NESTED_SCONTROL	(HV_X64_MSR_NESTED_SCONTROL)
#define HV_MSR_NESTED_SVERSION	(HV_X64_MSR_NESTED_SVERSION)
#define HV_MSR_NESTED_SIEFP	(HV_X64_MSR_NESTED_SIEFP)
#define HV_MSR_NESTED_SIMP	(HV_X64_MSR_NESTED_SIMP)
#define HV_MSR_NESTED_EOM	(HV_X64_MSR_NESTED_EOM)
#define HV_MSR_NESTED_SINT0	(HV_X64_MSR_NESTED_SINT0)

#define HV_MSR_STIMER0_CONFIG	(HV_X64_MSR_STIMER0_CONFIG)
#define HV_MSR_STIMER0_COUNT	(HV_X64_MSR_STIMER0_COUNT)

/* x86 supports nested virtualization */
#define HV_SUPPORTS_NESTED

#else /* __x86_64__ */

#define HV_MSR_CRASH_P0		(HV_REGISTER_GUEST_CRASH_P0)
#define HV_MSR_CRASH_P1		(HV_REGISTER_GUEST_CRASH_P1)
#define HV_MSR_CRASH_P2		(HV_REGISTER_GUEST_CRASH_P2)
#define HV_MSR_CRASH_P3		(HV_REGISTER_GUEST_CRASH_P3)
#define HV_MSR_CRASH_P4		(HV_REGISTER_GUEST_CRASH_P4)
#define HV_MSR_CRASH_CTL	(HV_REGISTER_GUEST_CRASH_CTL)

#define HV_MSR_VP_INDEX		(HV_REGISTER_VP_INDEX)
#define HV_MSR_TIME_REF_COUNT	(HV_REGISTER_TIME_REF_COUNT)
#define HV_MSR_REFERENCE_TSC	(HV_REGISTER_REFERENCE_TSC)

#define HV_MSR_SINT0		(HV_REGISTER_SINT0)
#define HV_MSR_SCONTROL		(HV_REGISTER_SCONTROL)
#define HV_MSR_SIEFP		(HV_REGISTER_SIEFP)
#define HV_MSR_SIMP		(HV_REGISTER_SIMP)
#define HV_MSR_EOM		(HV_REGISTER_EOM)
#define HV_MSR_SIRBP		(HV_REGISTER_SIRBP)

#define HV_MSR_STIMER0_CONFIG	(HV_REGISTER_STIMER0_CONFIG)
#define HV_MSR_STIMER0_COUNT	(HV_REGISTER_STIMER0_COUNT)

#endif

/* General Hypervisor Register Content Definitions */

union hv_explicit_suspend_register {
	__u64 as_uint64;
	struct {
		__u64 suspended : 1;
		__u64 reserved : 63;
	} __packed;
};

union hv_intercept_suspend_register {
	__u64 as_uint64;
	struct {
		__u64 suspended : 1;
		__u64 reserved : 63;
	} __packed;
};

union hv_dispatch_suspend_register {
	__u64 as_uint64;
	struct {
		__u64 suspended : 1;
		__u64 reserved : 63;
	} __packed;
};

union hv_internal_activity_register {
	__u64 as_uint64;

	struct {
		__u64 startup_suspend : 1;
		__u64 halt_suspend : 1;
		__u64 idle_suspend : 1;
		__u64 rsvd_z : 61;
	} __packed;
};

union hv_x64_interrupt_state_register {
	__u64 as_uint64;
	struct {
		__u64 interrupt_shadow : 1;
		__u64 nmi_masked : 1;
		__u64 reserved : 62;
	} __packed;
};


union hv_register_vsm_partition_status {
	__u64 as_uint64;
	struct {
		__u64 enabled_vtl_set : 16;
		__u64 max_vtl : 4;
		__u64 mbec_enabled_vtl_set: 16;
		__u64 supervisor_shadow_stack_enabled_vtl_set : 4;
		__u64 reserved : 24;
	} __packed;
};

#if defined(__aarch64__)
/* HvGetVpRegisters returns an array of these output elements */
struct hv_get_vp_registers_output {
	union {
		struct {
			__u32 a;
			__u32 b;
			__u32 c;
			__u32 d;
		} as32 __packed;
		struct {
			__u64 low;
			__u64 high;
		} as64 __packed;
	};
};

#define HV_ARM64_PENDING_EVENT_HEADER \
	__u8 event_pending : 1; \
	__u8 event_type : 3; \
	__u8 reserved : 4

union hv_arm64_pending_synthetic_exception_event {
	__u64 as_uint64[2];
	struct {
		HV_ARM64_PENDING_EVENT_HEADER;

		__u32 exception_type;
		__u64 context;
	} __packed;
};

union hv_arm64_interrupt_state_register {
	__u64 as_uint64;
	struct {
		__u64 interrupt_shadow : 1;
		__u64 reserved : 63;
	} __packed;
};

enum hv_arm64_pending_interruption_type {
	HV_ARM64_PENDING_INTERRUPT = 0,
	HV_ARM64_PENDING_EXCEPTION = 1
};

union hv_arm64_pending_interruption_register {
	__u64 as_uint64;
	struct {
		__u64 interruption_pending : 1;
		__u64 interruption_type : 1;
		__u64 reserved : 30;
		__u64 error_code : 32;
	} __packed;
};

#else /* defined(__aarch64__) */

union hv_x64_pending_exception_event {
	__u64 as_uint64[2];
	struct {
		__u32 event_pending : 1;
		__u32 event_type : 3;
		__u32 reserved0 : 4;
		__u32 deliver_error_code : 1;
		__u32 reserved1 : 7;
		__u32 vector : 16;
		__u32 error_code;
		__u64 exception_parameter;
	} __packed;
};

union hv_x64_pending_virtualization_fault_event {
	__u64 as_uint64[2];
	struct {
		__u32 event_pending : 1;
		__u32 event_type : 3;
		__u32 reserved0 : 4;
		__u32 reserved1 : 8;
		__u32 parameter0 : 16;
		__u32 code;
		__u64 parameter1;
	} __packed;
};

// bunch of stuff in between

union hv_x64_pending_interruption_register {
	__u64 as_uint64;
	struct {
		__u32 interruption_pending : 1;
		__u32 interruption_type : 3;
		__u32 deliver_error_code : 1;
		__u32 instruction_length : 4;
		__u32 nested_event : 1;
		__u32 reserved : 6;
		__u32 interruption_vector : 16;
		__u32 error_code;
	} __packed;
};

#define HV_SUPPORTS_SEV_SNP_GUESTS

union hv_x64_register_sev_control {
	__u64 as_uint64;
	struct {
		__u64 enable_encrypted_state : 1;
		__u64 reserved_z : 11;
		__u64 vmsa_gpa_page_number : 52;
	} __packed;
};

#endif /* defined(__aarch64__) */

union hv_register_value {
	struct hv_u128 reg128;
	__u64 reg64;
	__u32 reg32;
	__u16 reg16;
	__u8 reg8;

#if defined(__x86_64__)
	union hv_x64_fp_register fp;
	union hv_x64_fp_control_status_register fp_control_status;
	union hv_x64_xmm_control_status_register xmm_control_status;
	struct hv_x64_segment_register segment;
	struct hv_x64_table_register table;
#endif
	union hv_explicit_suspend_register explicit_suspend;
	union hv_intercept_suspend_register intercept_suspend;
	union hv_dispatch_suspend_register dispatch_suspend;
	union hv_internal_activity_register internal_activity;
	union hv_register_vsm_partition_status vsm_partition_status;
#if defined(__x86_64__)
	union hv_x64_interrupt_state_register interrupt_state;
	union hv_x64_pending_interruption_register pending_interruption;
	union hv_x64_msr_npiep_config_contents npiep_config;
	union hv_x64_pending_exception_event pending_exception_event;
	union hv_x64_pending_virtualization_fault_event
		pending_virtualization_fault_event;
	union hv_x64_register_sev_control sev_control;
#elif defined(__aarch64__)
	union hv_arm64_pending_interruption_register pending_interruption;
	union hv_arm64_interrupt_state_register interrupt_state;
	union hv_arm64_pending_synthetic_exception_event
		pending_synthetic_exception_event;
#endif
};

struct hv_register_assoc {
	__u32 name;			/* enum hv_register_name */
	__u32 reserved1;
	__u64 reserved2;
	union hv_register_value value;
} __packed;

struct hv_input_get_vp_registers {
	__u64 partition_id;
	__u32 vp_index;
	union hv_input_vtl input_vtl;
	__u8  rsvd_z8;
	__u16 rsvd_z16;
	__u32 names[];
} __packed;

struct hv_input_set_vp_registers {
	__u64 partition_id;
	__u32 vp_index;
	union hv_input_vtl input_vtl;
	__u8  rsvd_z8;
	__u16 rsvd_z16;
	struct hv_register_assoc elements[];
} __packed;

#define HV_UNMAP_GPA_LARGE_PAGE		0x2

/* HvCallSendSyntheticClusterIpi hypercall */
struct hv_send_ipi {	 /* HV_INPUT_SEND_SYNTHETIC_CLUSTER_IPI */
	__u32 vector;
	__u32 reserved;
	__u64 cpu_mask;
} __packed;

#define HV_X64_VTL_MASK			GENMASK(3, 0)

#if defined(__KERNEL__)
#if defined(__x86_64__)
union hv_msi_address_register { /* HV_MSI_ADDRESS */
	__u32 as_uint32;
	struct {
		__u32 reserved1:2;
		__u32 destination_mode:1;
		__u32 redirection_hint:1;
		__u32 reserved2:8;
		__u32 destination_id:8;
		__u32 msi_base:12;
	};
} __packed;

union hv_msi_data_register {	 /* HV_MSI_ENTRY.Data */
	__u32 as_uint32;
	struct {
		__u32 vector:8;
		__u32 delivery_mode:3;
		__u32 reserved1:3;
		__u32 level_assert:1;
		__u32 trigger_mode:1;
		__u32 reserved2:16;
	};
} __packed;

union hv_msi_entry {	 /* HV_MSI_ENTRY */

	__u64 as_uint64;
	struct {
		union hv_msi_address_register address;
		union hv_msi_data_register data;
	} __packed;
};

#elif defined(__aarch64__)

union hv_msi_entry {
	__u64 as_uint64[2];
	struct {
		__u64 address;
		__u32 data;
		__u32 reserved;
	} __packed;
};
#endif

union hv_ioapic_rte {
	__u64 as_uint64;

	struct {
		__u32 vector:8;
		__u32 delivery_mode:3;
		__u32 destination_mode:1;
		__u32 delivery_status:1;
		__u32 interrupt_polarity:1;
		__u32 remote_irr:1;
		__u32 trigger_mode:1;
		__u32 interrupt_mask:1;
		__u32 reserved1:15;

		__u32 reserved2:24;
		__u32 destination_id:8;
	};

	struct {
		__u32 low_uint32;
		__u32 high_uint32;
	};
} __packed;

enum hv_interrupt_source {	 /* HV_INTERRUPT_SOURCE */
	HV_INTERRUPT_SOURCE_MSI = 1, /* MSI and MSI-X */
	HV_INTERRUPT_SOURCE_IOAPIC,
};

struct hv_interrupt_entry {	 /* HV_INTERRUPT_ENTRY */
	__u32 source;
	__u32 reserved1;
	union {
		union hv_msi_entry msi_entry;
		union hv_ioapic_rte ioapic_rte;
	};
} __packed;

#define HV_DEVICE_INTERRUPT_TARGET_MULTICAST		1
#define HV_DEVICE_INTERRUPT_TARGET_PROCESSOR_SET	2

struct hv_device_interrupt_target {	 /* HV_DEVICE_INTERRUPT_TARGET */
	__u32 vector;
	__u32 flags;		/* HV_DEVICE_INTERRUPT_TARGET_* above */
	union {
		__u64 vp_mask;
		struct hv_vpset vp_set;
	};
} __packed;

struct hv_retarget_device_interrupt {	 /* HV_INPUT_RETARGET_DEVICE_INTERRUPT */
	__u64 partition_id;		/* use "self" */
	__u64 device_id;
	struct hv_interrupt_entry int_entry;
	__u64 reserved2;
	struct hv_device_interrupt_target int_target;
} __packed __aligned(8);

#endif /* __KERNEL__ */

enum hv_intercept_type {
#if defined(__x86_64__)
	HV_INTERCEPT_TYPE_X64_IO_PORT			= 0x00000000,
	HV_INTERCEPT_TYPE_X64_MSR			= 0x00000001,
	HV_INTERCEPT_TYPE_X64_CPUID			= 0x00000002,
#endif
	HV_INTERCEPT_TYPE_EXCEPTION			= 0x00000003,
	/* Used to be HV_INTERCEPT_TYPE_REGISTER */
	HV_INTERCEPT_TYPE_RESERVED0			= 0x00000004,
	HV_INTERCEPT_TYPE_MMIO				= 0x00000005,
#if defined(__x86_64__)
	HV_INTERCEPT_TYPE_X64_GLOBAL_CPUID		= 0x00000006,
	HV_INTERCEPT_TYPE_X64_APIC_SMI			= 0x00000007,
#endif
	HV_INTERCEPT_TYPE_HYPERCALL			= 0x00000008,
#if defined(__x86_64__)
	HV_INTERCEPT_TYPE_X64_APIC_INIT_SIPI		= 0x00000009,
	HV_INTERCEPT_MC_UPDATE_PATCH_LEVEL_MSR_READ	= 0x0000000A,
	HV_INTERCEPT_TYPE_X64_APIC_WRITE		= 0x0000000B,
	HV_INTERCEPT_TYPE_X64_MSR_INDEX			= 0x0000000C,
#endif
	HV_INTERCEPT_TYPE_MAX,
	HV_INTERCEPT_TYPE_INVALID			= 0xFFFFFFFF,
};

union hv_intercept_parameters {
	/*  HV_INTERCEPT_PARAMETERS is defined to be an 8-byte field. */
	__u64 as_uint64;
#if defined(__x86_64__)
	/* HV_INTERCEPT_TYPE_X64_IO_PORT */
	__u16 io_port;
	/* HV_INTERCEPT_TYPE_X64_CPUID */
	__u32 cpuid_index;
	/* HV_INTERCEPT_TYPE_X64_APIC_WRITE */
	__u32 apic_write_mask;
	/* HV_INTERCEPT_TYPE_EXCEPTION */
	__u16 exception_vector;
	/* HV_INTERCEPT_TYPE_X64_MSR_INDEX */
	__u32 msr_index;
#endif
	/* N.B. Other intercept types do not have any parameters. */
};

/* Access types for the install intercept hypercall parameter */
#define HV_INTERCEPT_ACCESS_MASK_NONE		0x00
#define HV_INTERCEPT_ACCESS_MASK_READ		0x01
#define HV_INTERCEPT_ACCESS_MASK_WRITE		0x02
#define HV_INTERCEPT_ACCESS_MASK_EXECUTE	0x04

struct hv_input_install_intercept {
	__u64 partition_id;
	__u32 access_type;	/* mask */
	__u32 intercept_type;	/* hv_intercept_type */
	union hv_intercept_parameters intercept_parameter;
} __packed;

/* Data structures for HVCALL_MMIO_READ and HVCALL_MMIO_WRITE */
#define HV_HYPERCALL_MMIO_MAX_DATA_LENGTH 64

struct hv_mmio_read_input { /* HV_INPUT_MEMORY_MAPPED_IO_READ */
	__u64 gpa;
	__u32 size;
	__u32 reserved;
} __packed;

struct hv_mmio_read_output {
	__u8 data[HV_HYPERCALL_MMIO_MAX_DATA_LENGTH];
} __packed;

struct hv_mmio_write_input {
	__u64 gpa;
	__u32 size;
	__u32 reserved;
	__u8 data[HV_HYPERCALL_MMIO_MAX_DATA_LENGTH];
} __packed;

enum hv_eventlog_type { /* HV_EVENTLOG_TYPE */
	HV_EVENT_LOG_TYPE_GLOBAL_SYSTEM_EVENTS	= 0x00000000,
	HV_EVENT_LOG_TYPE_LOCAL_DIAGNOSTICS	= 0x00000001,
	HV_EVENT_LOG_TYPE_SYSTEM_DIAGNOSTICS	= 0x00000002,
};

union hv_x64_register_sev_ghcb {
	__u64 as_uint64;
	struct {
		__u64 enabled:1;
		__u64 reservedz:11;
		__u64 page_number:52;
	} __packed;
};

union hv_x64_register_sev_hv_doorbell {
	__u64 as_uint64;
	struct {
		__u64 enabled:1;
		__u64 reservedz:11;
		__u64 page_number:52;
	} __packed;
};

/* Values for intercept_access_type field */
#define HV_INTERCEPT_ACCESS_READ 0
#define HV_INTERCEPT_ACCESS_WRITE 1
#define HV_INTERCEPT_ACCESS_EXECUTE 2

#endif /* _UAPI_HV_HVGDK_MINI_H */
