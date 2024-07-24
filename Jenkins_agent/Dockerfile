FROM jenkins/agent:jdk11

USER root

# Install tools
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        git \
        build-essential \
        gcc \
        g++ \
        cmake \
        libgtest-dev \
        valgrind && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Build GTest library
RUN cd /usr/src/googletest && \
    cmake . && \
    cmake --build . --target install

USER jenkins