//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long",  @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���С
��ͣ����֦��ߴߴ�����и���ͣ��
LONG
	);

	set("outdoors","beijing");
	set("exits", ([
		"west" : __DIR__"zuoyimen",
		"south" : __DIR__"gzxd4",
                      "north" : __DIR__"jianting",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
