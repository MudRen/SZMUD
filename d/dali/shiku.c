// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "剑川石窟");
	set("long", @LONG
    石宝山中，奇石千姿万态，各呈其妙，而山中有南诏的艺术瑰宝：十七个雕
刻精细，形象生动，内容独特，地方民族色彩浓郁的石窟。这些石窟分布在石宝
山的石钟寺，狮子关，沙登箐三处，绵延十二三里的地带，约造像一百四十躯。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
