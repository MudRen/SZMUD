// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ���������·ͨ����
��ǵ����š�
LONG
	);

	set("exits", ([
		"north" : __DIR__"tulu2.c",
		"south" : __DIR__"tulu4.c",
	]));

	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
