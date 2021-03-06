// Code of ShenZhou
// /d/forest/clforest3.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        int i;
        set("short", "树林");
        set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从
茂密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传
来野兽的啸声使人不觉犹豫了前进的脚步。
LONG
        );

        set("objects", ([
                __DIR__"npc/cl_fan" : 1,
                __DIR__"npc/cl_lu" : 1,
        ]));

        set("exits", ([
                "northwest" :  __DIR__"clforest2",
		"east" : __DIR__"clforest4",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}

