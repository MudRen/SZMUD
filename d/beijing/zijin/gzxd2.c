//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long",  @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���
С��ͣ����֦��ߴߴ�����и���ͣ��
LONG
	);

	set("exits", ([
		"north" : __DIR__"gzxd1",
		"south" : __DIR__"jingsidian",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}