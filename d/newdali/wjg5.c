// Code of ShenZhou
// acep , mantian , mantian

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
���������᷿�����ܲ���һ����֪��С��Ĺ뷿��ʯ��ʯ�ʣ�����ɽҰ��Ϣ��
�����ҹ���Щ�黭��һ����֪������û��ʲô�����ġ�����ʢ����һЩҰɽ�軨��
��Զ����ɽʯ������������һ��ɽ���
LONG);
	set("objects", ([
		__DIR__"npc/zhongling": 1,
		__DIR__"npc/yahuan": 1,
		]));
	set("exits", ([
		"west" : __DIR__"wjg3.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
