// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������᷶��Ķ�����ڡ��������ξ���������Ͽ�ڡ�ӥ��ȣ�
�����ɽ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"tanhai",
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

