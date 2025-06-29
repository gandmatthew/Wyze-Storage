FROM ubuntu:22.04
RUN DEBIAN_FRONTEND=noninteractive \
    apt-get update \
    && apt-get install gcc-mipsel-linux-gnu g++-mipsel-linux-gnu qemu qemu-user

RUN mkdir -p    /src/build
ENTRYPOINT cd   /src/build