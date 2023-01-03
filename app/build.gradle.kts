/*
 * This file was generated by the Gradle 'init' task.
 *
 * This generated file contains a sample C++ project to get you started.
 * For more details take a look at the Building C++ applications and libraries chapter in the Gradle
 * User Manual available at https://docs.gradle.org/7.6/userguide/building_cpp_projects.html
 */

plugins {
    // Apply the cpp-application plugin to add support for building C++ executables
    `cpp-application`

    // Apply the cpp-unit-test plugin to add support for building and running C++ test executables
    `cpp-unit-test`
}

// Set the target operating system and architecture for this application
application {
    targetMachines.add(machines.linux.x86_64)
}