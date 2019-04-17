cc := gcc
src_dir := src
out_dir := out
WORK_NAME := demo
woke_dir := /woke/c_woke/demo
window_ml_dir := \woke\c_woke\demo

# sdl
sdl_path := ${woke_dir}/lib/SDL
sdl_config := -lmingw32 -lSDL2main -lSDL2 
sdl_include := ${sdl_path}/include/SDL2
sdl_lib := ${sdl_path}/lib

vpath %.c ${src_dir}
vpath %.o ${src_dir}

srcs := $(wildcard *.c ${src_dir}/*.c)
objs := $(patsubst %c, %o, $(srcs))



build : ${objs}
	${cc} -o ${out_dir}/${WORK_NAME}.exe ${objs} -L${sdl_lib} ${sdl_config}
	cd ${sdl_path}/bin && copy SDL2.dll D:${window_ml_dir}\${out_dir}

%.o : %.c
	${cc} -c -I${sdl_include} $< -o $@ 

run : ${out_dir}/${WORK_NAME}.exe
	${out_dir}/${WORK_NAME}.exe

echo:
	echo ${objs}

.PHONY : clean

clean :
	cd ${src_dir} &&  del /Q *.o
	cd ${out_dir} && del /Q *