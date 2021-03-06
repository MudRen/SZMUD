// Code of ShenZhou
// /d/gumu/bingqifang.c 兵器房
// Lara

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
这里是古墓派的兵器房，墙上各处挂了许多长剑，短剑，竹剑和拂尘。
LONG
		  );

		  set("exits", ([
		  "east" : __DIR__"mudao16",
		  ]));

        set("objects", ([
                "/clone/weapon/changjian" : 3,
                "/clone/weapon/duanjian" : 1,
                "/clone/weapon/zhujian" : 1,
                "/clone/weapon/fuchen" : 2,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("skill_type")=="sword") j++;
                if ((string)inv[i]->query("skill_type")=="blade") j++;
        }
        
        if ( j == 1 ) me->set_temp("marks/剑", 1);
        if ( j > 1 ) return notify_fail("别那么自私！你不能带走超过一把兵器。\n");

        return ::valid_leave(me, dir);
}

