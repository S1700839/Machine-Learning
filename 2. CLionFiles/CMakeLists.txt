cmake_minimum_required(VERSION 3.12)
project(code_only C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ruleInducer
        Example_main.c
        ExampleData.h
        SolutionListOperations.c
        SolutionListOperations.h
        StructureDefinitions.h
        TrainAndTest.c
        TrainAndTest.h)
