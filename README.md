# Dockerized Testing
The intention on this project is for it to be used as a starting point for integrating dockerized unit testing into embedded projects. The main benefit from this is the ability to run unit tests in a CI/CD pipeline as a pre-merge sanity check.
## Overview
```mermaid
flowchart LR
subgraph A[Host Machine]
    A-1["Repo File Structure"]
    A-2(docker run ... make)
    end

subgraph B[Docker Container]
    B-1["/usr/local/cpputest"]
    B-2["/usr/src/"]

subgraph C[CppuTest Test Framework]
    C1[test_runner]
    test_x
    test_y
    test_z
    
    end
    end

    A-1 -. bind mount directory .-> B-2
    A-2 --> |invokes| C1
    B-1 -.-> |provides cpputest| C1
    B-2 -.-> |provides source files| C1
    C1 --> test_x 
    C1 --> test_y
    C1 --> test_z
```
Running unit tests this way also comes with the benefit of being able to make changes to the codebase on your local machine and quickly re-testing via the running container since the volume is bind mounted to the container.
