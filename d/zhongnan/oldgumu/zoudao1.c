// Code of ShenZhou
// road: /zhongnan/zoudao1.c

inherit ROOM;

void create()
{
        set("short","�ߵ�");

        set("long",@LONG
����ɭɭ���ߵ���Ҳ��֪����ͨ���Ĩ�ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ���ߵ�����Զһ����
�������ˡ��ߵ���ͷ�ƺ���Щ�������������˱����ǹ�Ĺ�������⣬����
�������İ����ߵ���
LONG);

		  set("exits",([ "west" : __DIR__"zoudao1",
								"south" : __DIR__"zoudao2",
								"east" : __DIR__"zoudao1",
								"out" : __DIR__"gumu",
							 ])
			  );
	  set("cost",1);

		  setup();
}

