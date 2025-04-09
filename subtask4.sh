#!/bin/bash

# 1. Обновил C++ код и тесты

# 2. Пересобрал образ
docker build -f Dockerfile.app -t mikev182/git-task-app:latest .

# 3. Запушил образ
docker push mikev182/git-task-app:latest

# 4. Обновил Helm-релиз
helm upgrade --install test-release ./helm/test-repo-chart \
  --set app.image=mikev182/git-task-app \
  --set app.tag=latest
