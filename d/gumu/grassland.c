// Oct 31,2001
// Code by Jiuer
// /gumu/grassland.c

inherit ROOM;

void create()
{
        set("short","青草地");

        set("long",@LONG
这是山腰的一处青草斜坡，走在这里要格外小心，以防滚进树丛之中。
仅够立足的一小片平地处离下面斜坡少说也有六七丈，绕道到青草坡上，
顺着草地上压平的一条路线可寻进树丛，越行树林会越密。
LONG);
		set("exits",([ 
			"east" : __DIR__"field",
			"south" : __DIR__"river",
			])
			);
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

