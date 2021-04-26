// Code of ShenZhou
// Room: /d/shaolin/fzlou1.c
// Date: YZC 96/01/19
// Date: cleansword 96/02/24

inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
�����Ƿ��ɴ��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ���
��ǽ�Ϲ���һ��������ǽ��һ�������ż���������и��������
�����ˡ����ݴ�������׭�֣������������ڣ��ƺ��Ǹ�����²衣
�����Ƿ����ҡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"fzlou2",
		"down" : __DIR__"fzlou",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-le" : 1,
	]));

	set("cost", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int skill;

	skill = me->query_skill("buddhism", 1);
	if (!wizardp(me) && skill < 30)
	{
		if (dir == "north" && present("qingle biqiu", environment(me)))
		{
			return notify_fail("���ֱ�����ס��˵�����ʸ񲻹������ܽ��뷽���ҡ�\n");
		}
	}
	return ::valid_leave(me, dir);
}


