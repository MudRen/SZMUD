// July 31,2000
// Code by April
// /gumu/shishi_m3.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ�����߼�����ʯ�ң��ıڹ��ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"west" : __DIR__"mudao8",
		 ])
			  );

        create_door("west", "ľ��", "east");

	  set("cost",1);

		  setup();

}

