// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������Ŀ���������Ǿ�̳����ƿ���ƺ�«���Ʊ���һ�����
�˱Ƕ��������Ű���һ�Ŵ�(bed)��
LONG
        );
        set("exits", ([
		"east" : __DIR__"mzqianting",
	]));

	set("objects", ([
		__DIR__"npc/danqing" : 1,
		"/d/city/obj/hdjiudai" : 1,
		"/d/xingxiu/npc/obj/hu" : 1,
		"/d/city/obj/nuerhong" : 1,
	]));
        set("item_desc", ([
                "bed" : "����ͨͨ��һ�Ŵ���\n",
        ]));

        set("no_clean_up", 0);

	set("cost", 0);
	setup();
        replace_program(ROOM);
}
