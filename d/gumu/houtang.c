// July 31,2000
// Code by April
// /gumu/houtang.c
// add exit north,april 01.08.28

inherit ROOM;

void create()
{
		  set("short","後堂");

		  set("long",@LONG
这里是古墓的後堂。堂上笼罩着一种庄严而又宁静的气氛，但不时让
人感到一丝温馨，东西两面石壁上各挂着一幅画(hua1)(hua2)。往南通往
大厅，往北是松鹤泉。
LONG);

		  set("item_desc",(["hua1" : "
    西壁画中是两个姑娘。一个二十五六岁，正在对镜梳装。另一个是十
四五岁的丫鬟，手捧面盆，在旁侍候。画中镜里那年长女郎容貌极美，秀
眉入鬓，眼角之间却隐隐带着一层杀气。\n",
				"hua2" : "
    东壁画中是一个身材甚高的中年道人。只见他腰悬长剑，右手食指指
着东北角，只是背脊向外，面貌却看不见。
				\n",
				  ]));

	set("objects", ([ 
		"/kungfu/class/gumu/npc/longer": 1, 
		"/kungfu/class/gumu/npc/yangguo": 1,
		]) );

		  set("exits",([ 
			  "south" : __DIR__"mudao14",
			  "north" : __DIR__"songhe",
			  ]));

		  set("cost",1);

	  setup();
}

