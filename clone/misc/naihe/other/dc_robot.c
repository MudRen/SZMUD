// ��������ʾ��������ҹһ����˵ġ�  ��dc_robot.c
// by naihe  2002-04-16  ��ï��
// �������Ը��ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��������ʾ��"NOR);
	set("long", "�����ǿ��������Ļ�������ʾ����ƽʱ������Щ�µ���Ϸ��������֮ǰ��
��������һ����ʾ���м��������ڴ������ܵĳ�������������Ϣ����û���̼�չ
ʾ��Ʒ��ʱ�������Եþ����ĵģ����˸е�һ�������������\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("objects", ([
	    __DIR__"obj/yizi" : 1,
	    ]));

	set("exits", ([
	    "east" : __DIR__"dc_dating",
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
	add_action("do_study",  "study");
	add_action("do_study",  "du");
	add_action("do_food", "eat");
	add_action("do_food", "chi");
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

int do_food(string arg)
{
	tell_object(this_player(), "�Ժ��뵽��¥������\n");
	return 1;
}

int do_skills(string arg)
{
	tell_object(this_player(), "�µĻ�����̫�����ˣ��㿴�ſ���������������\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "�µĻ�����̫�����ˣ�����Ŷ��Ÿ�����֪���Լ��ڶ�ʲô��\n");
	return 1;
}
