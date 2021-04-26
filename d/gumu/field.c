// Oct 31,2001
// Code by Jiuer
// /gumu/field.c

inherit ROOM;

void create()
{
        set("short","乱石林");

        set("long",@LONG
这是终南山西南角的一片乱石地，齐腰高的青草夹杂着大大小小的山
石。石缝里顽强地夹生着几株枝叶茂密的松柏。
LONG);
		set("exits",([ 
			"west" : __DIR__"grassland",
			"south" : __DIR__"huangshaling",
			])
			);
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

