// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.1
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ==============================================================

/***************************** Include Files *********************************/
#include "xtestpr.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XTestpr_CfgInitialize(XTestpr *InstancePtr, XTestpr_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XTestpr_Start(XTestpr *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL) & 0x80;
    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XTestpr_IsDone(XTestpr *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XTestpr_IsIdle(XTestpr *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XTestpr_IsReady(XTestpr *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XTestpr_EnableAutoRestart(XTestpr *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XTestpr_DisableAutoRestart(XTestpr *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_AP_CTRL, 0);
}

void XTestpr_InterruptGlobalEnable(XTestpr *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_GIE, 1);
}

void XTestpr_InterruptGlobalDisable(XTestpr *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_GIE, 0);
}

void XTestpr_InterruptEnable(XTestpr *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_IER);
    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_IER, Register | Mask);
}

void XTestpr_InterruptDisable(XTestpr *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_IER);
    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_IER, Register & (~Mask));
}

void XTestpr_InterruptClear(XTestpr *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XTestpr_WriteReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_ISR, Mask);
}

u32 XTestpr_InterruptGetEnabled(XTestpr *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_IER);
}

u32 XTestpr_InterruptGetStatus(XTestpr *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XTestpr_ReadReg(InstancePtr->Axilites_BaseAddress, XTESTPR_AXILITES_ADDR_ISR);
}
