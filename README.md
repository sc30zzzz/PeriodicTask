# PeriodicTask
A lightweight C++ library for managing periodic tasks with timing monitoring, designed for Linux systems.
Overview
This library provides a framework to create and manage periodic tasks that run in separate threads. It includes timing utilities to measure task execution duration and monitor task performance, ensuring tasks run at specified intervals with minimal drift.
Features

    Create periodic tasks with custom execution frequencies
    Monitor task runtime and interval compliance
    Track maximum runtime and interval metrics
    Color-coded status reporting for slow tasks
    Thread-safe task management
    High-precision timing using CLOCK_MONOTONIC

Components

    Timer: High-resolution timer for measuring elapsed time in nanoseconds, milliseconds, or seconds
    PeriodicTask: Abstract base class for periodic tasks (implement init(), run(), and cleanup())
    PeriodicTaskManager: Manages collections of periodic tasks
    PeriodicFunction: Wrapper for standalone functions as periodic tasks
    PeriodicMemberFunction: Wrapper for class member functions as periodic tasks
    PrintTaskStatus: Utility task for printing task statuses periodically

Building the Project
Prerequisites

    Linux system
    GCC compiler with C++11 support
    CMake (3.10 or higher)
    pthread library

Build Instructions

    Clone the repository
    Create and navigate to a build directory:
    bash

mkdir build && cd build


Generate makefiles with CMake:
bash

cmake ..


Build the project:
bash

    make


API Reference
Timer Class

    Timer(): Constructor that starts the timer immediately
    start(): Reset and start the timer
    getNs(): Get elapsed time in nanoseconds
    getMs(): Get elapsed time in milliseconds
    getSeconds(): Get elapsed time in seconds

PeriodicTask Class

    PeriodicTask(PeriodicTaskManager* manager, float period, std::string name): Constructor
    start(): Start the task execution
    stop(): Stop the task execution
    printStatus(): Print current task statistics
    clearMax(): Reset maximum runtime and period metrics
    isSlow(): Check if the task is running slower than expected (30% over target period)
    getPeriod(): Get target period in seconds
    getRuntime(): Get last execution time in seconds

PeriodicTaskManager Class

    addTask(PeriodicTask* task): Add a task to the manager
    printStatus(): Print status of all managed tasks
    printStatusOfSlowTasks(): Print status only for slow tasks
    stopAll(): Stop all managed tasks

Notes

    Requires -pthread flag for compilation
    Uses Linux-specific timerfd for precise interval timing
    Task periods are specified in seconds (floating-point values allowed)
    Slow tasks are highlighted in red in status reports
    All tasks run in their own dedicated threads
