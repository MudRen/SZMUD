// July 31,2000
// Code by April
// /gumu/mudao14.c

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
		"west" : __DIR__"mudao19",
		"south" : __DIR__"dating",
		"east" : __DIR__"mudao17",
		"north" : __DIR__"houtang",
		 ])
			  );
	  set("cost",1);

		  setup();

}

