//Cracked by sleep
// /d/wuguan/zhbshi.c 装备室
// sdong

inherit ROOM;

void create()
{
        set("short", "装备室");
        set("long", @LONG
这里是武馆的装备室，墙上各处挂了各种各样的武器。
LONG
		  );

       set("exits", ([
               "south" : __DIR__"zoulang2",
		  ]));

        set("objects", ([
                "/clone/weapon/zhujian" : 2,
                "/clone/weapon/mudao" : 2,
                "/clone/weapon/fuchen" : 2,
                "/clone/weapon/feibiao" : 1,
                "/clone/weapon/tiezhang" : 1,
                "/clone/weapon/tiegun" : 1,
                "/clone/weapon/tiebang" : 1,
                "/clone/weapon/stone" : 1,
        ]));

        set("cost", 0);
       set("no_fight", 1);
       set("no_steal", 1);
       set("no_hit", 1);
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

