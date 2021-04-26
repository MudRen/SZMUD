// Code of ShenZhou
// hz_east.c �����ֲ��
// Shan: 96/06/28

#include <ansi.h>
inherit ROOM;

int do_sit(string);
void delete_served(object);

void create()
{
        set("short", "�����ֲ��");
	set("long", @LONG
�����ǽ𶥻����ֶ����ǽӴ���ͼ������ĵط������ڰ��ż������ӣ�
����Χ���������ӡ�ǽ�����ż����ֻ���ǽ��һ����ܣ����ϰ������顣�м�
λ���������Ʒ����������ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ��
��Ĺ�������һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰæ��
�д����ˡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"hz_front",
	]));

    set("item_desc", ([
            "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�\n",
            "chair" : "һ�Ѻ�ľ���ӡ�\n",
        ]));

        set("objects",([
                __DIR__"npc/wenhui" : 1,
                CLASS_D("emei") + "/jinghe" : 1,
        ]));

        set("no_fight", 0);
        set("no_clean_up", 0);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

void init()
{
        add_action("do_sit", "sit");
}

int do_sit(string arg)
{

        object me;
        object wenhui;

        me = this_player();
        if ( !arg || (arg != "chair") )
                return notify_fail("��ϯ�ض���������������㵵�Ŀ�⡣\n");

	if( !objectp(wenhui = present("wenhui", environment(me))) )
                return notify_fail("����������Ϣ��û����������㡣\n");

	if( me->query_temp("marks/served") )
	{
		message_vision("����Сʦ̫Ц�Ŷ�$N˵���һ�æ���ţ���������Ϣ��Ϣ�ɡ�\n", me);
		return notify_fail("");
	}

	message_vision("$N������ǰ������СʦЦ�Ź����д���\n", me);
	wenhui->serve_tea(me) ;
	
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
        if (  (dir == "west")
           && ( present("xiang cha", this_player())
                || present("dian xin", this_player()) ) 
           && objectp(present("wenhui", environment(me))) ) {
	message_vision("����Сʦ̫��$N��û���꣬˵������λ�������������߰ɡ�", me);
        return notify_fail("\n");
	}

        return ::valid_leave(me, dir);
}

