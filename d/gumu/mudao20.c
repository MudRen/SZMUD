// July 31,2000
// Code by April
// /gumu/mudao20.c

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
		"west" : __DIR__"mudao21",
		"east" : __FILE__,
		"south" : __DIR__"mudao19",
		"north" : __FILE__,
		 ])
			  );

	  set("cost",1);

		  setup();

}

