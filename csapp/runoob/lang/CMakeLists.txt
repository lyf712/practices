# 添加源文件
aux_source_directory(. LANG_SRC)
# 添加链接库
add_library(lang ${LANG_SRC})

# add_executable(test_lang ${LANG_SRC} LangBaseReview.cpp)