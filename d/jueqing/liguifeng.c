// Filename:   /d/jueqinggu/liguifeng.c
// Jiuer Aug 15, 2001

#include <room.h>
inherit ROOM;

void create()
{

                  set("short","�����");
                  set("long",@LONG
��Ŀ�Ĺˣ�ԭ���㴦����һ������֮������������ľï�ܣ�Զ��
�ɼ�ʯׯ�������������֮ң����ɽ�������壬���������ഫ����
�������������˭Ҳ����������ɽ�ں��п��ʯ (stone)������
��ϸ���������׷��֡�
LONG);

                  set("objects",([
		CLASS_D("jueqing") + "/fan" : 1,
                ]));
                  set("item_desc", ([
                           "stone" : "һ���ʯ������ȥֻ���а�ʮ���ء�\n"
                             ]));
                  set("outdoors","jueqing");
                  set("cost",1);
                  setup();      
}

 void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me;
        me = this_player();
        if ( arg = "stone")
		{
			message_vision("$N�������ƿ���ʯ���������һ���ܵ���$N��ԥ��һ�£��������˽�ȥ��\n",me);
        
			me->move(__DIR__"midao"); 
			me->start_busy (0);    
		}
		return 1;   
}
