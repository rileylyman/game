
all:
	emcc -o index.html main.c \
		-Os -Wall libraylib.a -I. -I../raylib/src/ -L. -s USE_GLFW=3 -DPLATFORM_WEB \
		--shell-file shell.html

watch:
	while true; do $(MAKE) -q || $(MAKE); sleep 0.5; done