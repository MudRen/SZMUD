//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","许愿庵");
	set("long",@LONG
走到这里，就让你忘却了前世、今生的痛苦。庵的前门上方挂着一块大匾，
可能由于年代的久远，有些发黄了。匾上提着[许愿庵]三个清秀大字，据说是
庵主题的。这里曾经是个破庵，是现任庵主把着修复好的，听说这位庵主是个
不同寻常的人物。边上几位善男信女正在烧香拜佛，好象在求菩萨多多保佑。 
LONG
	);
	set("exits",([

		"southeast" : __DIR__"huadian",
		"south" : __DIR__"byxiang",
	]));

	setup();
}
