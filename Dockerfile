FROM ubuntu:24.04

RUN apt update
RUN apt dist-upgrade -y

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y locales locales-all

RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    dpkg-reconfigure --frontend=noninteractive locales && \
    update-locale LANG=en_US.UTF-8

RUN apt install -y software-properties-common
RUN apt install -y neovim
RUN apt install -y git git-lfs gettext cmake
RUN apt install -y git uncrustify build-essential curl wget zip
RUN apt install -y make gcc-arm-none-eabi
RUN apt install -y python3 python3-pip python3-venv

# RUN git clone https://github.com/asdf-vm/asdf.git ~/.asdf --branch v0.15.0
# RUN echo '. $HOME/.asdf/asdf.sh' >> ~/.bashrc
# RUN echo '. $HOME/.asdf/completions/asdf.bash'  >> ~/.bashrc
