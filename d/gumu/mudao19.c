// July 31,2000
// Code by April
// /gumu/mudao19.c

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
		"west" : __DIR__"liangongshi1",
		"east" : __DIR__"mudao14",
		"south" : __FILE__,
		"north" : __DIR__"mudao20",
		 ])
			  );

	  set("cost",1);

		  setup();

}

