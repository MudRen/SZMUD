//  forest1.c
//Jiuer 10-28-2001


inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
溪水西边另有一番景致，这里生长着笔直而粗壮的杉树，一排排密密
地矗立在终南山的西坡。这里没有蔟蔟的花林，但绿绒般的青草地上却盛
开着各色无名的山花，微风吹过，杉林发出阵阵的枝啸，山花随风左右摇
摆。你走进林中不禁心里一紧，不知该往哪儿走。
LONG
        );

       // set("objects", ([
         //       "/d/wudang/npc/huoji" : 1,
        //]));

        set("exits", ([
                "east" : __DIR__"milin18",
				"north" : __DIR__"river",
				"south" : __DIR__"forest1",
        ]));
  
    set("outdoors", "gumu");

	set("cost", 1);
    setup();
	replace_program(ROOM);
}
