// Code of ShenZhou
// Room: /d/newdali/bingying.c

inherit ROOM;

void create()
{
	set("short", "��Ӫ");
	set("long", @LONG
�������С��ȴ���Ӿ���������Ȼ���˱�����־������������֮
�ߣ����ϴ������뱱���γ��޺ͣ�����������£�����ˣ�������ս�¡�
���ǳ��������Ӫ��Ϊ����ĵ�ϵ��װ�������޲�������ԭ�ط�����
ʿ�������Դ�����������������������
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"north" : __DIR__"dahejie",
		"west" : __DIR__"majiu",	
		]));

	set("objects", ([
		__DIR__"npc/weishi2" : 1,
		__DIR__"npc/dalishibing" : 2,
		]));

	set("no_clean_up", 0);

	setup();
}
