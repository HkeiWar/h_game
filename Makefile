cc := gcc
src_dir := src
out_dir := out
WORK_NAME := demo
woke_dir := /woke/c_woke/demo
window_ml_dir := \woke\c_woke\demo
disk := D:
assets := assets

# sdl
sdl_path := ${woke_dir}/lib/SDL
sdl_include := ${sdl_path}/include/SDL2
sdl_lib := ${sdl_path}/lib
sdl_config := -lmingw32 -lSDL2main -lSDL2 

# sdl_image
sdl_image_path := ${woke_dir}/lib/SDL_image
sdl_image_include := ${sdl_image_path}/include/SDL2
sdl_image_lib := ${sdl_image_path}/lib
sdl_image_config := -lSDL2_image

# base
base_op := ${sdl_config} ${sdl_image_config}
base_include := ${sdl_image_include} ${sdl_include}
base_lib := ${sdl_lib} ${sdl_image_lib}

vpath %.c ${src_dir}
vpath %.o ${src_dir}

srcs := $(wildcard *.c ${src_dir}/*.c)
objs := $(patsubst %c, %o, $(srcs))


build : ${objs}
	${cc} -o ${out_dir}/${WORK_NAME}.exe ${objs} $(addprefix -L,$(base_lib)) ${base_op}
	cd ${sdl_path}/bin && copy SDL2.dll ${disk}${window_ml_dir}\${out_dir}
	cd ${disk}${window_ml_dir}\${out_dir} && mkdir ${assets}
	copy ${assets} ${disk}${window_ml_dir}\${out_dir}\${assets}

%.o : %.c
	${cc} -c $(addprefix -I,$(base_include)) $< -o $@ 

run : ${out_dir}/${WORK_NAME}.exe
	${out_dir}/${WORK_NAME}.exe

echo:
	echo ${objs}

.PHONY : clean

clean :
	cd ${src_dir} &&  del /Q *.o
	rd /s/Q out
	mkdir out
	