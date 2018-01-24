FROM base/devel:latest
ARG parallel=4

COPY mirrorlist.txt /etc/pacman.d/mirrorlist
RUN pacman -Syyu git emscripten cmake

RUN useradd -m build

USER build
WORKDIR /home/build
RUN git clone https://aur.archlinux.org/binaryen.git

WORKDIR binaryen
ENV MAKEFLAGS -j$parallel
RUN makepkg

USER root
RUN pacman --noconfirm -U binaryen-*.pkg.tar.xz

USER build
WORKDIR /home/build
COPY hello.cpp .
RUN emcc -v  
RUN em++ -o hello.js hello.cpp -s BINARYEN=1 -s DISABLE_EXCEPTION_CATCHING=1 -Os
RUN node hello.js

