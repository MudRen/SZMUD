// Code of ShenZhou
// void.c (re-created after Elon screwed it up on 07-24-95)
#include <login.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������԰");
	set("long",@LONG	
������Ǵ�˵�е� VOID -- �������ʦ��������԰���㿴������һƬ
��ãã�ģ���һ���������ð��һֻ��죬�ݸ���һ�ޡ��ɿڿ��֡�(tm)��
Ȼ��վ��һ�Ժ�а���Ц�����ֹ���һ�ᣬһֻ���������˹�����һ���ı�
����ֻ��첢��������������ƿ���֣���Ц������ʹ�����ǰ��ʧ�ˡ�
��ҡҡͷ�����ֵط����ǲ�Ҫ��̫�õĺá�
LONG
	);

	set("exits", ([
		"down" : "/d/city/zuixianlou",
	]));
	set("no_clean_up", 1);
	set("no_fight",1);
        set("sleep_room",1);
	setup();
//	replace_program(ROOM);
}
void init()
{       
	object me = this_player();
        add_action("do_practice", "get");
        add_action("do_practice", "drop");
	if (me->query("startroom")== "/d/death/blkbot")
		{
		write(HIW "\n�����ֻ֣������©���㻹�ǵ���ʦ����ѣ�\n\n" NOR);
		me->move("/d/death/blkbot");
		me->set("startroom", "/d/death/blkbot");
		return 0;
        }
        if (me->query("startroom")== "/d/taishan/jianyu")
                {
                write(HIW "\n�����ֻ֣������©���㻹�����˼���ɣ�\n\n" NOR);
                me->move("/d/taishan/jianyu");
                me->set("startroom", "/d/taishan/jianyu");
                return 0;
        }
		return 0;
}
int do_practice()
{
        write("�㲻���������԰��������¡�\n");
        return 1;
}
