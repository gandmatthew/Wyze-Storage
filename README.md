# About
This repository uses wz_mini_hacks to expose the firmware. This code is in active development. This project allows users to share and distribute files over the internet to their WyzeCams using a REST API with Mongoose Web Server. You are required to install the gcc-mipsel-linux-gnu toolchain for this project and compile your own binaries.
# Demo
- WIP
# Installation Steps
- Follow instructions with a compatible WyzeCam using [wz_mini_hacks](https://github.com/gtxaspec/wz_mini_hacks)
- Clone this repository
- Change IP...
- Run `build_local.sh` inside `/mongoose-api` requires GCC toolchain, this creates a local copy for you to test with the `test.py` and `test.txt` to ensure files are being sent over the API
- To create a production copy `docker build -t t20-ingenic-toolchain .`
