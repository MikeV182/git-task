#!/bin/bash

sleep 10

mkdir -p /app/public/

if [ -f /app/test_results/test_results.xml ]; then
  echo "<html><body><h1>Test Results</h1>" > /app/public/index.html
  cat /app/test_results/test_results.xml >> /app/public/index.html
  echo "</body></html>" >> /app/public/index.html
else
  echo "<html><body><h1>Error: No test results found!</h1></body></html>" > /app/public/index.html
fi

# Копируем в стандартный путь Nginx для отображения
cp -r /app/public/* /usr/share/nginx/html/

nginx -g 'daemon off;'
