// Code of ShenZhou
// hz_west.c �����ֲ��
// Shan: 96/06/28

#include <ansi.h>
inherit ROOM;

int do_sit(string);
void delete_served(object);

void create()
{
        set("short", "�����ֲ��");
	set("long", @LONG
�����ǽ𶥻����������ǽӴ���ͼ������ĵط������ڰ��ż������ӣ�
����Χ���������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ������顣�м�
λ���������Ʒ����������ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ��
��Ĺ�������һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ��
�д����ˡ��ϱ����ȴ���(chuang)��
LONG
	);
	set("exits", ([
		"east" : __DIR__"hz_front",
	]));

    set("item_desc", ([
            "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
            "chair" : "һ�Ѻ�ľ���ӡ�\n",
	    "chuang" : "������Կ�����üɽ������ɽ���������и�С����(paizi)��\n",
	    "paizi" : "������д�ţ���������Ϊ���أ�������(jump)����\n",
        ]));

        set("objects",([
                __DIR__"npc/wenqing" : 1,
//                CLASS_D("emei") + "/jingxin" : 1,
        ]));

	set("cost", 0);
	setup();

}

void init()
{
        add_action("do_sit", "sit");
	add_action("do_jump","jump");
}

int do_jump(string arg)
{

        object me = this_player();

        if (arg!="chuang") return 0;
        message_vision("$N���˲�ע�⣬�������⡣\n", me);
        me->move(__DIR__"hztrip1");
        message_vision("$N�ӻ�����������������\n", me);
        return 1;
}


int do_sit(string arg)
{

        object me;
        object wenqing;

        me = this_player();
        if ( !arg || (arg != "chair") )
                return notify_fail("��ϯ�ض���������������㵵�Ŀ�⡣\n");

	if( !objectp(wenqing = present("wenqing", environment(me))) )
                return notify_fail("����������Ϣ��û����������㡣\n");

	if( me->query_temp("marks/served") )
	{
		message_vision("����Сʦ̫Ц�Ŷ�$N˵���һ�æ���ţ���������Ϣ��Ϣ�ɡ�\n", me);
		return notify_fail("");
	}

	message_vision("$N������ǰ������СʦЦ�Ź����д���\n", me);
	wenqing->serve_tea(me) ;
	
	me->set_temp("marks/served", 1);
	call_out("delete_served", 10, me);
	return 1;
}


void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{

        if (  (dir == "east")
           && ( present("xiang cha", this_player())
                || present("dian xin", this_player()) ) 
           && objectp(present("wenqing", environment(me))) ) {
	message_vision("����Сʦ̫��$N��û���꣬˵������λ�������������߰ɡ�", me);
        return notify_fail("\n");
	}

        return ::valid_leave(me, dir);
}

