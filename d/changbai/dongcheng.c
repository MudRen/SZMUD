// Code of ShenZhou
// Room: dongcheng.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������û����̾͵Ľֵ������ϵ����˲��࣬�����������塣ż���м�
������������ε������߹��������������壬����ľ������洫�����ӵ�
��������������һ�Ż����ݳɵ���������������Ц��������
LONG
	);

	set("exits", ([
		"south" : __DIR__"tuyao",
                "east" : __DIR__"xuedi1",
                "west" : __DIR__"jishi",
                "northeast" : __DIR__"huanglu1",
	]));

        set("outdoors", "changbai");
        set("cost", 1);

	setup();
	replace_program(ROOM);
}

