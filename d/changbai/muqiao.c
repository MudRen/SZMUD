// Code of ShenZhou
// Room: muqiao.c
 
inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
����һ�����ʧ�޵���ľ�ţ��ɼ��������������ɡ�����ĺ�ˮ���Խ�
�ɼ�������ﱾ�Ǻ�ͼ�����ǵĻ��Ǻӣ����ѷ��������ˡ��Ӱ��������û�
���ѳɵĳ�ǽ���ܶദ����̮�����ɴ��򱱾��Ǻ�ͼ�������ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"lyddao5",
		"north" : __DIR__"nancheng",
	]));

        set("objects", ([
                __DIR__"npc/yu" : 1,
        ]));

        set("outdoors", "changbai");
        set("cost", 3);

	setup();
	replace_program(ROOM);
}

