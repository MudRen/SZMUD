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

	set("outdoors","beijing");
	set("exits", ([
		"north" : __DIR__"gzxd3",
		"south" : __DIR__"wenyuange",
	]));

	setup();
	replace_program(ROOM);
}