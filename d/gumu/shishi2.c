// July 31,2000
// Code by April
// /gumu/shishi2.c

inherit ROOM;

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����һ����ͨʯ�ң��ı���һЩ���ӣ���֪��ʲô�á�
LONG);

	 set("exits",([ 
		"north" : __DIR__"mudao17",
		 ])
			  );

	  set("cost",1);

		  setup();

}

