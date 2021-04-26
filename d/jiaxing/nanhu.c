// Code of ShenZhou
// Room: /d/quanzhou/nanhu.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "�����Ϻ�");
	set("long", @LONG
�����Ǽ����Ϻ����ڽ������Ҷ���У����ⱥʵ��һ������
��ת�ĸ�����Ʈ����ˮ���ɵĺ����ϡ�����һ��������һ��������
�����Ѿá������м���ũ���ڴ�ˮ��
LONG
	);

	set("exits", ([
                "west" : __DIR__"jiaxing",
		"south" : __DIR__"tieqiang",
                "southeast" : __DIR__ "nanhu1",
	]));

        set("resource/water", 1);


	set("outdoors", "quanzhou");
        set("objects", ([
            "/kungfu/class/gumu/limochou" : 1,
            "/kungfu/class/gumu/hong" : 1]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

