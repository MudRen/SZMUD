//                ��׼��������ʾ��                                   |
// �ĳ�����������  ��dc_chazuo.c
// by naihe  2002-04-29  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"����"NOR);
	set("long", "����һ������ķ��䣬��Ȼ������ŷ���һЩ�зָ����������ǽ���϶���
��Ư����ֽ�ţ���¥�ݵĵط��и�С���ӿ��Կ��������ֵľ�ɫ�����¥����
����������¥�µĳ�������ȫ�������ˣ���������Ϣһ�������������¡�¥����
���ŵ�ǰ����ǹ�̨���и�Ư����Ů��Ӧ(waitress)������ӭ�˹�����\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("objects", ([
	    __DIR__"npc/dc_waiter" : 1,
	    ]));

	set("exits", ([
	    "down": __DIR__"dc_dating",
	    ]));

	setup();
}

void init()
{
	add_action("do_skills",  "exercise");
	add_action("do_skills",  "dazuo");
	add_action("do_skills",  "respirate");
	add_action("do_skills",  "tuna");
	add_action("do_skills",  "practice");
	add_action("do_skills",  "lian");
	add_action("do_skills",  "study");
	add_action("do_skills",  "du");
	add_action("do_drop", "drop");
}

int do_skills(string arg)
{
	tell_object(this_player(), "����ð����أ���ѽ :P\n");
	return 1;
}

int do_drop(string arg)
{
	if(arg=="gold") return 0;
	tell_object(this_player(), "������������~~\n");
	return 1;
}
