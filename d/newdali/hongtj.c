// Code of ShenZhou
// Room: /d/dali/hongtj.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʥ��������ϵ��ʯ�����ɣ���ǧѰ����Ϊש����ͬ���������������ţ���
�����ʵǶ��ϡ�
LONG);
	set("exits", ([
		"up" : __DIR__"hongts1.c",
		"out" : __DIR__"hongshengt.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	int current_jingli, current_dodge;

	current_jingli = me->query("jingli");
	if (dir == "up" && current_jingli >40)
	{
		me->set("jingli",current_jingli-random(30));
		me->improve_skill("dodge", random(10));
		write("������һ��¥����Щ���ˡ�\n");
	}
	else if (dir == "up" && current_jingli <= 40)
	{
		write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
		me->unconcious();
		return notify_fail("");
	}
	return ::valid_leave(me, dir);
}
