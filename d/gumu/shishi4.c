// July 31,2000
// Code by April
// /gumu/shishi4.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ͨʯ�ң��ı���һЩ���ӣ���֪��ʲô�á�
LONG);

	 set("exits",([ 
		"north" : __DIR__"mudao18",
		 ])
			  );

	  set("cost",1);

		  setup();

}

