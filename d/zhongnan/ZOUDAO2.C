// Code of ShenZhou
// road: /zhongnan/zoudao2.c

inherit ROOM;

void create()
{
        set("short","�ߵ�");

        set("long",@LONG
����ɭɭ���ߵ���Ҳ��֪����ͨ���Ĩ�ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ���ߵ�����Զһ����
�������ˡ��ߵ���ͷ�ƺ���Щ���������������Ϸ���һ˿���������⣬��
�෽�����İ����ߵ���
LONG);

        set("exits",([ "west" : __DIR__"zoudao2",
                        "south" : __DIR__"dating",
                        "east" : __DIR__"zoudao2",
                        "north" : __DIR__"zoudao1",
                      ])
           );
	  set("cost",1);

	 setup();
}

