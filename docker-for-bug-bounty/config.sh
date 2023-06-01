#!/bin/bash

apt-get install gcc libpcap-dev zsh python3 python3-pip -y
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
export ZSH_CUSTOM=/root/.oh-my-zsh/custom
curl -OL https://golang.org/dl/go1.19.linux-amd64.tar.gz ; sudo tar -C /usr/local -xvf go1.19.linux-amd64.tar.gz ; cp /usr/local/go/bin/go /usr/bin
wget https://github.com/neovim/neovim/releases/download/nightly/nvim-linux64.tar.gz ; tar xzvf nvim-linux64.tar.gz ; mv ./nvim-linux64/bin/nvim /usr/bin ; bash <(curl -s https://raw.githubusercontent.com/lunarvim/lunarvim/master/utils/installer/install.sh)
git clone https://github.com/spaceship-prompt/spaceship-prompt.git "$ZSH_CUSTOM/themes/spaceship-prompt" --depth=1 ; ln -s "$ZSH_CUSTOM/themes/spaceship-prompt/spaceship.zsh-theme" "$ZSH_CUSTOM/themes/spaceship.zsh-theme"
mv .zshrc ~/.zshrc
mv config.yaml ~/.config/nuclei/
mv provider-config.yaml ~/.config/notify/
mv .tmux.conf ~/.tmux.conf ; tmux source ~/.tmux.conf
wget https://raw.github.com/trapd00r/LS_COLORS/master/LS_COLORS -O ~/.dircolors
echo 'eval $(dircolors ~/.dircolors)' >> ~/.zshrc
source ~/.zshrc