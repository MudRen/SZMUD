//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "Э����");
	set("long",  @LONG
������ƽʱ�������ر��ţ�ֻ�������������̲Ŵ򿪣�����ʿ��
����ʹ�á�
LONG
	);

	set("exits", ([
		"east" : __DIR__"wenhuamen",
        "west" : __DIR__"guang2",
	]));
	set("outdoors","beijing");

	setup();
	replace_program(ROOM);
}
