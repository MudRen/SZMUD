//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
������ƽʱ�������ر��ţ�ֻ�������������̲Ŵ򿪣�����ʿ��
����ʹ�á�
LONG
	);

	set("exits", ([
		"west" : __DIR__"wuyingmen",
        "east" : __DIR__"guang2",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
