// Code of ShenZhou
// chanfang.c ����

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�䰲���������������Ǹ������е��Ӵ�������֮������������
����ط���������š���λ����ʦ̫���׼�Ů�����������붨��
LONG
	);
	set("exits", ([
		"west" : __DIR__"fushou1",
	]));

	set("jingzuo_room", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo(string arg)
{
	object me = this_player();
	if ( me->query("family/family_name") != "������" || me->is_busy() )
		return 0;
	if(random(9) == 3) {
		tell_object(me, "��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������\nֻ�ø�ȥ���������������С�\n");
		tell_room(environment(me),(string)me->query("name")+"������ȥ�����������������ˡ�\n", me); 
		switch (random(3)) {
			case 0: me->move("/d/emei/hz_chanfang");
				break;
			case 1: me->move("/d/emei/chanfang_wn");
				break;
			case 2: me->move("/d/emei/chanfang_qf");
				break;
		}
		tell_room(environment(me),(string)me->query("name")+"�ӱ������������������������\n", me); 
		return 1;
	}
	return command("jingzuo "+arg);
}
