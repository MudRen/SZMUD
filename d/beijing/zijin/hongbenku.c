//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "�챾��");
	set("long",  @LONG
���Ǹ���ǰ������Ϣʹ�õġ���ǽ�Ǽ��Ŵ󴲣����������ڹ���
����ֵ��ʱ������������Ϣһ�¡�
LONG
	);

	set("exits", ([
        "north" : __DIR__"wenhuamen",
        "east"  : __DIR__"shiluku",
	]));

	setup();
	replace_program(ROOM);
}
