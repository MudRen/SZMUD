// July 31,2000
// Code by April
// /gumu/mudao11.c

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
		"west" : __DIR__"mudao7",
		"north" : __FILE__,
		"east" : __FILE__,
		"south" : __DIR__"mudao12",
		 ])
			  );
	  set("cost",1);

		  setup();

}

