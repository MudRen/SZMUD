// July 31,2000
// Code by April
// /gumu/shishi3.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ͨʯ�ң��ı���һЩ���ӣ���֪��ʲô�á�
LONG);

	 set("exits",([ 
		"south" : __DIR__"mudao18",
		 ])
			  );

        create_door("south", "ľ��", "north");

	  set("cost",1);

		  setup();

}

