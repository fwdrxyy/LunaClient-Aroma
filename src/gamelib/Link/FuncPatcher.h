#pragma once

#include <utils/Kernel.h>
#include <utils/Logger.h>
#include <utils/Types.h>

#define MC_DECL_FUNCTION(type, name, ...)                                                                                                                                \
    type (*real_##name)(__VA_ARGS__);                                                                                                                                    \
    type my_##name(__VA_ARGS__)

#define MC_REPLACE(addr, name) real_##name = (decltype(real_##name)) mc::FuncPatcher::replaceFunc((void *) addr, (void *) &my_##name);
#define MC_HOOK(addr, func)                                                                                                                                              \
    uint32_t hook_##func[4] = {0x3D800000UL | ((uint32_t) &func >> 16), 0x618C0000UL | ((uint32_t) &func & 0xFFFF), 0x7D8903A6UL, 0x4E800421UL};                         \
    mc::FuncPatcher::injectInstr((void *) addr, hook_##func, sizeof(hook_##func));

#define MINECRAFT_EXECUTABLE_SPACE_START (0x0384CC20 + 0x10000)

#define BRANCH_MAX_DISTANCE_POSITIVE     0x1FFFFFC
#define BRANCH_MAX_DISTANCE_NEGATIVE     (-0x2000000)

#define INSTRUCTION_BRANCH               0x48000000
#define INSTRUCTION_BRANCH_OFFSET_BIT    0x3FFFFFC

namespace mc::FuncPatcher {
    inline int32_t current_executable_space = MINECRAFT_EXECUTABLE_SPACE_START;

    inline void *allocExec(size_t size) {
        const int32_t ret = current_executable_space;
        current_executable_space += size;

        DEBUG_FUNCTION_LINE("current_executable_space:%08X", current_executable_space);

        return reinterpret_cast<void *>(ret);
    }

    inline void *replaceFunc(void *original_func, void *my_func) {
        DEBUG_FUNCTION_LINE("%08x", reinterpret_cast<uint32_t>(original_func));

        if (reinterpret_cast<uint32_t>(original_func) % 4 != 0 || reinterpret_cast<uint32_t>(my_func) % 4 != 0) return nullptr;

        int32_t jump_length = reinterpret_cast<int32_t>(my_func) - reinterpret_cast<int32_t>(original_func);

        if (jump_length > BRANCH_MAX_DISTANCE_POSITIVE || jump_length < BRANCH_MAX_DISTANCE_NEGATIVE) {
            int32_t big_jump[4];
            big_jump[0] = 0x3D800000 | (reinterpret_cast<uint32_t>(my_func) >> 16);   // lis r12, my_func@h
            big_jump[1] = 0x618C0000 | (reinterpret_cast<int32_t>(my_func) & 0xFFFF); // ori r12, r12, my_func@l
            big_jump[2] = 0x7D8903A6;                                                 // mtctr r12
            big_jump[3] = 0x4E800420;                                                 // bctr

            void *destination = allocExec(sizeof(big_jump));

            KernelMemcpy(destination, big_jump, sizeof(big_jump));

            jump_length = reinterpret_cast<int32_t>(destination) - reinterpret_cast<int32_t>(original_func);
        }

        int32_t real_func_buffer[2];
        void *real_func     = allocExec(sizeof(real_func_buffer));
        real_func_buffer[0] = *static_cast<int32_t *>(original_func);
        real_func_buffer[1] =
                INSTRUCTION_BRANCH | (((reinterpret_cast<int32_t>(original_func) + 4) - (reinterpret_cast<int32_t>(real_func) + 4)) & INSTRUCTION_BRANCH_OFFSET_BIT);

        KernelMemcpy(real_func, real_func_buffer, sizeof(real_func_buffer));

        const int32_t instr_jump_to_my_func = INSTRUCTION_BRANCH | (jump_length & INSTRUCTION_BRANCH_OFFSET_BIT);

        Poke32(reinterpret_cast<uint32_t>(original_func), instr_jump_to_my_func);

        return real_func;
    }

    inline void injectInstr(void *dst, void *instr, const size_t instr_size) {
        DEBUG_FUNCTION_LINE("%08x/%d", reinterpret_cast<uint32_t>(dst), instr_size);

        if (reinterpret_cast<uint32_t>(dst) % 4 != 0 || instr_size % 4 != 0) return;

        const int32_t inject_size = instr_size + sizeof(int32_t) * 2;

        auto *allocated_space = static_cast<int32_t *>(allocExec(inject_size));

        const int32_t jump_length = reinterpret_cast<int32_t>(allocated_space) - reinterpret_cast<int32_t>(dst);
        const int32_t jump_return_length =
                (reinterpret_cast<uint32_t>(dst) + sizeof(int32_t)) - ((reinterpret_cast<uint32_t>(allocated_space) + sizeof(uint32_t) + instr_size));

        const uint32_t instr_jump_to_injected   = INSTRUCTION_BRANCH | (jump_length & INSTRUCTION_BRANCH_OFFSET_BIT);
        const uint32_t instr_return_to_original = INSTRUCTION_BRANCH | (jump_return_length & INSTRUCTION_BRANCH_OFFSET_BIT);
        const uint32_t instr_real               = *static_cast<int32_t *>(dst);

        if (jump_length > BRANCH_MAX_DISTANCE_POSITIVE || jump_length < BRANCH_MAX_DISTANCE_NEGATIVE) return;
        if (jump_return_length > BRANCH_MAX_DISTANCE_POSITIVE || jump_return_length < BRANCH_MAX_DISTANCE_NEGATIVE) return;

        Poke32(reinterpret_cast<uint32_t>(allocated_space), instr_real);
        allocated_space++;

        KernelMemcpy(allocated_space, instr, instr_size);
        allocated_space += instr_size / sizeof(uint32_t);

        Poke32(reinterpret_cast<uint32_t>(allocated_space), instr_return_to_original);
        Poke32(reinterpret_cast<uint32_t>(dst), instr_jump_to_injected);
    }
} // namespace mc::FuncPatcher
