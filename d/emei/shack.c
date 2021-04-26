// Code of ShenZhou
// Shan: 96/07/09

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ƕ���ɽ����һ���򵥵Ĳ�����϶���Щ�ϻ����ܶ���ɽ���οͶ���
������Щ��ɽ��Ʒ��������и��ھ���������һ����ǡ�
LONG
        );
        set("exits", ([
	  "east" : __DIR__"shijie1",
	  "west" : __DIR__"majiu1",
        ]));

        set("objects", ([
                __DIR__"npc/seller": 1 ]) );

        set("no_clean_up", 0);
	set("outdoors", "emei");

        setup();
}

void init()
{
        add_action("do_move", "move");
}

int do_move(string arg)
{
        object me;
        mapping fam;

        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="mugai" || arg=="lid" )
        {
		if(me->query("rided"))
                return notify_fail("����������������ɣ�\n");
                if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" )
                {
                        message_vision("$N�ƿ����ϵ�ľ�ǣ�ֻ����ھ��Ѿ�Ǭ�ԣ������и�С���ӡ�\n", me);
                        message("vision",
                                me->name() + "����ؤ�����ǹ���һ����������������ȥ��\n",
                                environment(me), ({me}) );
                        me->move("/d/gaibang/underem");
                        message("vision",
                                me->name() + "�Ӿ������˽�����\n",
                                environment(me), ({me}) );
                        return 1;
                }
                else
                        return notify_fail("��ôС�ľ�������ý�ȥ��\n");
        }
}
