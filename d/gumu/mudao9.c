// July 31,2000
// Code by April
// /gumu/mudao9.c

inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
����ɭɭ��Ĺ����Ҳ��֪����ͨ���Ķ��ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ��Ĺ������Զһ�����
�������ˡ�Ĺ����ͷ�ƺ���Щ����������
LONG);

	 set("exits",([ 
		"west" : __DIR__"shishi_m4",
		"north" : __FILE__,
		"east" : __DIR__"mudao10",
		"south" : __DIR__"mudao8",
		 ])
			  );
        create_door("west", "ľ��", "east");

	  set("cost",1);

		  setup();

}

