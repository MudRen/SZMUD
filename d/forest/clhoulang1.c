//Cracked by Yujie
///d/forest/clhoulang1.c
// by yujie 10 / 2001

inherit ROOM;

#define DDR "/kungfu/class/changle/"

void create()
{
        set("short", "后堂走廊");
        set("long", @LONG
这是长乐帮后堂一条幽静的走廊，两边种满了各种奇花异草，真令人
赏心悦目。往东是龙灵堂香主的私房，西边是狮敏堂香主的私房，装饰都
十分的华丽。
LONG );
        set("exits", ([
		"north": __DIR__"clhoulang2",
		"south": __DIR__"clhoutang",
		"east" : DDR+"clsifang1",
		"west" : DDR+"clsifang2",
		
        ]));
	
        set("objects",(["/d/forest/npc/shicong" : 1 ]));
        setup();
       
}

int valid_leave(object me, string dir)
{
        object ob;
	string pos;
	
        if ( dir == "east")
        {	
                if (stringp (pos = me->query("clbpos")) && (pos != "龙灵堂") && (me->query_temp("invite")!= "龙灵堂"))
        		return notify_fail("这间不是你自己的私房。\n");
        		  
                if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "龙灵堂"))
        		return notify_fail("这是龙灵堂香主的私房，没有被邀请不得擅自闯入。\n");
        	
        	return ::valid_leave(me, dir);
	}
	
	if ( dir == "west")
        {	
                if (stringp (pos = me->query("clbpos")) && (pos != "狮敏堂") && (me->query_temp("invite")!= "狮敏堂"))
        		return notify_fail("这间不是你自己的私房。\n");
        		  
                if (!stringp (pos = me->query("clbpos")) && (me->query_temp("invite")!= "狮敏堂"))
        		return notify_fail("这是狮敏堂香主的私房，没有被邀请不得擅自闯入。\n");
        	
        	return ::valid_leave(me, dir);
	}
	
	return ::valid_leave(me, dir);
}
	
	
        


