//                ��׼��������ʾ��                                   |
// Ϊ�˼��ٷ�����������������ͨ��  ��dc_tongdao.c

inherit ROOM;

void create()
{
	set("short", "Сͨ��");
	set("long", "����һ��Сͨ�����������ص��ĳ�������ͨ����ͷ�Ǹ�ϴ�ֵĵط��������
��������Ǽ�������Ϸ�ĵ��䡣\n");
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("invalid_startroom",1);

	set("exits", ([
	    "northwest" : __DIR__"dc_dating",
	    "adj":__DIR__"adj",
	    "bdj":__DIR__"bdj",
	    "cdj":__DIR__"cdj",
	    "north":__DIR__"dc_lav",
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
	tell_object(this_player(), "���ﲻ�������ĵط���\n");
	return 1;
}

int do_study(string arg)
{
	tell_object(this_player(), "���ﲻ�Ƕ���ĵط���\n");
	return 1;
}
