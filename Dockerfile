FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive
ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

# note that we need to install a newer version of cmake through a pass
RUN apt-get update --fix-missing
RUN apt-get install -y --no-install-recommends llvm-11* clang-11* gdb git curl zsh tmux wget libxml2 libarchive13 autoconf vim libgmp-dev libmpfr-dev libmpc-dev flex

RUN cp /usr/bin/llvm-profdata-11 /usr/bin/llvm-profdata && cp /usr/bin/llvm-cov-11 /usr/bin/llvm-cov && cp /usr/bin/clang-11 /usr/bin/clang

# GIT STUFF
RUN git config --global core.fileMode false && \
    git config --global diff.ignoreSubmodules dirty && \
    git config --global core.autocrlf input && \
    git config --global --add oh-my-zsh.hide-status 1 && \
    git config --global --add oh-my-zsh.hide-dirty 1

# PIP
ENV PIP_ROOT_USER_ACTION=ignore

RUN apt-get update -y \
    && apt-get install -y python3-pip
RUN pip install --upgrade pip

WORKDIR /mem_leak

COPY . /mem_leak/AddressWatcher

RUN mkdir build

RUN mkdir testing

WORKDIR /mem_leak/build

RUN ../AddressWatcher/configure --prefix=/mem_leak/goodgcc --enable-languages=c,c++ --disable-bootstrap --disable-multilib

RUN make -j4
RUN make install

WORKDIR /mem_leak

ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/mem_leak/goodgcc/lib64

ENV ASAN_OPTIONS="log_path=/mem_leak/testing/asan:halt_on_error=0:detect_leaks=1:address_watcher=1"


# ZSH (Optional)
# RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
#     -t robbyrussell \
#     -p git -p 'history-substring-search' \
#     -a 'bindkey "\$terminfo[kcuu1]" history-substring-search-up' \
#     -a 'bindkey "\$terminfo[kcud1]" history-substring-search-down' \
#     -p https://github.com/zsh-users/zsh-autosuggestions \
#     -p https://github.com/zsh-users/zsh-completions \
#     -p https://github.com/zsh-users/zsh-syntax-highlighting