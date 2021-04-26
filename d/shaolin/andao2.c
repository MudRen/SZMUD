// Code of ShenZhou
// Room: /d/shaolin/andao2.c
// Date: YZC 96/02/06
//modified by kane

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ��������ʪ�ĵص����ı��ôֲڵ�Ƭ���ݶ���ɣ�һ��
��ˮ������ǽ�ڹ����������ڵ��ϡ�Ҳ������Ϊ��ʱ������ͨ�е�
Ե�ʣ������ص�������һ�ɸ�ʬ��Ķ�����Ա�һ��ǽ(wall)�ϵ�
��̦�ƺ��е���䡣
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou1",
	]));

	set("item_desc", ([
	"wall" : "����ǽ����ȥ��̫��ʵ����֪���ܲ�����(tui)�ö���\n",
	]) );

	set("cost", 1);
	setup();
}

void init()
{       
	object ob;

	if( interactive(ob = this_player()) 
	&& (int)ob->query_condition("bonze_jail") >= 0 )
	{
		message("vision",
			HIY "ֻ��ˮ����������һ�죬һ��������ڣ�ȫ���ཬ�ļһ����˹�����\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "����û������ɣ������߳�����������Ի����ӳ������ˣ�\n");

		ob->set("startroom", START_ROOM);
		ob->clear_one_condition("bonze_jail");
	}

        add_action("do_push", "tui");
}

int do_push(string arg)
{
	object me = this_player();

        if( !arg || arg!="wall" ) {
                write("��Ҫ��ʲô��\n");
                return 1;
        }

        message_vision(
        "$N��һ�������˾�˫�ۣ���ʯ������һ�ơ�\n",me);

	write("ʯ��΢΢һ�Σ�ֻ���������������������ѿ�һ���󶴡�\n");
        set("exits/down", __DIR__"mishi");
        remove_call_out("close");
        call_out("close", 5, this_object());

        return 1;
}

void close(object room)
{
	message("vision","ֻ���ã������������죬�����ָֻ���ԭ״��\n", room);
        room->delete("exits/down");
}
