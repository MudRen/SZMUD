// July 31,2000
// Code by April
// /gumu/mudao5.c

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
		"west" : __DIR__"mudao4",
		"north" : __DIR__"zhangshi3",
		"east" : __DIR__"mudao6",
		"south" : __DIR__"shishi_m7",
		 ])
			  );

        create_door("south", "ľ��", "north");

	  set("cost",1);

		  setup();

}

