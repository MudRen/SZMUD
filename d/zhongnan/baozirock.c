// Code of ShenZhou
// road: /zhongnan/baozirock.c

inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
һ·������ɽ·��Խ��Խ�ա�ֻ����ͺͺ��ɽ·�����Ծ��ǹ�ʯ����
������������Ԩ���첻���ס�ǰ����Զ����һ���ʯ�����������ı����ҡ�
�ٿ����ۣ�����������������֣�����һ�����˱��Ÿ����Ӱ㣬ϸ�ĺǻ���
���Ϻ�������һƬ���֡�
LONG);

        set("exits",([ "south" : __DIR__"shulin1",
                        "west" : __DIR__"shulin2",
                      ])
           );
	  set("cost",2);
        set("fjing", 1);
	  set("objects", ([
				 __DIR__"npc/chen-zy" : 1,
		  ]));
	  set("outdoors", "zhongnan");

	  setup();
}
