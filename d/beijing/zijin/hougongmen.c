//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "����");
	set("long",  @LONG
����������ȫ���ĺ��ţ��ɴ��򱱾Ϳ����뿪���ٹ���
LONG
	);

	set("exits", ([
        "north" : __DIR__"tongdao7",
        "south" : __DIR__"yihexuan",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
