// July 31,2000
// Code by April
// /gumu/shishi_m4.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ�����߼�����ʯ�ң��ıڹ��ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"east" : __DIR__"mudao9",
		 ])
			  );

        create_door("east", "ľ��", "west");

	  set("cost",1);

		  setup();

}

