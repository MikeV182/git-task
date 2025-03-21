#!/bin/bash

# Ожидание запуска контейнера app
sleep 5

# docker logs $(docker ps -q --filter "name=app") > /usr/share/nginx/html/index.html
docker logs app > /usr/share/nginx/html/index.html

nginx -g 'daemon off;'