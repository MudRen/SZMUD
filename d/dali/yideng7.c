// Code of ShenZhou
// yideng quest room 7

inherit ROOM;

void create()
{
	set("short", "ȱ��");
	set("long", @LONG
ɽ·�м�ͻȻ�жϣ�ǰ���ɽ�м��ѿ���������һ��ȱ��(gap)��
ʯ��ֱ��ֱ�£���������������ͣ����������ǵ�����ɵġ�ɽ
·�ڶ����ɽ�ϼ���������ǰ��
LONG
);
	set("exits", ([
		"down":__DIR__"yideng5",
        ]));

	set("objects", ([
		"/kungfu/class/dali/zhu.c" : 1,
		]) );

	set("item_desc",([
		"gap" : "��ȱ�ڿ��������ǲ�����������ȥ�����Ƕ����и��������ţ����������������յ�ʱ����ֹ����������Ǳ������ɡ�\n",
		]));
        
	set("invalid_startroom", 1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_kill", "kill");
	add_action("do_kill", "fight");
	add_action("do_steal", "steal");
	add_action("do_steal", "throw");
}

int do_kill(string arg)
{
	if (arg=="zhu" || arg=="ziliu" || arg=="zhu ziliu") {
		tell_object(this_object(), "�������ȱ�ڣ�����ô����������\n");
		return 1;
	}
	return 0;
}

int do_steal(string arg)
{
	tell_object(this_object(), "ɽ��֮�ϣ��������ڣ���û�а취͵Ϯ��\n");
	return 1;
}

