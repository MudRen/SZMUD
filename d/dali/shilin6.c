// Code of ShenZhou
// Room: /d/newdali/shilin6.c

inherit ROOM;

void create()
{
	set("short", "大叠水瀑布");
	set("long", @LONG
延山间小路越丘陵，过村庄，穿田野，约二，三里后，隐隐听见
水流的轰鸣，续前进，在一片坡地的前端，呈现倒丫字形深箐，那巨
大的轰鸣声，就是从这箐沟里传出的.沿坡上的之字形小路攀藤扶石
蜿蜒而下，约五百丈，至箐底，一片雄奇壮观的瀑布，便呈现在你的
眼前。
LONG
	);
	set("cost", 2);
	set("outdoors", "dali");
	set("exits", ([
		"southdown" : __DIR__"qingtan.c",
		"northwest" : __DIR__"chhill5.c",
		"eastdown" : __DIR__"road7.c",
		]));
	set("no_clean_up", 0);
        set("fjing", 1);

	setup();
}
