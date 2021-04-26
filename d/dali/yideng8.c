// Code of ShenZhou
// yideng quest room 8

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
ɽ·�͵��˾�ͷ��ǰ��������Լ�����ʯ�������������ɽ��֮
�䣬�������֣�������������ʯ����͹��ƽ���ּ�����������֮�У�
ʯ���ﻬ�쳣��ǰ�治Զ����ʯ��ͻȻ�Ͽ���һ�ο�ȱ(gap)��
LONG
        );
        set("exits", ([
			"down":__DIR__"yideng7",
        ]));

        set("item_desc",([
                "gap" : "һ��һ�������Ŀ�ȱ��ӭ��ɽ�����ң����°���ƮƮ�����ˤ��ȥ ... ...\n",
                ]));
        
	set("invalid_startroom", 1);
        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
        object me = this_player();
        if ( !arg || arg != "gap" )
                return notify_fail( "ʲô��\n");

        message_vision("$N��������ȱ������ȥ��\n", me);
        if ( me->query_skill("dodge",1) <= 80) {
                message_vision("$N���ие�һ��������ӿ����������û���������棬����һ��\n", me);
                message_vision("�Һ����ӿ���ֱ׹����ȥ��\n", me);
                me->receive_wound("qi", me->query("max_qi")+100, "ˤ�����⽴");
        }
        if ( me->query_skill("dodge",1) > 80 ) {
                me->move(__DIR__"yideng9");
                message("vision", me->name() + "�����ɶ������˹�����\n",environment(me), ({me}) );
        }
        return 1;
} 
