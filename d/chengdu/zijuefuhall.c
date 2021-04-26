// Room: /d/chengdu/zijuefuhall.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ӿ����Ĵ�����װ�ε�ʮ�ֺ������Ƚ���ֵ������ܵ�ǽ�Ϲ��ŵĲ�
�������ֻ���ȴ�����������ף����������Ǻ�ϲ��Χ��ġ�һλ���Ż������
��������̫ʦ���ϣ������Ҷ���һ�����̡�
LONG
	);

	set("objects", ([
		__DIR__"npc/liuhaoyi" : 1,
	]));

	set("exits", ([
		"north" : __DIR__"zijuefumen",
		"west" : __DIR__"zijuefushufang",
	]));

	setup();
}

void init()
{
	object me = this_player();

	if (present("ou xie pu", me)) me->set_temp("ouxiepu_got", 1);
}

int valid_leave(object me, string dir)
{
	object ob;

	if (dir == "west" && !me->query_temp("qipu_guess_win")) {
		if ((ob = present("liu haoyi", this_object())) && living(ob)) {
			return notify_fail("��������ס��˵����������鷿��ͬһ�㣬�ſ�װ�������Ļ��أ���������ȥ���Ƚ�һ����(question)��˵����\n");
		}
		return notify_fail("��̤����Ҫ�����ߣ�һ����ա��Ȼ��ͷ��������������æ�����ˣ�ա�����ڽ�������Ĵ��ֺ��ǰ�����ų���һ���亹��\n");
	}
	return ::valid_leave(me, dir);
}