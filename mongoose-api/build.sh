#!/bin/sh

# This script only builds the API for local testing, run this to actually see if 
# the Mongoose web server code is actually working

gcc mongoose_api.c mongoose.c -o mongoose_api -pthread