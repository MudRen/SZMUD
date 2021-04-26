// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "玉虚观");
	set("long", @LONG
玉虚观内十分清检，正中供着张果老、吕洞宾、何香姑等八仙的
塑像，香火缭绕，供桌上摆着些蟠桃。正中放了几个蒲团。旁边一个
小间里摆着桌椅，是玉虚散人休息和授徒的地方。
LONG
	);

	set("exits", ([
		"south" : __DIR__"yuxuguan1.c",
	]));

	set("objects", ([
		"/kungfu/class/dali/daobaifeng.c" : 1,
	]));

	set("cost", 1);
	setup();
}
