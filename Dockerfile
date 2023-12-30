FROM ubuntu:latest
LABEL authors="arch"

ENTRYPOINT ["top", "-b"]