// Code of ShenZhou
// road: /zhongnan/zoudao3.c

inherit ROOM;

void create()
{
        set("short","�ߵ�");

        set("long",@LONG
����ɭɭ���ߵ���Ҳ��֪����ͨ���Ĩ�ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ���ߵ�����Զһ����
�������ˡ��ߵ���ͷ�ƺ���Щ���������������ǳ����������������ҡ���
�����Ҵ�����
LONG);

        set("exits",([ "west" : __DIR__"dating",
                        "north" : __DIR__"kitchen2",
                        "south" : __DIR__"lianggongshi1",

                      ])
           );
	  set("cost",1);
	  setup();
}

