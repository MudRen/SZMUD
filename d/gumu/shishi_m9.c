// July 31,2000
// Code by April
// /gumu/shishi_m9.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ��ʮ�ɼ����ľ޴�ʯ�ң��տյ����ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao7",
		 ])
			  );

        create_door("south", "ľ��", "north");

	  set("cost",1);

		  setup();

}

