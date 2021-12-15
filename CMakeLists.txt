project("oblivious-transfer")

add_executable(${PROJECT_NAME} src/main.c src/crypto/rsa.c src/math/algorithms.c)