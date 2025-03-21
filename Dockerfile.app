FROM gcc:latest

RUN apt-get update && apt-get install -y cmake git

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build \
    && cmake .. \
    && make

CMD ["./build/testproj", "--gtest_output=xml:/app/test_results.xml"]