// July 31,2000
// Code by April
// /gumu/mudao16.c

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
		"west" : __DIR__"bingqifang",
		"east" : __DIR__"mudao15",
		"south" : __DIR__"chufang",
		"north" : __DIR__"yaofang",
		 ])
			  );
	  set("cost",1);

		  setup();

}

