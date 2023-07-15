#pragma once
#include "stdafx.h"
#include <string>

// Resolve a circular dependency
class CIFWnd;

/// Loader for resinfo/*.txt files
class CIRMManager {
public:
    CIRMManager();

    /// Get a pointer to a control identified by the Id
    /// \param id The Id of the control as stated in the resinfo file or set on creation
    /// \param a2 Completely unknown, is always 1
    /// \returns Pointer to the control, NULL if Id was not found.
    CIFWnd* GetResObj(int id, int a2);

    /// Get a pointer to a control identified by the Id
    /// \tparam T Expected type of the control. The type is never validated.
    /// \param id The Id of the control as stated in the resinfo file or set on creation
    /// \param a2 Completely unknown, is always 1
    /// \returns Pointer to the control, NULL if Id was not found.
    template<typename T>
    T* GetResObj(int id, int a2) {
        return reinterpret_cast<T * (__thiscall*)(CIRMManager*, int, int)>(0x008B51F0)(this, id, a2);
    }

private:
    int N00009CBC;
};