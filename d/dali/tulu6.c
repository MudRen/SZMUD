// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·������ͨ��ٵ���������·ͨ����
��ǵ����š�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"tulu5.c",
		"west" : __DIR__"tulu7.c",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
