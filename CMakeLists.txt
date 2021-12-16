project("oblivious_transfer")

add_executable(${PROJECT_NAME}_rsa src/main_rsa.c src/crypto/rsa.c src/math/algorithms.c)
add_executable(${PROJECT_NAME}_obtf src/main_obtf.c src/crypto/rsa.c src/math/algorithms.c src/crypto/obtf.c)