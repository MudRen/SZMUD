// July 31,2000
// Code by April
// /gumu/gumu.c

inherit ROOM;

void create()
{
	set("short","古墓");

	set("long",@LONG						
在你眼前出现了一座坟墓，墓门上方有几个石刻大字（zi）。据说这
是当年一位武林奇人为抵抗金兵，动用数千人力，历时数年方始建成。墓
门是两块万斤巨石，当年杨过和小龙女曾将它放下，后来又集合众人之力
将它打开。不过看它摇摇欲坠，仍是十分危险。
LONG);

	set("item_desc",(["zi" : "
                       ≡≡≡≡≡≡
                       ≌活死人墓≌
                       ≡≡≡≡≡≡
\n",]));

	set("exits",([
		"enter" : __DIR__"mudao1",
		"south" : __DIR__"milin3",
	]));

	set("objects", ([
//		"/kungfu/class/gumu/npc/huangyi_gate" : 1,
	]));    

	set("cost",1);

	set("outdoors", "gumu");
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;

	fam = (mapping)me->query("family");

	if(( fam && fam["family_name"] != "古墓派" 
		&& me->query("combat_exp") > 10000 ) 
                && dir == "enter"
		&& objectp(present("huangyi girl", environment(me))) ) 
	{
		return notify_fail("黄衣少女道：古墓禁地，外人止步。\n");
	}
	return ::valid_leave(me, dir);
}

