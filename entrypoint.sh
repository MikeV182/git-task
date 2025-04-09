#!/bin/bash

sleep 10

if [ -f /app/test_results/test_results.xml ]; then
  echo "<html><body><h1>Test Results</h1>" > /usr/share/nginx/html/index.html
  cat /app/test_results/test_results.xml >> /usr/share/nginx/html/index.html
  echo "</body></html>" >> /usr/share/nginx/html/index.html
else
  echo "<html><body><h1>Error: No test results found!</h1></body></html>" > /usr/share/nginx/html/index.html
fi

nginx -g 'daemon off;'








# sleep 5
# docker logs app > /usr/share/nginx/html/index.html
# nginx -g 'daemon off;'
