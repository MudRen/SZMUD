// July 31,2000
// Code by April
// /gumu/shishi_m1.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ�����߼�����ʯ�ң��ıڹ��ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao2",
		 ])
			  );

        create_door("south", "ľ��", "north");

	  set("cost",1);

		  setup();

}

