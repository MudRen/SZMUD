// Code of ShenZhou
// Room: /d/xiangyang/beimen.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ǵı��š���һ�ӹٱ�������ϸ���̲����İ��գ�Ҳ�����½��
��ϸ������ڵĹ�ϵ�ɡ����������������߾͵���ˮ�ϰ��ˡ�
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : 6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "northwest" : __DIR__"tulu5",
  "south" : __DIR__"jzjie3",
]));

	setup();
	replace_program(ROOM);
}
