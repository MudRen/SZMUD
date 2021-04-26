// Code of ShenZhou
// Room: /d/shaolin/wuchang.c
// Date: YZC 96/01/19
// modified by aln

inherit ROOM;

void reset();

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ�
��������ɳ�ӣ�ʮ����ɮ��������ϰ���ա������������һ����
����
LONG
	);

	set("exits", ([
		"south" : __DIR__"houdian",
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"wuchang1",
		"north" : __DIR__"fzlou",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		CLASS_D("shaolin") + "/dao-jue" : 1,
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

// by aln
// if any problem from 18 zhen happens, players can still have chance to leave
void reset()
{
        ::reset();

        if( !query("exits") && query("store") )
        set("exits", query("store"));
}
