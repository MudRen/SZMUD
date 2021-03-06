// Code of ShenZhou
// liangongfang.c 练功房
// by Xiang
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是练功房，地下凌乱地放着几个蒲团，几位武当弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		"south" : __DIR__"donglang1",
	]));
	set("objects", ([
                "/d/huashan/obj/duanjian" : 1,
                "/d/huashan/obj/changjian" : 1,
                "/d/village/obj/zhujian" : 2]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/剑", 1);
        if ( j > 1 ) return notify_fail("别那么自私！你不能带走超过一把兵器。\n");

        return ::valid_leave(me, dir);
}
