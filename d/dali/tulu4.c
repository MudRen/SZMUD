// Code of ShenZhou
// Room: /d/dali/tulu4.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ��������·�ϣ����˶��Ǳ��صİ�
�����ˡ�Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ�����
������·ͨ������ǵ����ţ����пɴ�㶫��ɽ��
LONG
	);
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");

	set("exits", ([
		"northwest" : __DIR__"shqiao",
		"southeast" : "/d/foshan/dlroad7.c",
		]));

	setup();
}
