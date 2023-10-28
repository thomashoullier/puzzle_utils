FROM alpine:3.18
RUN apk add --no-cache git cmake g++ make boost-dev curl gnupg coreutils perl-utils
RUN apk add lcov --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing/

ENTRYPOINT ["/bin/sh"]