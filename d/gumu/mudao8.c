// July 31,2000
// Code by April
// /gumu/mudao8.c

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
		"west" : __FILE__,
		"north" : __DIR__"mudao9",
		"east" : __DIR__"shishi_m3",
		"south" : __DIR__"mudao3",
		 ])
			  );
        create_door("east", "ľ��", "west");

	  set("cost",1);

		  setup();

}

