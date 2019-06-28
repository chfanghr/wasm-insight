#!/bin/sh

sudo apt install -y wget

wget https://dl.google.com/go/go1.12.6.linux-amd64.tar.gz

sudo tar -C /usr/local -xzf go1.12.6.linux-amd64.tar.gz