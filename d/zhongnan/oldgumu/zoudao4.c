// Code of ShenZhou
// road: /zhongnan/zoudao4.c

inherit ROOM;

void create()
{
        set("short","�ߵ�");

        set("long",@LONG
����ɭɭ���ߵ���Ҳ��֪����ͨ���Ĩ�ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ���ߵ�����Զһ����
�������ˡ��ߵ���ͷ�ƺ���Щ�������������ߵ����Ӵ�������ͨ������Ϣ
�ҡ�������һ�����յ�ʯ�š�
LONG);

		  set("exits",([ "west" : __DIR__"shishi",
								"south" : __DIR__"nyudiziqinshi",
								"east" : __DIR__"dating",
								])
			  );
	  set("cost",1);

        setup();
        replace_program(ROOM);
}

