// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov19.c

inherit ROOM;

void create()
{
	set("short", "�س�С·");
	set("long", @LONG
����һ�����ŵ���ϰ���С·������а������Ϯ�ˡ�Զ����غ��棬�̲�
����������Ϸˮ��ңң�ɼ��δ����洬�ᷫ���ơ��˵����˼��ɾ�����·����ֱ
�ϵ��������Ⱥɽ��
LONG);
	set("exits", ([
		"westup" : __DIR__"minov7",
		"east" : __DIR__"minov18",
		]));
	set("area", "��٤��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
