// Code of ShenZhou
// Room: /city/minwu1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ������һ��Ǯ���ϰ��ռң��������ݲ�ͬ������䷿�ݽ�Ϊ����
����ļҾ�Ҳ���£������һλ���˿���������Ц���е�����ӭ����������һ��
С��·������С����������ˣ�����Ͽ��Կ���һ���ƾɵ�С���
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaomiao",
		"west" : __DIR__"xiaotulu",
	]));

	set("objects", ([
		__DIR__"npc/woman" : 1,
		__DIR__"npc/girl" : 1,
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

