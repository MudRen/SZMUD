// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
���������᷿�����ܲ���һ����֪��С��Ĺ뷿��ʯ��ʯ�ʣ���
��ɽҰ��Ϣ�������ҹ���Щ�黭��һ����֪������û��ʲô�����ġ�
����ʢ����һЩҰɽ�軨����Զ����ɽʯ������������һ��ɽ���
LONG
	);

	set("exits", ([
		"west" : __DIR__"wjg3.c",
	]));

	set("objects", ([
		__DIR__"npc/zhongling": 1,
		__DIR__"npc/yahuan": 1,
	]));

	set("cost", 1);
	setup();
}
