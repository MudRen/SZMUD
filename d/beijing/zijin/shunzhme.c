//Cracked by Roath
// This is a room made by roommaker.

inherit ROOM;

void create()
{
    set("short", "˳����");
    set("long",@long
��������԰���������,���峯,ƽʱ�ǹ��ŵ�,�ʵ�,�ʺ�,
���ɳ���ʱ,��ʱ���ա�
long
);
	set("exits", ([
        "north" : __DIR__"shenwume",
        "south" : __DIR__"yuhuayua",
	]));
	setup();
	replace_program(ROOM);
}
