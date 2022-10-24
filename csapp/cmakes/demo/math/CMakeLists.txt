# 添加源文件
aux_source_directory(. MATH_SRC)
# 添加链接库
add_library(fun ${MATH_SRC})
# 添加可执行
add_executable(test math.cpp)