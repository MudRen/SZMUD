// Code of ShenZhou
// Room: /d/dali/dalicheng14.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�������С��ȴ���Ӿ���������Ȼ���˱�����־������������֮�ߣ����ϴ�
�����뱱���γ��޺ͣ�����������£�����ˣ�������ս�¡����ǳ��������Ӫ��
Ϊ����ĵ�ϵ��װ�������޲�������ԭ�ط�����ʿ�������Դ�����������������
������
LONG);
	set("objects", ([
		__DIR__"npc/weishi2" : 1,
		__DIR__"npc/dalishibing" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng13",
		"west" : __DIR__"dalicheng15",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
