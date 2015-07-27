FROM docker/whalesay:latest
RUN apt-get update -y && apt-get -y install fortunes
CMD /usr/games/fortune -a | cowsay
