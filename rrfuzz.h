/*
 *  ____  ____  _____              
 * |  _ \|  _ \|  ___|   _ ________
 * | |_) | |_) | |_ | | | |_  /_  /
 * |  _ <|  _ <|  _|| |_| |/ / / / 
 * |_| \_\_| \_\_|   \__,_/___/___|
 *
 * Copyright (C) National University of Singapore
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RRFUZZ_H
#define __RRFUZZ_H

#define PCAP_FILENO             999
#define CONFIG_FILENO           998

#define ACTX                    250

#define FORK_CHILD              0
#define FORK_PARENT             1
#define FORK_FAIL               2

struct CONFIG                   // RRFuzz config
{
    bool debug;                 // Attach debugger?
    bool fuzz;                  // Fuzz mode?
    bool hex;                   // Log output in hex?
    bool patch;                 // Patch replay?
    bool record;                // Record mode (false = replay mode)
    bool tty;                   // Is TTY? (print colors)
    bool blackbox;              // Blackbox mode?
    bool save;                  // Save-all mode?
    uint8_t fork;               // Fork-mode?
    int8_t log;                 // Log level.
    int8_t emulate;             // Emulation level.
    int64_t seed;               // RNG seed.
    int32_t timeout;            // Fuzz timeout.
    uint16_t depth;             // Fuzz depth.
    uint16_t cpu;               // CPU number.
    size_t count;               // Max executions.
    char strs[];                // String options
};

struct CONTEXT                  // Execution context/
{
    uint32_t cpu;               // Which CPU to run on.
    pid_t pid;                  // Process ID
    uint8_t fork;               // Fork-mode
    uint32_t argc;              // Length of argv[]
    uint32_t envl;              // Length of envp[]
    uint32_t size;              // Size of args[]
    char args[];                // argv[] followed by envp[].
};

#endif
