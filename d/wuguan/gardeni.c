//Creatied by sleep on k1-08-11
//Modified by Zyu on k1-08-11
// road : /d/wuguan/gardeni.c

inherit ROOM;

void create()
{
        set("short", "��԰�");
        set("long", @LONG
��֪�����У����Ѿ��ߵ��˻�԰��ˡ�����������ǻ�����������
��Ʈ�����ʻ������㡣��Զ����һ����Բ�ε�͸�����ӣ����Ҳ�������
���˿�����˵���������󻨲ݵ����Ұɡ�
LONG
        );

        set("objects", ([
                 __DIR__"obj/shizi" : 1,
                 __DIR__"obj/flower1" : 1,
                 __DIR__"obj/flower2" : 1,
	]));
        set("exits", ([
                "southwest" : __DIR__"wenshi",
                "west" : __DIR__"garden",
        ]));

        set("cost", 1);
        set("outdoors", "wuguan");

        setup();
}

void init()
{
	object me = this_player();

	add_action("go_sw", "southwest");
	add_action("do_go", "go");
}

int go_sw(string arg)
{
	object me = this_player();

	if ( arg ) return 0;

        if ( me->query("combat_exp") <= 4000 )
	{
		tell_object(me,"��ľ��鲻�㣬�����޷���ɻ��������������\n");
		return 1;
	}

	return 0;
}

int do_go(string arg)
{
	object me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg != "southwest" ) return 0;

        if ( me->query("combat_exp") <= 4000 )
	{
		tell_object(me,"��ľ��鲻�㣬�����޷���ɻ��������������\n");
		return 1;
	}

	return 0;
}