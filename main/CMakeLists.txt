set(Main_SRCS AuthenticationService.cpp ProfileDao.cpp RsaTokenDao.cpp Context.cpp Birthday.cpp)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} Main_SRCS)

add_library(core ${Main_SRCS})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} core)
