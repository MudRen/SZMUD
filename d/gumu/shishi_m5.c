// July 31,2000
// Code by April
// /gumu/shishi_m5.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ɼ�����ʯ�ң��ıڹ��ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao10",
		 ])
			  );

        create_door("south", "ľ��", "north");

	  set("cost",1);

		  setup();

}

