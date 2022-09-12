#管理下面的文件夹内的Makefile

SUBDIRS = src/pair	#编译库
SUBDIRS += src

LIB_PATH = ./lib

#定义一个函数，遍历所有的$(SUBDIRS)，$1是参数
define make_subdir
@for i in $(SUBDIRS); do\
(cd $$i && make $1)	\
done;
endef


#默认的目标为编译所有子目录
ALL:
	$(shell if ! test -d $(LIB_PATH); then mkdir $(LIB_PATH); fi;)
	$(call make_subdir)

#清空所有的子目录
clean:
	$(shell if test -d $(LIB_PATH); then rm -rf $(LIB_PATH); fi;)
	$(call make_subdir,clean)

# 把子目录里生成的程序或so都复制到$(BIN_PATH)目录下
install:
	$(shell if ! test -d $(LIB_PATH); then mkdir $(LIB_PATH); fi;)
	$(call make_subdir, install)