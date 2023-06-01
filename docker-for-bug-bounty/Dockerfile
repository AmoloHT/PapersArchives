FROM python:3.10.4-slim-buster
COPY --from=golang:1.18.2-bullseye /usr/local/go/ /usr/local/go/
WORKDIR /root

ENV PATH="/usr/local/go/bin:${PATH}"
ENV GOPATH /go
ENV PATH $GOPATH/bin:$PATH

RUN apt-get update
RUN apt-get -qq -y install vim tmux make gcc zsh
RUN apt-get -qq -y install curl unzip tar wget libpcap-dev
RUN mkdir -p "$GOPATH/src" "$GOPATH/bin" && chmod -R 777 "$GOPATH"
RUN mkdir /root/tools
RUN mkdir /root/setup
RUN echo "source ~/tools/pdiscovery-bot/func.sh" >> ~/.bashrc

COPY install_hacktools.sh /root/setup/install_hacktools.sh
COPY install.sh /root/setup/install.sh
COPY scon /usr/bin/scon
COPY pdiscovery-bot /root/tools/pdiscovery-bot
COPY config.sh /root/setup/config.sh
COPY provider-config.yaml /root/setup/provider-config.yaml
COPY config.yaml /root/setup/config.yaml
COPY .zshrc /root/setup/.zshrc
COPY .tmux.conf /root/setup/.tmux.conf
COPY zsh_instalation.sh /root/setup/zsh_instalation.sh

RUN chmod +x /root/setup/install* /root/setup/config.sh
RUN chmod +x /usr/bin/scon
RUN bash /root/setup/install.sh
RUN bash /root/setup/install_hacktools.sh