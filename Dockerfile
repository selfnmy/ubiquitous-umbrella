FROM python:3.13-slim
RUN apt-get update && apt-get install -y --no-install-recommends texlive-xetex texlive-fonts-recommended fonts-anonymous-pro && rm -rf /var/lib/apt/lists/*
LABEL org.opencontainers.image.source=https://github.com/RobotoLev/icpc-trd-template
LABEL org.opencontainers.image.description="Docker-образ для сборки xetex-проектов (см. https://github.com/RobotoLev/icpc-trd-template)"
WORKDIR /build
