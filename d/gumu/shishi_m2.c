// July 31,2000
// Code by April
// /gumu/shishi_m2.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ɼ�����ʯ�ң��ıڹ��ģ�ʲôҲû�С�
LONG);

	 set("exits",([ 
		"north" : __DIR__"mudao3",
		 ])
			  );

        create_door("north", "ľ��", "south");

	  set("cost",1);

		  setup();

}

