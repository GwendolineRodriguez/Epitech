#! /bin/bash

MF="Makefile"
REP=""
SOURCES=""
HEADERS=""
LIBS=""
EXEC=""
COMP=""
CFLAGS=""
LDFLAGS=""
RM="rm -f"
ZIP=""
SVG=""
TMP=""

if [ $# = 1 ]
then
   while read line
   do
       if [[ $line =~ "REP;" ]]; then REP=$line;
       elif [[ $line =~ ".c" ]]; then TMP=$line;
	SOURCES=$SOURCES" "$(echo $TMP | cut -d ";" -f1);
       elif [[ $line =~ "HEADERS" ]]; then HEADERS=$line;
       elif [[ $line =~ "LIBS" ]]; then LIBS=$line;
       elif [[ $line =~ "EXEC" ]]; then EXEC=$line;
       elif [[ $line =~ "COMP" ]]; then COMP=$line;
       elif [[ $line =~ "CFLAGS" ]]; then CFLAGS=$line;
       elif [[ $line =~ "LDFLAGS" ]]; then LDFLAGS=$line;
       elif [[ $line =~ "UNZIPFLAGS" ]]; then UNZIPFLAGS=$line;
       elif [[ $line =~ "ZIPFLAGS" ]]; then ZIPFLAGS=$line;
       elif [[ $line =~ "UNZIP;" ]]; then UNZIP=$line;
       elif [[ $line =~ "ZIP;" ]]; then ZIP=$line;
       elif [[ $line =~ "REP_SVG" ]]; then SVG=$line;
       fi
   done < $1

   REP=$(echo $REP | cut -d ";" -f2)
   HEADERS=$(echo $HEADERS | cut -d ";" -f2)
   LIBS=$(echo $LIBS | cut -d ";" -f2)
   EXEC=$(echo $EXEC | cut -d ";" -f2)
   COMP=$(echo $COMP | cut -d ";" -f2)
   CFLAGS=$(echo $CFLAGS | cut -d ";" -f2)
   LDFLAGS=$(echo $LDFLAGS | cut -d ";" -f2)
   ZIP=$(echo $ZIP | cut -d ";" -f2)".tar"
   SVG=$(echo $SVG | cut -d ";" -f2)
   ZIPFLAGS=$(echo $ZIPFLAGS | cut -d ";" -f2)
   UNZIP=$(echo $UNZIP | cut -d ";" -f2)
   UNZIPFLAGS=$(echo $UNZIPFLAGS | cut -d ";" -f2)

   if [ "$REP" != "" ]
      then mkdir -p $REP
	   REP=$(echo $REP"/")
   fi
   mkdir -p $SVG
   echo "COLOR_E = \033[0m" > $REP$MF;
   echo "" >> $REP$MF;
   echo "COLOR_B = \033[32m" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "COLOR_C = \033[31m" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "PROM_1  = \$(COLOR_B)[Compilation succeeded]\$(COLOR_E)" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "PROM_2  = \$(COLOR_B)[Sources Objects Removed]\$(COLOR_E)" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "PROM_3  = \$(COLOR_B)[Sources Names Removed]\$(COLOR_E)" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "PROM_4  = \$(COLOR_C)[Compilation failed]\$(COLOR_E)" >> $REP$MF;
   echo "" >> $REP$MF;
   if [ "$CFLAGS" != "" ]
   then echo "CFLAGS +=" $CFLAGS >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   if [ "$LDFLAGS" != "" ]
   then echo "LDFLAGS +=" $LDFLAGS >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   echo "NAME		=       " $EXEC >> $REP$MF;
   echo "" >> $REP$MF;
   echo "SRC		=	" $SOURCES >> $REP$MF;
   echo "" >> $REP$MF;
   echo "OBJ		=	\$(SRC:.c=.o)" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "COMP		=	" $COMP >> $REP$MF;
   echo "" >> $REP$MF;
   echo "RM		=	" $RM >> $REP$MF;
   echo "" >> $REP$MF;
   if [ "$LIBS" != "" ]
   then echo "LIBS		=	" $LIBS >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   if [ "$ZIP" != "" ]
   then echo "ZIP		=	" $ZIP >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   if [ "$ZIPFLAGS" != "" ]
   then echo "ZIPFLAGS	=	" $ZIPFLAGS >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   if [ "$UNZIP" != "" ]
   then echo "UNZIP		=	" $UNZIP >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   if [ "$UNZIPFLAGS" != "" ]
   then echo "UNZIPFLAGS	=	" $UNZIPFLAGS >> $REP$MF;
	echo "" >> $REP$MF;
   fi
   echo "all:	\$(NAME)" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "\$(NAME):	\$(OBJ)" >> $REP$MF;
   echo "	@\$(COMP) \$(OBJ) -o \$(NAME) \$(LDFLAGS) && echo -e \"\$(PROM_1)\" || (echo -e \"\$(PROM_4)\" >&2)1> /dev/null" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "clean:" >> $REP$MF;
   echo "	@\$(RM) \$(OBJ)" >> $REP$MF;
   echo "	@echo -e \"\$(PROM_2)\"" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "fclean:		clean" >> $REP$MF;
   echo "	@\$(RM) \$(NAME)" >> $REP$MF;
   echo "	@echo -e \"\$(PROM_3)\"" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "re:			fclean all" >> $REP$MF;
   echo "" >> $REP$MF;
   echo "archive:		\$(UNZIP) \$(ZIPFLAGS) \$(ZIP) * && echo \"Fichier \$(ZIP) généré.\n\"" >> $REP$MF
fi
