#-----------------------------------------------------------------------------
# Makefile
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# Choose a compiler and its options
#--------------------------------------------------------------------------
CC   = gcc
OPTS = -O0
DEBUG = -g -Wall
#--------------------------------------------------------------------------
# Add the names of the directories (Add them after each ./)
#--------------------------------------------------------------------------
#SRCDIR=./src
#OBJDIR=./obj
#INCDIR=./inc
#BINDIR=./bin

#--------------------------------------------------------------------
# Add the rest of the source files. Don't forget to add the '\' character
# to continue the line. You don't need it after the last source file.
# Note: The source directory, $(SRCDIR), needs to be given for each
# individual file. The $(SRCDIR) below shows how it is done for the
# Lab8.c file. Also note that there should only be one SRCS= (i.e. don't
# add more of them as you add files).
#--------------------------------------------------------------------
#//
#--------------------------------------------------------------------
# You don't need to edit the next few lines. They define other flags
# used in the compilation of the source code
#--------------------------------------------------------------------
INCLUDE = $(addprefix -I,$(INCDIR))
OBJS=${SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o}
CFLAGS   = $(OPTS) $(INCLUDE) $(DEBUG)
#--------------------------------------------------------------------
# Add the name of the executable after the $(BINDIR)/
#--------------------------------------------------------------------
all: AsciiToBinary BinaryToAscii
AsciiToBinary: AsciiToBinary.c
	${CC} ${CFLAGS} -o $@ AsciiToBinary.c

BinaryToAscii: BinaryToAscii.c
	${CC} ${CFLAGS} -o $@ BinaryToAscii.c

#--------------------------------------------------------------------
# Add a target below named cleanall that will remove the object files
# as well as the executable
#--------------------------------------------------------------------
clean:
	rm -f AsciiToBinary
	rm -f BinaryToAscii 

